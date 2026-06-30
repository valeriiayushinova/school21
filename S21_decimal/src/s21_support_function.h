#ifndef S21_SUPPORT_FUNCTION_H
#define S21_SUPPORT_FUNCTION_H
#include <math.h>
#include <string.h>

#include "s21_decimal.h"

typedef struct {
  unsigned int bits[12];
} s21_decimal_huge;

#define MAX_DECIMAL 79228162514264337593543950335.L

int s21_getterSign(s21_decimal value);
void s21_setterSign(s21_decimal *value, int sign);
int s21_getterScale(s21_decimal value);
void s21_setterScale(s21_decimal *value, int scale);
void set_bit_big(s21_decimal_huge *num, int bit, int value);
int get_bit_big(s21_decimal_huge num, int bit);
void s21_toDecimalHuge(s21_decimal value, s21_decimal_huge *valueHuge);
int s21_toDecimalBasic(s21_decimal_huge valueHuge, s21_decimal *value);
int s21_bankRound(s21_decimal_huge *valueHuge, int mod, int *newScale);
void s21_copyArr(const unsigned *arr1, unsigned *arr2, int count);
void s21_zeroFillArray(unsigned *arr, int count);
int s21_find_zero(const unsigned *arr, int count);
void s21_addingHuge(s21_decimal_huge value_1, s21_decimal_huge value_2,
                    s21_decimal_huge *result);
void s21_diffBetween(s21_decimal_huge value_1, s21_decimal_huge value_2,
                     s21_decimal_huge *result);
void s21_multiplyHuge(s21_decimal_huge value_1, s21_decimal_huge value_2,
                      s21_decimal_huge *result);
void s21_divideHuge(s21_decimal_huge value_1, s21_decimal_huge value_2,
                    s21_decimal_huge *result);
void s21_average(s21_decimal_huge value_1, s21_decimal_huge value_2,
                 s21_decimal_huge *result);
void s21_multiple10(unsigned *arr, int count);
void s21_divide10(unsigned *arr, int count);

int s21_found_mod10(const unsigned *arr, int count);
int s21_bit_compare_arr(const unsigned *arr_1, const unsigned *arr_2,
                        int count);

#endif