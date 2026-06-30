#include "test_main.h"

START_TEST(s21_negate_1) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_2) {
  int true_res = 0;
  s21_decimal number1 = {{0x2196602A, 0x03178923, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x2196602A, 0x03178923, 0x00000000, 0x800F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_3) {
  int true_res = 0;
  s21_decimal number1 = {{0x7C103971, 0x5CB51098, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x7C103971, 0x5CB51098, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_4) {
  int true_res = 0;
  s21_decimal number1 = {{0x0477675D, 0x01AB24CC, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x0477675D, 0x01AB24CC, 0x00000000, 0x800F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_5) {
  int true_res = 0;
  s21_decimal number1 = {{0xDBEC3C7B, 0x1464ECBB, 0x00000003, 0x80100000}};
  s21_decimal result = {{0xDBEC3C7B, 0x1464ECBB, 0x00000003, 0x00100000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_6) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal result = {{0x00000001, 0x00000000, 0x00000000, 0x801C0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_7) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_8) {
  int true_res = 0;
  s21_decimal number1 = {{0xF88B5A22, 0x272CF139, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0xF88B5A22, 0x272CF139, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_9) {
  int true_res = 0;
  s21_decimal number1 = {{0x5D989704, 0x2731E70F, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x5D989704, 0x2731E70F, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_10) {
  int true_res = 0;
  s21_decimal number1 = {{0xDE38B005, 0x2174A46E, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0xDE38B005, 0x2174A46E, 0x00000000, 0x800F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_11) {
  int true_res = 0;
  s21_decimal number1 = {{0x2E45C4FE, 0x1CCB0272, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x2E45C4FE, 0x1CCB0272, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_12) {
  int true_res = 0;
  s21_decimal number1 = {{0x2580AADF, 0x50585FA0, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x2580AADF, 0x50585FA0, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_13) {
  int true_res = 0;
  s21_decimal number1 = {{0x4A070176, 0x4499E0C9, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x4A070176, 0x4499E0C9, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_14) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_15) {
  int true_res = 0;
  s21_decimal number1 = {{0x6887E5CF, 0x03C041E3, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x6887E5CF, 0x03C041E3, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_16) {
  int true_res = 0;
  s21_decimal number1 = {{0xF2490891, 0x3FD907B2, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0xF2490891, 0x3FD907B2, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_17) {
  int true_res = 0;
  s21_decimal number1 = {{0x743D8EE9, 0x38F693A9, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x743D8EE9, 0x38F693A9, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_18) {
  int true_res = 0;
  s21_decimal number1 = {{0xFA6DF24F, 0x5A036D0E, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0xFA6DF24F, 0x5A036D0E, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_19) {
  int true_res = 0;
  s21_decimal number1 = {{0x485D4427, 0x2025A74A, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x485D4427, 0x2025A74A, 0x00000000, 0x800F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_20) {
  int true_res = 0;
  s21_decimal number1 = {{0xD8ACC486, 0x826A7EA8, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0xD8ACC486, 0x826A7EA8, 0x00000000, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_21) {
  int true_res = 1;
  s21_decimal number1 = {{0xAE76BAB1, 0xDD9C865E, 0xB2952F05, 0x80110000}};
  s21_decimal *output = NULL;
  int s21_res = s21_negate(number1, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_negate(void) {
  Suite *s = suite_create("\033[45m-=S21_NEGATE=-\033[0m");
  TCase *tc = tcase_create("s21_negate_tc");

  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);
  tcase_add_test(tc, s21_negate_6);
  tcase_add_test(tc, s21_negate_7);
  tcase_add_test(tc, s21_negate_8);
  tcase_add_test(tc, s21_negate_9);
  tcase_add_test(tc, s21_negate_10);
  tcase_add_test(tc, s21_negate_11);
  tcase_add_test(tc, s21_negate_12);
  tcase_add_test(tc, s21_negate_13);
  tcase_add_test(tc, s21_negate_14);
  tcase_add_test(tc, s21_negate_15);
  tcase_add_test(tc, s21_negate_16);
  tcase_add_test(tc, s21_negate_17);
  tcase_add_test(tc, s21_negate_18);
  tcase_add_test(tc, s21_negate_19);
  tcase_add_test(tc, s21_negate_20);
  tcase_add_test(tc, s21_negate_21);

  suite_add_tcase(s, tc);
  return s;
}
