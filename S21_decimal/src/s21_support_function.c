
#include "s21_decimal.h"

void s21_setterScale(s21_decimal *value, int scale) {
  if (value) {
    int mask = 0x7FFFFFFF;
    value->bits[3] = (value->bits[3] & ~mask) | ((scale & mask) << 16);
  }
}

int s21_getterScale(s21_decimal value) {
  int scale;
  int mask = 0xFF;
  scale = (value.bits[3] >> 16) & mask;
  return scale;
}

int s21_getterSign(s21_decimal value) {
  return (value.bits[3] & (1 << 31)) != 0;
}

void s21_setterSign(s21_decimal *value, int sign) {
  if (value) {
    if (sign == 0) {
      value->bits[3] &= ~(1 << 31);
    } else {
      value->bits[3] |= (1 << 31);
    }
  }
}

int get_bit_big(s21_decimal_huge num, int bit) {
  unsigned int mask = (1u << (bit % 32));
  int bit1 = 0;
  if ((num.bits[bit / 32] & mask) != 0) bit1 = 1;
  return bit1;
}

void set_bit_big(s21_decimal_huge *num, int bit, int value) {
  if (value) {
    num->bits[bit / 32] |= (1u << (bit % 32));
  } else {
    num->bits[bit / 32] &= ~(1u << (bit % 32));
  }
}

void s21_addingHuge(s21_decimal_huge value_1, s21_decimal_huge value_2,
                    s21_decimal_huge *result) {
  if (result) {
    s21_zeroFillArray(result->bits, 12);
    unsigned memo = 0;
    for (int i = 0; i < (int)(sizeof(s21_decimal_huge) / sizeof(unsigned)) * 32;
         i++) {
      unsigned result_bit =
          get_bit_big(value_1, i) + get_bit_big(value_2, i) + memo;
      memo = result_bit / 2;
      result_bit &= 1;
      set_bit_big(result, i, result_bit);
    }
  }
}

void s21_diffBetween(s21_decimal_huge value_1, s21_decimal_huge value_2,
                     s21_decimal_huge *result) {
  if (result) {
    unsigned memo = 0;
    for (int i = 0; i < (int)(sizeof(s21_decimal_huge) / sizeof(unsigned)) * 32;
         i++) {
      unsigned bit1 = get_bit_big(value_1, i);
      unsigned bit2 = get_bit_big(value_2, i);

      int result_bit = (int)bit1 - (int)bit2 - (int)memo;

      if (result_bit < 0) {
        memo = 1;
        result_bit += 2;
      } else {
        memo = 0;
      }
      set_bit_big(result, i, result_bit);
    }
  }
}

void s21_zeroFillArray(unsigned *arr, int count) {
  for (int i = 0; i < count; i++) {
    arr[i] = 0;
  }
}

void s21_multiplyHuge(s21_decimal_huge value_1, s21_decimal_huge value_2,
                      s21_decimal_huge *result) {
  s21_zeroFillArray(result->bits, 12);
  for (int i = 0; i < 6; ++i) {
    for (int k = 0; k < 6; ++k) {
      unsigned long long int m =
          (unsigned long long)value_1.bits[k] * value_2.bits[i] +
          result->bits[i + k];
      result->bits[i + k] = m & 0xFFFFFFFF;
      unsigned overflow = m >> 32;
      for (int p = i + k + 1; p < 12; p++) {
        unsigned long long int tmp = overflow;
        tmp += result->bits[p];
        result->bits[p] = tmp & 0xFFFFFFFF;
        overflow = tmp >> 32;
      }
    }
  }
  for (int d = 0; d < 28; ++d) {
    s21_divide10(result->bits, 12);
  }
}

void s21_divideHuge(s21_decimal_huge value_1, s21_decimal_huge value_2,
                    s21_decimal_huge *result) {
  s21_decimal min_v = {{0, 0, 0, 0}},
              max_v = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal_huge left, left_p, right, right_p, average_r, temper;

  s21_toDecimalHuge(min_v, &left);
  s21_toDecimalHuge(max_v, &right);

  s21_zeroFillArray(left_p.bits, 12);
  s21_zeroFillArray(right_p.bits, 12);

  while (s21_bit_compare_arr(left_p.bits, left.bits, 12) ||
         s21_bit_compare_arr(right_p.bits, right.bits, 12)) {
    s21_copyArr(left.bits, left_p.bits, 12);
    s21_copyArr(right.bits, right_p.bits, 12);
    s21_average(left, right, &average_r);
    s21_multiplyHuge(average_r, value_2, &temper);
    if (s21_bit_compare_arr(temper.bits, value_1.bits, 12) == -1) {
      s21_copyArr(average_r.bits, left.bits, 12);
    } else {
      s21_copyArr(average_r.bits, right.bits, 12);
    }
  }

  s21_multiplyHuge(average_r, value_2, &temper);
  if (s21_bit_compare_arr(temper.bits, value_1.bits, 12))
    s21_copyArr(right.bits, result->bits, 12);
  else
    s21_copyArr(left.bits, result->bits, 12);
}

void s21_average(s21_decimal_huge value_1, s21_decimal_huge value_2,
                 s21_decimal_huge *result) {
  s21_addingHuge(value_1, value_2, result);
  unsigned md = 0;
  for (int i = 11; i >= 0; --i) {
    unsigned tmp_v = md;
    md = result->bits[i] & 1;
    result->bits[i] = (result->bits[i] >> 1) | (tmp_v << 31);
  }
}

void s21_multiple10(unsigned *arr, int count) {
  unsigned long long int overflow = 0;
  for (int k = 0; k < count; ++k) {
    unsigned long long int tmp_v = arr[k];
    tmp_v = tmp_v * 10;
    tmp_v = tmp_v + overflow;
    arr[k] = tmp_v & 0xFFFFFFFF;
    overflow = tmp_v >> 32;
  }
}

void s21_divide10(unsigned *arr, int count) {
  unsigned long long int md = 0;
  for (int i = count - 1; i >= 0; i--) {
    unsigned long long int tmp_v = md << 32;
    tmp_v = tmp_v + arr[i];
    arr[i] = tmp_v / 10;
    md = tmp_v % 10;
  }
}

int s21_found_mod10(const unsigned *arr, int count) {
  unsigned arrayTemp[12];
  s21_copyArr(arr, arrayTemp, 12);
  unsigned long long int md = 0;
  for (int i = count - 1; i >= 0; i--) {
    unsigned long long int tmp_v = md << 32;
    tmp_v = tmp_v + arrayTemp[i];
    arrayTemp[i] = tmp_v;
    md = tmp_v % 10;
  }
  return md;
}

int s21_bit_compare_arr(const unsigned *arr_1, const unsigned *arr_2,
                        int count) {
  int ret = 0;
  for (int i = count - 1; i >= 0 && !ret; i--) {
    if (arr_1[i] != arr_2[i]) {
      ret = arr_1[i] > arr_2[i] ? 1 : -1;
    }
  }
  return ret;
}

int s21_find_zero(const unsigned *arr, int count) {
  int ret = 1;
  for (int i = 0; i < count && ret; i++) {
    ret = arr[i] == 0;
  }
  return ret;
}

void s21_copyArr(const unsigned *arr1, unsigned *arr2, int count) {
  for (int i = 0; i < count; ++i) {
    arr2[i] = arr1[i];
  }
}

void s21_toDecimalHuge(s21_decimal value, s21_decimal_huge *valueHuge) {
  int degree = 28 - s21_getterScale(value);
  s21_zeroFillArray(valueHuge->bits, 12);
  s21_copyArr((unsigned *)value.bits, valueHuge->bits, 3);

  for (int i = 0; i < degree; ++i) {
    s21_multiple10(valueHuge->bits, 12);
  }
}

int s21_toDecimalBasic(s21_decimal_huge valueHuge, s21_decimal *value) {
  int newScale = 28, mod = 0, ret = 0;
  while (!s21_found_mod10(valueHuge.bits, 12) && newScale > 0) {
    s21_divide10(valueHuge.bits, 12);
    newScale--;
  }
  while (!s21_find_zero(valueHuge.bits + 3, 9) && newScale > 0) {
    mod = s21_found_mod10(valueHuge.bits, 12);
    s21_divide10(valueHuge.bits, 12);
    newScale--;
  }

  ret = s21_bankRound(&valueHuge, mod, &newScale);
  if (value) {
    if (!ret) {
      s21_copyArr(valueHuge.bits, (unsigned *)value->bits, 3);
      s21_setterScale(value, newScale);
    } else {
      s21_zeroFillArray((unsigned *)value, 4);
    }
  }
  return ret;
}

int s21_bankRound(s21_decimal_huge *valueHuge, int mod, int *newScale) {
  int ret = !s21_find_zero(valueHuge->bits + 3, 9);
  if (!ret && (mod > 5 || (mod == 5 && (valueHuge->bits[0] & 1)))) {
    unsigned max_mantisa[] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
    if (!s21_bit_compare_arr(valueHuge->bits, max_mantisa, 3)) {
      if (*newScale > 0) {
        mod = s21_found_mod10(valueHuge->bits, 12);
        s21_divide10(valueHuge->bits, 12);
        (*newScale)--;
      } else {
        ret = 1;
      }
    }
    s21_decimal_huge one;
    s21_zeroFillArray(one.bits, 12);
    one.bits[0] = 1;
    s21_addingHuge(*valueHuge, one, valueHuge);
  }
  return ret;
}
