#include "test_main.h"

START_TEST(s21_div_1) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{1, 0, 0, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_2) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal number2 = {{0xAF44FE20, 0x00223705, 0x0BC4451D, 0x00060000}};
  s21_decimal number3 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_3) {
  int true_res = 3;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_4) {
  int true_res = 0;
  s21_decimal number1 = {{0x57226211, 0xD647F58F, 0xB0FF890F, 0x00020000}};
  s21_decimal number2 = {{0xABC947B5, 0x2BE60B34, 0xFB68067E, 0x000F0000}};
  s21_decimal number3 = {{0xB6C3DF8B, 0x752ECC09, 0xE37C2F6D, 0x00100000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_5) {
  int true_res = 0;
  s21_decimal number1 = {{0x854A2E16, 0xA6B7E550, 0x37BF9D52, 0x00070000}};
  s21_decimal number2 = {{0x668F8B05, 0x559FBBE4, 0x7954D676, 0x000B0000}};
  s21_decimal number3 = {{0x842D82CE, 0x2E0EDB22, 0x9476B609, 0x00190000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_6) {
  int true_res = 0;
  s21_decimal number1 = {{0xE040FA55, 0x386B8A7E, 0x969CFE95, 0x00100000}};
  s21_decimal number2 = {{0x3BF8AE0F, 0x3EDEC9F4, 0x37596530, 0x00140000}};
  s21_decimal number3 = {{0x4818010F, 0xB8747C22, 0x57ECCAF8, 0x00180000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_7) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal number2 = {{0x3473FA5C, 0xBCE1D699, 0xFA76A341, 0x80160000}};
  s21_decimal number3 = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_8) {
  int true_res = 0;
  s21_decimal number1 = {{0xD79E6FF5, 0x41143A2A, 0x2DC46EEF, 0x80020000}};
  s21_decimal number2 = {{0x4CD613A7, 0x403C319D, 0x3910EDD4, 0x00100000}};
  s21_decimal number3 = {{0xA9A8D58C, 0xB68C53DD, 0x19EA0788, 0x800E0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_9) {
  int true_res = 0;
  s21_decimal number1 = {{0x0A957738, 0x1CEA3F77, 0x43D0C8C5, 0x80010000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number3 = {{0xF7C142FF, 0x281CCA6D, 0x00DB1FB8, 0x001C0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_10) {
  int true_res = 0;
  s21_decimal number1 = {{0xE54D2721, 0xCC4F84AD, 0x5AEC559D, 0x000C0000}};
  s21_decimal number2 = {{0xBD76BBA3, 0xFDFB89D5, 0xA5BE4FD8, 0x00060000}};
  s21_decimal number3 = {{0x373F972D, 0x627CA2CA, 0x00000129, 0x001C0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_11) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{1, 0, 0, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_12) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal number2 = {{0xB6112139, 0xA0C7436F, 0xDECED9D7, 0x00180000}};
  s21_decimal number3 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_13) {
  int true_res = 2;
  s21_decimal number1 = {{52133000, 0, 785, 0x80000000}};
  s21_decimal number2 = {{0x0, 0x0, 1, 0x001B0000}};
  s21_decimal output;
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_14) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number3 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_15) {
  int true_res = 3;
  s21_decimal number1 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal number2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_16) {
  int true_res = 0;
  s21_decimal number1 = {{0xFA111F0D, 0xEC4B8CE5, 0xBB750E08, 0x00040000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number3 = {{0x7C4B040B, 0x8FC37A06, 0x00000F81, 0x801B0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_17) {
  int true_res = 0;
  s21_decimal number1 = {{0xD9AB9F10, 0x7A488D6E, 0xB6BC4969, 0x00150000}};
  s21_decimal number2 = {{0x85EA2597, 0xE883DCB2, 0xD2A192CF, 0x80030000}};
  s21_decimal number3 = {{0x051B6525, 0x00000002, 0x00000000, 0x801C0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_18) {
  int true_res = 1;
  s21_decimal number1 = {{52133000, 0, 785, 0x00000000}};
  s21_decimal number2 = {{0x0, 0x0, 1, 0x001B0000}};
  s21_decimal output;
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_19) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0x22AF2435, 0xA4EE5B43, 0x83337718, 0x80060000}};
  s21_decimal number3 = {{0x48FF280C, 0x95E3D4B0, 0x3F0BFB68, 0x00160000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_20) {
  int true_res = 0;
  s21_decimal number1 = {{0xF08EC9FB, 0xA1700518, 0x83C97A1D, 0x80110000}};
  s21_decimal number2 = {{0xA8D44FFB, 0xD8A97214, 0x09411146, 0x800D0000}};
  s21_decimal number3 = {{0x83A3686B, 0xB46EF9F2, 0x000BC79C, 0x001C0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_div(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_21) {
  int true_res = 3;
  s21_decimal number1 = {{0x78D7B7B9, 0xF404012B, 0xD96CD9B4, 0x80060000}};
  s21_decimal number2 = {{0, 0, 0, 0x80000000}};
  s21_decimal output;
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_div_22) {
  int true_res = 3;
  s21_decimal number1 = {{0x77D7B7B9, 0xF404012B, 0xD96CD8B4, 0x80020000}};
  s21_decimal number2 = {{0, 0, 0, 0}};
  s21_decimal output;
  int s21_res = s21_div(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("\033[45m-=S21_DIV=-\033[0m");
  TCase *tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_6);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_8);
  tcase_add_test(tc, s21_div_9);
  tcase_add_test(tc, s21_div_10);
  tcase_add_test(tc, s21_div_11);
  tcase_add_test(tc, s21_div_12);
  tcase_add_test(tc, s21_div_13);
  tcase_add_test(tc, s21_div_14);
  tcase_add_test(tc, s21_div_15);
  tcase_add_test(tc, s21_div_16);
  tcase_add_test(tc, s21_div_17);
  tcase_add_test(tc, s21_div_18);
  tcase_add_test(tc, s21_div_19);
  tcase_add_test(tc, s21_div_20);
  tcase_add_test(tc, s21_div_21);
  tcase_add_test(tc, s21_div_22);

  suite_add_tcase(s, tc);
  return s;
}
