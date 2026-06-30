#include "test_main.h"

START_TEST(s21_is_less_or_equal_1) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{0x2A7C4D3C, 0x81898429, 0x374A8631, 0x00030000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_2) {
  int true_res = 1;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0x5BD75879, 0x9EDC4949, 0x6570BBF7, 0x00130000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_3) {
  int true_res = 1;
  s21_decimal number1 = {{0xC551C40B, 0x72AD57BE, 0x7384FB62, 0x00080000}};
  s21_decimal number2 = {{0xC551C40B, 0x72AD57BE, 0x7384FB62, 0x00080000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_4) {
  int true_res = 1;
  s21_decimal number1 = {{0x6B070184, 0xD1D5303D, 0xBB07EDE9, 0x800A0000}};
  s21_decimal number2 = {{0xA5B4A5FE, 0x13620427, 0x40428492, 0x80100000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_5) {
  int true_res = 0;
  s21_decimal number1 = {{0x0555DC4D, 0x0F332B73, 0x456148DA, 0x00080000}};
  s21_decimal number2 = {{0x6CD859D9, 0xCFC5B15A, 0x2D3F9EEE, 0x00180000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_6) {
  int true_res = 1;
  s21_decimal number1 = {{0xA51CAFEB, 0xD88A3370, 0xBFC8269F, 0x00180000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_7) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{0x9CC1E012, 0x9CB0ADC4, 0x6E1B3C2B, 0x80190000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_8) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_9) {
  int true_res = 0;
  s21_decimal number1 = {{0x02393C67, 0xD628F7EE, 0x89CA705F, 0x80090000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_10) {
  int true_res = 1;
  s21_decimal number1 = {{0x329A1AD6, 0xDCD3FE18, 0xCE6C3D2A, 0x80060000}};
  s21_decimal number2 = {{0x329A1AD6, 0xDCD3FE18, 0xCE6C3D2A, 0x80060000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_11) {
  int true_res = 0;
  s21_decimal number1 = {{0x07FEC1FB, 0xF326E5CC, 0xD0F60DBD, 0x80040000}};
  s21_decimal number2 = {{0x2F8A8868, 0x9C6B896E, 0x72412201, 0x80010000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_12) {
  int true_res = 1;
  s21_decimal number1 = {{0xF8668DA9, 0xF4E2F006, 0x75E567B0, 0x00160000}};
  s21_decimal number2 = {{0x0A0CB11B, 0x151B8629, 0xABB1FA0B, 0x00140000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_13) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xF73EE9F9, 0xB403487E, 0xE2CDCE37, 0x80060000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_14) {
  int true_res = 1;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0x55D4F0BB, 0x2BADE160, 0x4FEFCFBA, 0x00100000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_15) {
  int true_res = 0;
  s21_decimal number1 = {{0x53974EA4, 0x8137E34A, 0xF323FD37, 0x00100000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_16) {
  int true_res = 0;
  s21_decimal number1 = {{0xAECCB7B8, 0x1CD984E2, 0x041314B7, 0x00160000}};
  s21_decimal number2 = {{0x2091953B, 0x4BDDE9E1, 0x9373FE20, 0x800E0000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_17) {
  int true_res = 1;
  s21_decimal number1 = {{0xC341B086, 0xC7E86EF6, 0xEFBDE1C2, 0x80190000}};
  s21_decimal number2 = {{0xC341B086, 0xC7E86EF6, 0xEFBDE1C2, 0x80190000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_18) {
  int true_res = 1;
  s21_decimal number1 = {{0xFD7DA814, 0x331F68AF, 0xD59E9BCC, 0x000F0000}};
  s21_decimal number2 = {{0xFD7DA814, 0x331F68AF, 0xD59E9BCC, 0x000F0000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_19) {
  int true_res = 0;
  s21_decimal number1 = {{0xB9934E73, 0x5140058C, 0xB000D66F, 0x00030000}};
  s21_decimal number2 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_or_equal_20) {
  int true_res = 0;
  s21_decimal number1 = {{0x7FEBADDE, 0xB7214C34, 0x4FAC1F85, 0x00060000}};
  s21_decimal number2 = {{0x239B065B, 0x6FAA79EA, 0xB7ECC033, 0x80060000}};
  int s21_res = s21_is_less_or_equal(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_is_less_or_equal(void) {
  Suite *s = suite_create("\033[45m-=S21_IS_LESS_OR_EQUAL=-\033[0m");
  TCase *tc = tcase_create("s21_is_less_or_equal_tc");
  tcase_add_test(tc, s21_is_less_or_equal_1);
  tcase_add_test(tc, s21_is_less_or_equal_2);
  tcase_add_test(tc, s21_is_less_or_equal_3);
  tcase_add_test(tc, s21_is_less_or_equal_4);
  tcase_add_test(tc, s21_is_less_or_equal_5);
  tcase_add_test(tc, s21_is_less_or_equal_6);
  tcase_add_test(tc, s21_is_less_or_equal_7);
  tcase_add_test(tc, s21_is_less_or_equal_8);
  tcase_add_test(tc, s21_is_less_or_equal_9);
  tcase_add_test(tc, s21_is_less_or_equal_10);
  tcase_add_test(tc, s21_is_less_or_equal_11);
  tcase_add_test(tc, s21_is_less_or_equal_12);
  tcase_add_test(tc, s21_is_less_or_equal_13);
  tcase_add_test(tc, s21_is_less_or_equal_14);
  tcase_add_test(tc, s21_is_less_or_equal_15);
  tcase_add_test(tc, s21_is_less_or_equal_16);
  tcase_add_test(tc, s21_is_less_or_equal_17);
  tcase_add_test(tc, s21_is_less_or_equal_18);
  tcase_add_test(tc, s21_is_less_or_equal_19);
  tcase_add_test(tc, s21_is_less_or_equal_20);

  suite_add_tcase(s, tc);
  return s;
}
