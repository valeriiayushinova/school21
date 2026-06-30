#include "test_main.h"

START_TEST(s21_is_less_1) {
  int true_res = 1;
  s21_decimal number1 = {{0xCFC7BBE5, 0x045A20C5, 0xA14D831D, 0x800E0000}};
  s21_decimal number2 = {{0x91087D8B, 0xF0D7C01C, 0xC78E8064, 0x00150000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_2) {
  int true_res = 0;
  s21_decimal number1 = {{0x23ED4856, 0xC227CDA3, 0x17F23977, 0x80050000}};
  s21_decimal number2 = {{0x23ED4856, 0xC227CDA3, 0x17F23977, 0x80050000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_3) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_4) {
  int true_res = 1;
  s21_decimal number1 = {{0x5C761EDD, 0x0251D35A, 0x963EB880, 0x00120000}};
  s21_decimal number2 = {{0x70B130AF, 0x36485D76, 0xF71A2A1A, 0x00040000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_5) {
  int true_res = 1;
  s21_decimal number1 = {{0x704A8428, 0x606FCB32, 0x2D91683C, 0x80090000}};
  s21_decimal number2 = {{0x6DBA88D2, 0x6A73D7F0, 0x61A060FE, 0x80110000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_6) {
  int true_res = 0;
  s21_decimal number1 = {{0x3CD79DE2, 0x367B0C0C, 0x31E71C68, 0x00020000}};
  s21_decimal number2 = {{0xC93F662C, 0x19EB37E6, 0xACBAC0A3, 0x80050000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_7) {
  int true_res = 0;
  s21_decimal number1 = {{0x5F2F6A89, 0xD310FACA, 0xDA1B17BD, 0x00080000}};
  s21_decimal number2 = {{0x069C7C3C, 0x55F708A2, 0x26C01F37, 0x00080000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_8) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_9) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xC31CB675, 0xDCE3D44B, 0x2FB14699, 0x800B0000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_10) {
  int true_res = 0;
  s21_decimal number1 = {{0x55145039, 0x4F916DDF, 0x659CF94C, 0x00110000}};
  s21_decimal number2 = {{0x008124EB, 0x8FE0D3E1, 0xE19E3A55, 0x80100000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_11) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{0x6C466C46, 0x16CAA89A, 0x032E9848, 0x00080000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_12) {
  int true_res = 0;
  s21_decimal number1 = {{0x270964ED, 0xC1872F4E, 0x282BC691, 0x00180000}};
  s21_decimal number2 = {{0x270964ED, 0xC1872F4E, 0x282BC691, 0x00180000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_13) {
  int true_res = 0;
  s21_decimal number1 = {{0x7BFB8254, 0x46DA5132, 0x6512DBF2, 0x000C0000}};
  s21_decimal number2 = {{0x7BFB8254, 0x46DA5132, 0x6512DBF2, 0x000C0000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_14) {
  int true_res = 1;
  s21_decimal number1 = {{0x95B69803, 0x99CA2356, 0x0E9FEC3F, 0x00060000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_15) {
  int true_res = 1;
  s21_decimal number1 = {{0xBCF522ED, 0x23D4EED1, 0x98FB58FB, 0x80020000}};
  s21_decimal number2 = {{0x91017B06, 0x6735A838, 0xC537E9A1, 0x800C0000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_16) {
  int true_res = 0;
  s21_decimal number1 = {{0x0D59CB50, 0x3ADAEB09, 0xE1F0C764, 0x80150000}};
  s21_decimal number2 = {{0x060124F2, 0x81DC7A04, 0x8CC6870F, 0x80130000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_17) {
  int true_res = 0;
  s21_decimal number1 = {{0x5D26326D, 0x522D49E2, 0x2E1DE351, 0x000E0000}};
  s21_decimal number2 = {{0xDCC69BE5, 0xCF723C2E, 0x9FECB1C9, 0x80100000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_18) {
  int true_res = 0;
  s21_decimal number1 = {{0x470FEAF1, 0x64DAA073, 0x77D8825A, 0x00020000}};
  s21_decimal number2 = {{0x31D8B4B6, 0x83A57D32, 0xA4C9BBBC, 0x80100000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_19) {
  int true_res = 0;
  s21_decimal number1 = {{0x6E61E9FF, 0xC9111A21, 0x6941EADC, 0x801A0000}};
  s21_decimal number2 = {{0x6E61E9FF, 0xC9111A21, 0x6941EADC, 0x801A0000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_is_less_20) {
  int true_res = 0;
  s21_decimal number1 = {{0x34A2FDA9, 0xB2E5DBC4, 0x8BCDC1C5, 0x00140000}};
  s21_decimal number2 = {{0xA18953DE, 0x43CD5BEF, 0x662475E5, 0x001C0000}};
  int s21_res = s21_is_less(number1, number2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_is_less(void) {
  Suite *s = suite_create("\033[45m-=S21_IS_LESS=-\033[0m");
  TCase *tc = tcase_create("s21_is_less_tc");

  tcase_add_test(tc, s21_is_less_1);
  tcase_add_test(tc, s21_is_less_2);
  tcase_add_test(tc, s21_is_less_3);
  tcase_add_test(tc, s21_is_less_4);
  tcase_add_test(tc, s21_is_less_5);
  tcase_add_test(tc, s21_is_less_6);
  tcase_add_test(tc, s21_is_less_7);
  tcase_add_test(tc, s21_is_less_8);
  tcase_add_test(tc, s21_is_less_9);
  tcase_add_test(tc, s21_is_less_10);
  tcase_add_test(tc, s21_is_less_11);
  tcase_add_test(tc, s21_is_less_12);
  tcase_add_test(tc, s21_is_less_13);
  tcase_add_test(tc, s21_is_less_14);
  tcase_add_test(tc, s21_is_less_15);
  tcase_add_test(tc, s21_is_less_16);
  tcase_add_test(tc, s21_is_less_17);
  tcase_add_test(tc, s21_is_less_18);
  tcase_add_test(tc, s21_is_less_19);
  tcase_add_test(tc, s21_is_less_20);

  suite_add_tcase(s, tc);
  return s;
}
