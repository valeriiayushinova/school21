#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int ret = (s21_find_zero((unsigned *)value_1.bits, 3) &&
             s21_find_zero((unsigned *)value_2.bits, 3));
  if (!ret) {
    s21_decimal_huge arr1, arr2;
    s21_toDecimalHuge(value_1, &arr1);
    s21_toDecimalHuge(value_2, &arr2);
    ret = (s21_getterSign(value_1) == s21_getterSign(value_2)) &&
          (s21_bit_compare_arr(arr1.bits, arr2.bits, 12) == 0);
  }
  return ret;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int ret = 0;
  if (!(s21_find_zero((unsigned *)value_1.bits, 3) &&
        s21_find_zero((unsigned *)value_2.bits, 3))) {
    int sign1 = s21_getterSign(value_1) ? -1 : 1;
    int sign2 = s21_getterSign(value_2) ? -1 : 1;
    if (sign1 != sign2) {
      ret = sign1 < sign2;
    } else {
      s21_decimal_huge arr1, arr2;
      s21_toDecimalHuge(value_1, &arr1);
      s21_toDecimalHuge(value_2, &arr2);
      ret = s21_bit_compare_arr(arr1.bits, arr2.bits, 12) + sign1 == 0;
    }
  }
  return ret;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_equal(value_1, value_2) || s21_is_less(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_2, value_1);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_equal(value_1, value_2) || s21_is_greater(value_1, value_2);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}
