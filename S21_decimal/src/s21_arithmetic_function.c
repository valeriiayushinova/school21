#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int answer = 0;
  if (s21_getterSign(value_1) == s21_getterSign(value_2)) {
    s21_decimal_huge arr_one, arr_two, dop;
    s21_toDecimalHuge(value_1, &arr_one);
    s21_toDecimalHuge(value_2, &arr_two);
    s21_addingHuge(arr_one, arr_two, &dop);
    answer = s21_toDecimalBasic(dop, result);
    s21_setterSign(result, s21_getterSign(value_1));
    if (answer) answer += s21_getterSign(value_1);
  } else {
    if (s21_getterSign(value_2)) {
      s21_negate(value_2, &value_2);
      answer = s21_sub(value_1, value_2, result);
    } else {
      s21_negate(value_1, &value_1);
      answer = s21_sub(value_2, value_1, result);
    }
  }
  return answer;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int answer = 0;
  if (s21_getterSign(value_1) == s21_getterSign(value_2)) {
    s21_decimal_huge arr_one, arr_two, dop;
    s21_toDecimalHuge(value_1, &arr_one);
    s21_toDecimalHuge(value_2, &arr_two);
    int sign = s21_getterSign(value_1);
    s21_setterSign(&value_1, 0);
    s21_setterSign(&value_2, 0);

    if (s21_is_greater(value_1, value_2)) {
      s21_diffBetween(arr_one, arr_two, &dop);
    } else {
      s21_diffBetween(arr_two, arr_one, &dop);
      sign = !sign;
    }
    answer = s21_toDecimalBasic(dop, result);
    if (answer)
      answer = answer + s21_getterSign(value_1);
    else
      s21_setterSign(result, sign);
  } else {
    s21_negate(value_2, &value_2);
    answer = s21_add(value_1, value_2, result);
  }
  return answer;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int answer = 0;
  s21_decimal_huge arr_one, arr_two, dop;
  s21_toDecimalHuge(value_1, &arr_one);
  s21_toDecimalHuge(value_2, &arr_two);
  s21_multiplyHuge(arr_one, arr_two, &dop);
  answer = s21_toDecimalBasic(dop, result);
  if (answer)
    answer += s21_getterSign(value_1) != s21_getterSign(value_2);
  else
    s21_setterSign(result, s21_getterSign(value_1) != s21_getterSign(value_2));

  return answer;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int answer = s21_find_zero((unsigned *)value_2.bits, 3) ? 3 : 0;
  if (!answer) {
    s21_decimal max_num = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal_huge arr_one, arr_two, arr_max, arr_res;

    s21_toDecimalHuge(value_1, &arr_one);
    s21_toDecimalHuge(value_2, &arr_two);
    s21_toDecimalHuge(max_num, &arr_max);
    s21_multiplyHuge(arr_two, arr_max, &arr_res);
    if (s21_bit_compare_arr(arr_res.bits, arr_one.bits, 12) == -1) {
      answer = 1 + (s21_getterSign(value_1) != s21_getterSign(value_2));
    } else {
      s21_divideHuge(arr_one, arr_two, &arr_res);
      s21_toDecimalBasic(arr_res, result);
      s21_setterSign(result,
                     s21_getterSign(value_1) != s21_getterSign(value_2));
    }
  }
  return answer;
}
