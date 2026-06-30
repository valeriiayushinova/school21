#include "test_main.h"

START_TEST(s21_add_1) {
  int true_res = 0;
  s21_decimal number1 = {{0x2819E464, 0xEB438F3C, 0x35C6F888, 0x00150000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number3 = {{0xFF020B50, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_2) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0xAF44FE20, 0x00223705, 0x0BC4451D, 0x00060000}};
  s21_decimal number3 = {{0xD8B1ED40, 0x01562638, 0x75AAB322, 0x00070000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_3) {
  int true_res = 0;
  s21_decimal number1 = {{0xD2CFED81, 0x0C6815A5, 0x550A2BF8, 0x001A0000}};
  s21_decimal number2 = {{0xD078C8D6, 0x5E8B7CC8, 0x2A4D7938, 0x80120000}};
  s21_decimal number3 = {{0x4DE10D95, 0x1A1DBAF7, 0x2A4D792A, 0x80120000}};
  s21_decimal output;
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_4) {
  int true_res = 2;
  s21_decimal number1 = {{0x0A957738, 0x1CEA3F77, 0x43D0C8C5, 0x80010000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_5) {
  int true_res = 0;
  s21_decimal number1 = {{0xE54D2721, 0xCC4F84AD, 0x5AEC559D, 0x000C0000}};
  s21_decimal number2 = {{0xBD76BBA3, 0xFDFB89D5, 0xA5BE4FD8, 0x00060000}};
  s21_decimal number3 = {{0xF57E10EF, 0x6E12B994, 0xA5BE55CE, 0x00060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_6) {
  int true_res = 0;
  s21_decimal number1 = {{0xF6D7F10D, 0xFF45F96D, 0x92E95263, 0x000C0000}};
  s21_decimal number2 = {{0xE46DB62B, 0x5B0FD4DF, 0x65C82DB6, 0x80000000}};
  s21_decimal number3 = {{0xE75C28C5, 0x5A6E4CFC, 0x65C82DB6, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_7) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0xB6112139, 0xA0C7436F, 0xDECED9D7, 0x00180000}};
  s21_decimal number3 = {{0xB6112139, 0xA0C7436F, 0xDECED9D7, 0x00180000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_8) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number3 = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_9) {
  int true_res = 1;
  s21_decimal number1 = {{0xFA111F0D, 0xEC4B8CE5, 0xBB750E08, 0x00040000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number3 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_10) {
  int true_res = 2;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0x22AF2435, 0xA4EE5B43, 0x83337718, 0x80060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_11) {
  int true_res = 0;
  s21_decimal number1 = {{0xF08EC9FB, 0xA1700518, 0x83C97A1D, 0x80110000}};
  s21_decimal number2 = {{0xA8D44FFB, 0xD8A97214, 0x09411146, 0x800D0000}};
  s21_decimal number3 = {{0x6F92F270, 0xC1C9D511, 0x5CAC698F, 0x800E0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_12) {
  int true_res = 0;
  s21_decimal number1 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal number2 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number3 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_13) {
  int true_res = 0;
  s21_decimal number1 = {{0x4544919D, 0x16FDE9F1, 0x0ED1DE21, 0x00060000}};
  s21_decimal number2 = {{0x4EBBCDCE, 0xD2E63988, 0x46EA28AF, 0x00060000}};
  s21_decimal number3 = {{0x94005F6B, 0xE9E42379, 0x55BC06D0, 0x00060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_14) {
  int true_res = 0;
  s21_decimal number1 = {{0xD9AB9F10, 0x7A488D6E, 0xB6BC4969, 0x00150000}};
  s21_decimal number2 = {{0x85EA2597, 0xE883DCB2, 0xD2A192CF, 0x80030000}};
  s21_decimal number3 = {{0x5B0A2B4F, 0xE883DCA5, 0xD2A192CF, 0x80030000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_15) {
  int true_res = 0;
  s21_decimal number1 = {{0x14A1D0CE, 0x89BC108A, 0x17C39287, 0x00000000}};
  s21_decimal number2 = {{0x3CFDBF53, 0xB24F4A86, 0x921E04AD, 0x00000000}};
  s21_decimal number3 = {{0x519F9021, 0x3C0B5B10, 0xA9E19735, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_16) {
  int true_res = 0;
  s21_decimal number1 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal number2 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number3 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_17) {
  int true_res = 0;
  s21_decimal number1 = {{0x064A65BA, 0xDD117DEE, 0xF12483D6, 0x00020000}};
  s21_decimal number2 = {{0x167694AA, 0x71E30E20, 0xBE745CA9, 0x00170000}};
  s21_decimal number3 = {{0x09CDCB23, 0xDD117DEE, 0xF12483D6, 0x00020000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_18) {
  int true_res = 0;
  s21_decimal number1 = {{0xE54D2721, 0xCC4F84AD, 0x5AEC559D, 0x000C0000}};
  s21_decimal number2 = {{0xBD76BBA3, 0xFDFB89D5, 0xA5BE4FD8, 0x00060000}};
  s21_decimal number3 = {{0xF57E10EF, 0x6E12B994, 0xA5BE55CE, 0x00060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_19) {
  int true_res = 0;
  s21_decimal number1 = {{0xF6D7F10D, 0xFF45F96D, 0x92E95263, 0x000C0000}};
  s21_decimal number2 = {{0xE46DB62B, 0x5B0FD4DF, 0x65C82DB6, 0x80000000}};
  s21_decimal number3 = {{0xE75C28C5, 0x5A6E4CFC, 0x65C82DB6, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_20) {
  int true_res = 0;
  s21_decimal number1 = {{0x57226211, 0xD647F58F, 0xB0FF890F, 0x00020000}};
  s21_decimal number2 = {{0xABC947B5, 0x2BE60B34, 0xFB68067E, 0x000F0000}};
  s21_decimal number3 = {{0x011EBEDE, 0xD6639A05, 0xB0FF890F, 0x00020000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_21) {
  int true_res = 0;
  s21_decimal number1 = {{0x854A2E16, 0xA6B7E550, 0x37BF9D52, 0x00070000}};
  s21_decimal number2 = {{0x668F8B05, 0x559FBBE4, 0x7954D676, 0x000B0000}};
  s21_decimal number3 = {{0xB96BEF68, 0xF51D35FF, 0x37C2B87A, 0x00070000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_22) {
  int true_res = 0;
  s21_decimal number1 = {{0xE040FA55, 0x386B8A7E, 0x969CFE95, 0x00100000}};
  s21_decimal number2 = {{0x3BF8AE0F, 0x3EDEC9F4, 0x37596530, 0x00140000}};
  s21_decimal number3 = {{0xBAADD40D, 0xC4EB4EA9, 0x969E6951, 0x00100000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_23) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number2 = {{0x3473FA5C, 0xBCE1D699, 0xFA76A341, 0x80160000}};
  s21_decimal number3 = {{0x3473FA5C, 0xBCE1D699, 0xFA76A341, 0x80160000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_24) {
  int true_res = 0;
  s21_decimal number1 = {{0xD79E6FF5, 0x41143A2A, 0x2DC46EEF, 0x80020000}};
  s21_decimal number2 = {{0x4CD613A7, 0x403C319D, 0x3910EDD4, 0x00100000}};
  s21_decimal number3 = {{0x5CDA3800, 0x4113998A, 0x2DC46EEF, 0x80020000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_25) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{0x422BDB6F, 0xEA71081D, 0xFB7D9F9E, 0x00000000}};
  s21_decimal number3 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_26) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number2 = {{0x00000005, 0x00000000, 0x00000000, 0x00010000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_27) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00010000}};
  s21_decimal number2 = {{0x00000005, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal number3 = {{0x9999999A, 0x99999999, 0x19999999, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x80000000, 0x00000000}};
  int s21_res = s21_add(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_add(void) {
  Suite *s = suite_create("\033[45m-=S21_ADD=-\033[0m");
  TCase *tc = tcase_create("s21_add_tc");

  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);
  tcase_add_test(tc, s21_add_8);
  tcase_add_test(tc, s21_add_9);
  tcase_add_test(tc, s21_add_10);
  tcase_add_test(tc, s21_add_11);
  tcase_add_test(tc, s21_add_12);
  tcase_add_test(tc, s21_add_13);
  tcase_add_test(tc, s21_add_14);
  tcase_add_test(tc, s21_add_15);
  tcase_add_test(tc, s21_add_16);
  tcase_add_test(tc, s21_add_17);
  tcase_add_test(tc, s21_add_18);
  tcase_add_test(tc, s21_add_19);
  tcase_add_test(tc, s21_add_20);
  tcase_add_test(tc, s21_add_21);
  tcase_add_test(tc, s21_add_22);
  tcase_add_test(tc, s21_add_23);
  tcase_add_test(tc, s21_add_24);
  tcase_add_test(tc, s21_add_25);
  tcase_add_test(tc, s21_add_26);
  tcase_add_test(tc, s21_add_27);

  suite_add_tcase(s, tc);
  return s;
}
