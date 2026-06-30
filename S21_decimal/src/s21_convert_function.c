#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int ret = 0;
  if (dst) {
    s21_zeroFillArray((unsigned *)dst->bits, 4);
    s21_setterSign(dst, src < 0);
    if (src > 0 || src == (int)0x80000000)
      dst->bits[0] = src;
    else
      dst->bits[0] = -src;
  } else
    ret = 1;
  return ret;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int ret = 0;
  s21_truncate(src, &src);
  if (s21_find_zero((unsigned *)src.bits + 1, 2) &&
      ((unsigned)src.bits[0] < 0x80000000 ||
       ((unsigned)src.bits[0] == 0x80000000 && s21_getterSign(src)))) {
    if (dst) {
      *dst = src.bits[0];
      if (s21_getterSign(src)) *dst *= -1;
    }
  } else {
    if (dst) *dst = 0;
    ret = 1;
  }
  return ret;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int ret = 0;
  if (dst && fabs(src) >= 1e-28 && fabs(src) <= MAX_DECIMAL) {
    char str[100], *tmp;
    s21_decimal_huge cipher, res;
    s21_zeroFillArray(cipher.bits, 12);
    s21_zeroFillArray(res.bits, 12);
    sprintf(str, "% .28f", src);
    tmp = str + 1;
    while (*tmp) {
      if (*tmp != '.') {
        cipher.bits[0] = *tmp - '0';
        s21_multiple10(res.bits, 12);
        s21_addingHuge(res, cipher, &res);
      }
      tmp++;
    }
    s21_toDecimalBasic(res, dst);
    s21_setterSign(dst, src < 0);
  } else {
    if (dst) s21_zeroFillArray((unsigned *)dst->bits, 4);
    ret = 1;
  }
  return ret;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int ret = 0;
  if (dst) {
    char str[100];
    *str = '\0';
    int len = 0;
    while (!s21_find_zero((unsigned *)src.bits, 3) ||
           len <= s21_getterScale(src)) {
      if (len == s21_getterScale(src)) {
        strcat(str, ".");
      }
      char cipher[2] = ".";
      sprintf(cipher, "%d", s21_found_mod10((unsigned *)src.bits, 3));
      strcat(str, cipher);
      s21_divide10((unsigned *)src.bits, 3);
      len++;
    }
    if (s21_getterSign(src)) {
      char cipher[2] = "-";
      strcat(str, cipher);
      len++;
    }
    for (int i = 0; i < len / 2; ++i) {
      char c = str[i];
      str[i] = str[len - i];
      str[len - i] = c;
    }
    sscanf(str, "%f", dst);
  } else {
    ret = 1;
  }
  return ret;
}
