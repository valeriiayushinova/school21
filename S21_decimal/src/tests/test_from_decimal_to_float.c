#include "test_main.h"

START_TEST(s21_to_float_1) {
  s21_decimal inp = {{0x07F8347F, 0xC1A8A381, 0x7C8B01CD, 0x80100000}};
  float out;
  float res;
  unsigned char b[] = {82, 91, 96, 212};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_2) {
  s21_decimal inp = {{0x74DE3062, 0x4C6BCEB7, 0xAF44FE20, 0x000C0000}};
  float out;
  float res;
  unsigned char b[] = {251, 181, 64, 91};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_3) {
  s21_decimal inp = {{0x51D1EED4, 0x3A43F62D, 0xD815D747, 0x80080000}};
  float out;
  float res;
  unsigned char b[] = {45, 3, 17, 226};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_4) {
  s21_decimal inp = {{0x72B910C6, 0x4C72B550, 0xDB91A95E, 0x80170000}};
  float out;
  float res;
  unsigned char b[] = {210, 230, 37, 201};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_5) {
  s21_decimal inp = {{0x5E8B7CC8, 0x2A4D7938, 0x7B4CCA05, 0x00030000}};
  float out;
  float res;
  unsigned char b[] = {176, 132, 252, 105};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_6) {
  s21_decimal inp = {{0x58FE9C25, 0x90FA48E2, 0x140B5742, 0x00130000}};
  float out;
  float res;
  unsigned char b[] = {157, 230, 19, 78};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_7) {
  s21_decimal inp = {{0x68761ABC, 0xF76192BE, 0x195CBFB6, 0x80190000}};
  float out;
  float res;
  unsigned char b[] = {54, 59, 68, 196};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_8) {
  s21_decimal inp = {{0x854A2E16, 0xA6B7E550, 0x37BF9D52, 0x00070000}};
  float out;
  float res;
  unsigned char b[] = {152, 15, 187, 98};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_9) {
  s21_decimal inp = {{0xB059DB54, 0xBE4707EC, 0x676EAE4E, 0x000D0000}};
  float out;
  float res;
  unsigned char b[] = {202, 245, 53, 89};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_10) {
  s21_decimal inp = {{0xB2C22513, 0xFE676E04, 0x7FE4B386, 0x80110000}};
  float out;
  float res;
  unsigned char b[] = {83, 80, 184, 210};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_11) {
  s21_decimal inp = {{0x7791392B, 0x3BF8AE0F, 0x3EDEC9F4, 0x00090000}};
  float out;
  float res;
  unsigned char b[] = {76, 3, 135, 95};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_12) {
  s21_decimal inp = {{0xB3306728, 0x789F7C55, 0x3473FA5C, 0x000B0000}};
  float out;
  float res;
  unsigned char b[] = {139, 46, 16, 92};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_13) {
  s21_decimal inp = {{0x34139801, 0xC676EAFA, 0xFF5412D4, 0x800A0000}};
  float out;
  float res;
  unsigned char b[] = {80, 83, 219, 222};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_14) {
  s21_decimal inp = {{0x1DA41411, 0xDD5422DC, 0xC8228DAA, 0x00080000}};
  float out;
  float res;
  unsigned char b[] = {237, 78, 6, 98};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_15) {
  s21_decimal inp = {{0x403C319D, 0x3910EDD4, 0xDA1C78EC, 0x800D0000}};
  float out;
  float res;
  unsigned char b[] = {72, 218, 191, 217};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_16) {
  s21_decimal inp = {{0xF774DD5D, 0x8C54BE67, 0x119A7C8D, 0x000D0000}};
  float out;
  float res;
  unsigned char b[] = {41, 191, 247, 87};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_17) {
  s21_decimal inp = {{0x721C3CFD, 0x4ADB0D65, 0x59D2E8C2, 0x00050000}};
  float out;
  float res;
  unsigned char b[] = {198, 119, 107, 102};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_18) {
  s21_decimal inp = {{0x1A36571C, 0xE9272BD7, 0x708C3FDF, 0x80120000}};
  float out;
  float res;
  unsigned char b[] = {67, 194, 1, 209};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_19) {
  s21_decimal inp = {{0x47D02367, 0xF6D7F10D, 0xFF45F96D, 0x00040000}};
  float out;
  float res;
  unsigned char b[] = {179, 30, 209, 104};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_20) {
  s21_decimal inp = {{0x705C93D2, 0x62B89F80, 0x4DFB3C27, 0x00020000}};
  float out;
  float res;
  unsigned char b[] = {226, 161, 71, 107};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_21) {
  s21_decimal inp = {{0xB3015939, 0x4CFF5081, 0x0E76E246, 0x80140000}};
  float out;
  float res;
  unsigned char b[] = {240, 195, 42, 204};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_22) {
  s21_decimal inp = {{0x3B9D7A0C, 0x3A00EDEC, 0xC302AFEC, 0x00000000}};
  float out;
  float res;
  unsigned char b[] = {176, 2, 67, 111};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_23) {
  s21_decimal inp = {{0xDD117DEE, 0xF12483D6, 0xAE13E198, 0x80080000}};
  float out;
  float res;
  unsigned char b[] = {161, 164, 233, 225};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_24) {
  s21_decimal inp = {{0xE207F5B0, 0xCA9620E2, 0xD3C7F3C2, 0x000C0000}};
  float out;
  float res;
  unsigned char b[] = {18, 219, 104, 91};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_25) {
  s21_decimal inp = {{0xCF954062, 0x83E9C5A8, 0x4F2C5ED0, 0x80150000}};
  float out;
  float res;
  unsigned char b[] = {86, 241, 186, 203};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_26) {
  s21_decimal inp = {{0xA6C141BF, 0x91784E26, 0xFA111F0D, 0x00170000}};
  float out;
  float res;
  unsigned char b[] = {248, 241, 60, 73};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_27) {
  s21_decimal inp = {{0xE08E48A5, 0x2BDAA6CE, 0x86DBF405, 0x801B0000}};
  float out;
  float res;
  unsigned char b[] = {150, 242, 38, 194};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_28) {
  s21_decimal inp = {{0xD6E69C9D, 0x969EEF8F, 0xC11316F2, 0x00140000}};
  float out;
  float res;
  unsigned char b[] = {193, 118, 14, 78};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_29) {
  s21_decimal inp = {{0xC612E85E, 0xE8323E88, 0xE2F00D2A, 0x000B0000}};
  float out;
  float res;
  unsigned char b[] = {77, 243, 27, 93};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_30) {
  s21_decimal inp = {{0x4544919D, 0x16FDE9F1, 0x0ED1DE21, 0x00060000}};
  float out;
  float res;
  unsigned char b[] = {138, 162, 120, 99};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_31) {
  s21_decimal inp = {{0xDCE2E424, 0x98861681, 0x8AF023A1, 0x000C0000}};
  float out;
  float res;
  unsigned char b[] = {149, 195, 24, 91};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_32) {
  s21_decimal inp = {{0x5AA4230D, 0x4356CA1C, 0xB43A5135, 0x80180000}};
  float out;
  float res;
  unsigned char b[] = {206, 225, 89, 199};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_33) {
  s21_decimal inp = {{0xBD074833, 0xF78E4950, 0xDEF3BF08, 0x00120000}};
  float out;
  float res;
  unsigned char b[] = {237, 133, 128, 81};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_34) {
  s21_decimal inp = {{0x83C97A1D, 0x8016D99C, 0xA8D44FFB, 0x80030000}};
  float out;
  float res;
  unsigned char b[] = {154, 225, 44, 234};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_35) {
  s21_decimal inp = {{0x146F3E03, 0x7533DA9A, 0xFB737BF7, 0x00100000}};
  float out;
  float res;
  unsigned char b[] = {174, 124, 226, 84};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_36) {
  s21_decimal inp = {{0x59AF6D0C, 0x03793331, 0x9A6159A5, 0x00030000}};
  float out;
  float res;
  unsigned char b[] = {221, 21, 30, 106};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_37) {
  s21_decimal inp = {{0xB8D150C7, 0xA98EBB38, 0xB47EF7EE, 0x80070000}};
  float out;
  float res;
  unsigned char b[] = {55, 105, 151, 227};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_38) {
  s21_decimal inp = {{0xDCD24AA8, 0x4DDFB8BC, 0x1F838B55, 0x00070000}};
  float out;
  float res;
  unsigned char b[] = {96, 124, 83, 98};
  memcpy(&res, &b, 4);
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_39) {
  s21_decimal inp = {{0x164338CA, 0x77E94EA2, 0xDD7ECF07, 0x00000000}};
  float *out = NULL;
  int error = s21_from_decimal_to_float(inp, out);
  ck_assert_ptr_eq(out, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_FLOAT=-\033[0m");
  TCase *tc = tcase_create("s21_to_float_tc");

  tcase_add_test(tc, s21_to_float_1);
  tcase_add_test(tc, s21_to_float_2);
  tcase_add_test(tc, s21_to_float_3);
  tcase_add_test(tc, s21_to_float_4);
  tcase_add_test(tc, s21_to_float_5);
  tcase_add_test(tc, s21_to_float_6);
  tcase_add_test(tc, s21_to_float_7);
  tcase_add_test(tc, s21_to_float_8);
  tcase_add_test(tc, s21_to_float_9);
  tcase_add_test(tc, s21_to_float_10);
  tcase_add_test(tc, s21_to_float_11);
  tcase_add_test(tc, s21_to_float_12);
  tcase_add_test(tc, s21_to_float_13);
  tcase_add_test(tc, s21_to_float_14);
  tcase_add_test(tc, s21_to_float_15);
  tcase_add_test(tc, s21_to_float_16);
  tcase_add_test(tc, s21_to_float_17);
  tcase_add_test(tc, s21_to_float_18);
  tcase_add_test(tc, s21_to_float_19);
  tcase_add_test(tc, s21_to_float_20);
  tcase_add_test(tc, s21_to_float_21);
  tcase_add_test(tc, s21_to_float_22);
  tcase_add_test(tc, s21_to_float_23);
  tcase_add_test(tc, s21_to_float_24);
  tcase_add_test(tc, s21_to_float_25);
  tcase_add_test(tc, s21_to_float_26);
  tcase_add_test(tc, s21_to_float_27);
  tcase_add_test(tc, s21_to_float_28);
  tcase_add_test(tc, s21_to_float_29);
  tcase_add_test(tc, s21_to_float_30);
  tcase_add_test(tc, s21_to_float_31);
  tcase_add_test(tc, s21_to_float_32);
  tcase_add_test(tc, s21_to_float_33);
  tcase_add_test(tc, s21_to_float_34);
  tcase_add_test(tc, s21_to_float_35);
  tcase_add_test(tc, s21_to_float_36);
  tcase_add_test(tc, s21_to_float_37);
  tcase_add_test(tc, s21_to_float_38);
  tcase_add_test(tc, s21_to_float_39);

  suite_add_tcase(s, tc);
  return s;
}
