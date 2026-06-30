#include "test_main.h"

START_TEST(s21_mul_1) {
  int true_res = 2;
  s21_decimal number1 = {{0x2819E464, 0xEB438F3C, 0x35C6F888, 0x00150000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_2) {
  int true_res = 2;
  s21_decimal number1 = {{0xA96DF7C5, 0x82CFC050, 0x173A2998, 0x800B0000}};
  s21_decimal number2 = {{0x1388DBE5, 0xA883DCA4, 0x5AD54F75, 0x00040000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST
START_TEST(s21_mul_3) {
  int true_res = 0;
  s21_decimal number1 = {{0xD2CFED81, 0x0C6815A5, 0x550A2BF8, 0x001A0000}};
  s21_decimal number2 = {{0xD078C8D6, 0x5E8B7CC8, 0x2A4D7938, 0x80120000}};
  s21_decimal number3 = {{0x739DE59C, 0xC63B855F, 0x6F559311, 0x80100000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_4) {
  int true_res = 1;
  s21_decimal number1 = {{0x57226211, 0xD647F58F, 0xB0FF890F, 0x00020000}};
  s21_decimal number2 = {{0xABC947B5, 0x2BE60B34, 0xFB68067E, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_5) {
  int true_res = 1;
  s21_decimal number1 = {{0x854A2E16, 0xA6B7E550, 0x37BF9D52, 0x00070000}};
  s21_decimal number2 = {{0x668F8B05, 0x559FBBE4, 0x7954D676, 0x000B0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_6) {
  int true_res = 0;
  s21_decimal number1 = {{0xE040FA55, 0x386B8A7E, 0x969CFE95, 0x00100000}};
  s21_decimal number2 = {{0x3BF8AE0F, 0x3EDEC9F4, 0x37596530, 0x00140000}};
  s21_decimal number3 = {{0x892C99FC, 0x9E5A0034, 0x19CCB745, 0x00070000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_7) {
  int true_res = 1;
  s21_decimal number1 = {{0x6096F430, 0x94781453, 0x5F72E816, 0x80050000}};
  s21_decimal number2 = {{0xF5E16214, 0x100E194A, 0x8F3AC400, 0x80130000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_8) {
  int true_res = 2;
  s21_decimal number1 = {{0xD79E6FF5, 0x41143A2A, 0x2DC46EEF, 0x80020000}};
  s21_decimal number2 = {{0x4CD613A7, 0x403C319D, 0x3910EDD4, 0x00100000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_9) {
  int true_res = 1;
  s21_decimal number1 = {{0x0A957738, 0x1CEA3F77, 0x43D0C8C5, 0x80010000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_10) {
  int true_res = 1;
  s21_decimal number1 = {{0xE54D2721, 0xCC4F84AD, 0x5AEC559D, 0x000C0000}};
  s21_decimal number2 = {{0xBD76BBA3, 0xFDFB89D5, 0xA5BE4FD8, 0x00060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_11) {
  int true_res = 2;
  s21_decimal number1 = {{0xF6D7F10D, 0xFF45F96D, 0x92E95263, 0x000C0000}};
  s21_decimal number2 = {{0xE46DB62B, 0x5B0FD4DF, 0x65C82DB6, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_12) {
  int true_res = 2;
  s21_decimal number1 = {{0x7062AF49, 0x6F47AC25, 0x8B38115E, 0x00170000}};
  s21_decimal number2 = {{0xE1097289, 0x060D91BE, 0x5CE3CD9A, 0x80040000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_13) {
  int true_res = 1;
  s21_decimal number1 = {{0x064A65BA, 0xDD117DEE, 0xF12483D6, 0x00020000}};
  s21_decimal number2 = {{0x167694AA, 0x71E30E20, 0xBE745CA9, 0x00170000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_14) {
  int true_res = 2;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_15) {
  int true_res = 0;
  s21_decimal number1 = {{0x83E9C5A8, 0x4F2C5ED0, 0xD5251BCF, 0x00120000}};
  s21_decimal number2 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal number3 = {{0x5BD49823, 0x0000000F, 0x00000000, 0x001C0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_16) {
  int true_res = 1;
  s21_decimal number1 = {{0xFA111F0D, 0xEC4B8CE5, 0xBB750E08, 0x00040000}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_17) {
  int true_res = 2;
  s21_decimal number1 = {{0xD9AB9F10, 0x7A488D6E, 0xB6BC4969, 0x00150000}};
  s21_decimal number2 = {{0x85EA2597, 0xE883DCB2, 0xD2A192CF, 0x80030000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_18) {
  int true_res = 1;
  s21_decimal number1 = {{0x4544919D, 0x16FDE9F1, 0x0ED1DE21, 0x00060000}};
  s21_decimal number2 = {{0x4EBBCDCE, 0xD2E63988, 0x46EA28AF, 0x00060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_19) {
  int true_res = 1;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{0x22AF2435, 0xA4EE5B43, 0x83337718, 0x80060000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_20) {
  int true_res = 0;
  s21_decimal number1 = {{0xF08EC9FB, 0xA1700518, 0x83C97A1D, 0x80110000}};
  s21_decimal number2 = {{0xA8D44FFB, 0xD8A97214, 0x09411146, 0x800D0000}};
  s21_decimal number3 = {{0x4D766A1A, 0x1E637A84, 0x25BE8107, 0x00020000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_21) {
  int true_res = 1;
  s21_decimal number1 = {{0x50FF5F69, 0xDA07C98D, 0x66211715, 0x800B0000}};
  s21_decimal number2 = {{0xBD45DF5F, 0x39753B0D, 0x860636A7, 0x800E0000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_22) {
  int true_res = 2;
  s21_decimal number1 = {{0x58029FC8, 0xF7F17607, 0x3C067E8C, 0x00030000}};
  s21_decimal number2 = {{0x77C27CDA, 0x27B29AF3, 0x53C1DA90, 0x80050000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_23) {
  int true_res = 2;
  s21_decimal number1 = {{0xDD0D1E8C, 0xB4A266AB, 0x056925A3, 0x00050000}};
  s21_decimal number2 = {{0xD19B1143, 0x0B406C17, 0xD3A634D5, 0x80070000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_24) {
  int true_res = 1;
  s21_decimal number1 = {{0xDA40EC11, 0xD4832CA5, 0x5976AEC3, 0x00100000}};
  s21_decimal number2 = {{0x2C124DC6, 0x0AFC4E64, 0xA06587D8, 0x00040000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_25) {
  int true_res = 1;
  s21_decimal number1 = {{0x18E3DB4B, 0xC46DB38E, 0xECDCCE99, 0x80080000}};
  s21_decimal number2 = {{0x62060EC2, 0x0A745795, 0x09D72853, 0x80080000}};
  s21_decimal output;
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_26) {
  int true_res = 0;
  s21_decimal number1 = {{1, 0, 0, 0}};
  s21_decimal number2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal number3 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(number1, number2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], number3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_mul(void) {
  Suite *s = suite_create("\033[45m-=S21_MUL=-\033[0m");
  TCase *tc = tcase_create("s21_mul_tc");

  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_15);
  tcase_add_test(tc, s21_mul_16);
  tcase_add_test(tc, s21_mul_17);
  tcase_add_test(tc, s21_mul_18);
  tcase_add_test(tc, s21_mul_19);
  tcase_add_test(tc, s21_mul_20);
  tcase_add_test(tc, s21_mul_21);
  tcase_add_test(tc, s21_mul_22);
  tcase_add_test(tc, s21_mul_23);
  tcase_add_test(tc, s21_mul_24);
  tcase_add_test(tc, s21_mul_25);
  tcase_add_test(tc, s21_mul_26);

  suite_add_tcase(s, tc);
  return s;
}
