#include "test_main.h"

START_TEST(s21_sub_1) {
  int true_res = 1;
  s21_decimal number1 = {{0x2819E464, 0xEB438F3C, 0x35C6F888, 0x00150000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_2) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0xAF44FE20, 0x00223705, 0x0BC4451D, 0x00060000}};
  s21_decimal number3 = {{0xD8B1ED40, 0x01562638, 0x75AAB322, 0x80070000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_3) {
  int true_res = 0;
  s21_decimal number1 = {{0x9E0AD71A, 0x51DE4CE3, 0x7C7E230F, 0x00130000}};
  s21_decimal number2 = {{0xA1BC94CD, 0x5B315F96, 0xE77AD916, 0x800D0000}};
  s21_decimal number3 = {{0x3E474BBF, 0xFF5D4DB0, 0xE77AE13E, 0x000D0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_4) {
  int true_res = 0;
  s21_decimal number1 = {{0x57226211, 0xD647F58F, 0xB0FF890F, 0x00020000}};
  s21_decimal number2 = {{0xABC947B5, 0x2BE60B34, 0xFB68067E, 0x000F0000}};
  s21_decimal number3 = {{0xAD260544, 0xD62C5119, 0xB0FF890F, 0x00020000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_5) {
  int true_res = 0;
  s21_decimal number1 = {{0x854A2E16, 0xA6B7E550, 0x37BF9D52, 0x00070000}};
  s21_decimal number2 = {{0x668F8B05, 0x559FBBE4, 0x7954D676, 0x000B0000}};
  s21_decimal number3 = {{0x51286CC4, 0x585294A1, 0x37BC822A, 0x00070000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_6) {
  int true_res = 0;
  s21_decimal number1 = {{0xE040FA55, 0x386B8A7E, 0x969CFE95, 0x00100000}};
  s21_decimal number2 = {{0x3BF8AE0F, 0x3EDEC9F4, 0x37596530, 0x00140000}};
  s21_decimal number3 = {{0x05D4209D, 0xABEBC654, 0x969B93D8, 0x00100000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_7) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0x3473FA5C, 0xBCE1D699, 0xFA76A341, 0x80160000}};
  s21_decimal number3 = {{0x3473FA5C, 0xBCE1D699, 0xFA76A341, 0x00160000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_8) {
  int true_res = 0;
  s21_decimal number1 = {{0xD79E6FF5, 0x41143A2A, 0x2DC46EEF, 0x80020000}};
  s21_decimal number2 = {{0x4CD613A7, 0x403C319D, 0x3910EDD4, 0x00100000}};
  s21_decimal number3 = {{0x5262A7EA, 0x4114DACB, 0x2DC46EEF, 0x80020000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_9) {
  int true_res = 0;
  s21_decimal number1 = {{0x0A957738, 0x1CEA3F77, 0x43D0C8C5, 0x80010000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number3 = {{0xE5577413, 0x49E89340, 0xF937EBEC, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_10) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number3 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_11) {
  int true_res = 0;
  s21_decimal number1 = {{0xF6D7F10D, 0xFF45F96D, 0x92E95263, 0x000C0000}};
  s21_decimal number2 = {{0xE46DB62B, 0x5B0FD4DF, 0x65C82DB6, 0x80000000}};
  s21_decimal number3 = {{0xE17F4391, 0x5BB15CC2, 0x65C82DB6, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_12) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0xB6112139, 0xA0C7436F, 0xDECED9D7, 0x00180000}};
  s21_decimal number3 = {{0xB6112139, 0xA0C7436F, 0xDECED9D7, 0x80180000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_13) {
  int true_res = 0;
  s21_decimal number1 = {{0x064A65BA, 0xDD117DEE, 0xF12483D6, 0x00020000}};
  s21_decimal number2 = {{0x167694AA, 0x71E30E20, 0xBE745CA9, 0x00170000}};
  s21_decimal number3 = {{0x02C70051, 0xDD117DEE, 0xF12483D6, 0x00020000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_14) {
  int true_res = 0;
  s21_decimal number1 = {{0x0000001, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal number2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal number3 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_15) {
  int true_res = 0;
  s21_decimal number1 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal number2 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number3 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_16) {
  int true_res = 0;
  s21_decimal number1 = {{0xFA111F0D, 0xEC4B8CE5, 0xBB750E08, 0x00040000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number3 = {{0xC617E89F, 0xEE28A52E, 0xFFFB337A, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_17) {
  int true_res = 0;
  s21_decimal number1 = {{0xD9AB9F10, 0x7A488D6E, 0xB6BC4969, 0x00150000}};
  s21_decimal number2 = {{0x85EA2597, 0xE883DCB2, 0xD2A192CF, 0x80030000}};
  s21_decimal number3 = {{0xB0CA1FDF, 0xE883DCBF, 0xD2A192CF, 0x00030000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_18) {
  int true_res = 0;
  s21_decimal number1 = {{0x4544919D, 0x16FDE9F1, 0x0ED1DE21, 0x00060000}};
  s21_decimal number2 = {{0x4EBBCDCE, 0xD2E63988, 0x46EA28AF, 0x00060000}};
  s21_decimal number3 = {{0x09773C31, 0xBBE84F97, 0x38184A8E, 0x80060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_19) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0x22AF2435, 0xA4EE5B43, 0x83337718, 0x80060000}};
  s21_decimal number3 = {{0x312F1859, 0xCFD75351, 0xFFFFF766, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_20) {
  int true_res = 0;
  s21_decimal number1 = {{0xF08EC9FB, 0xA1700518, 0x83C97A1D, 0x80110000}};
  s21_decimal number2 = {{0xA8D44FFB, 0xD8A97214, 0x09411146, 0x800D0000}};
  s21_decimal number3 = {{0xC1034D2C, 0x2B73148B, 0x5C68EFF9, 0x000E0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_sub(void) {
  Suite *s = suite_create("\033[45m-=S21_SUB=-\033[0m");
  TCase *tc = tcase_create("s21_sub_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_12);
  tcase_add_test(tc, s21_sub_13);
  tcase_add_test(tc, s21_sub_14);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
  tcase_add_test(tc, s21_sub_17);
  tcase_add_test(tc, s21_sub_18);
  tcase_add_test(tc, s21_sub_19);
  tcase_add_test(tc, s21_sub_20);

  suite_add_tcase(s, tc);
  return s;
}
