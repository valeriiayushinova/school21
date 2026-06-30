#include "test_main.h"

START_TEST(s21_float_1) {
  float inp = -321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8EF1F395, 0x00721CF8, 0x00000000, 0x800E0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_2) {
  float inp = 321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8EF1F395, 0x00721CF8, 0x00000000, 0x000E0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_3) {
  float inp = 321213143.8323;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x132552E0, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_4) {
  float inp = 9732131234575756436473.323123474;
  s21_decimal out = {{3211, 123145, 231, 312441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000000, 0x94740000, 0x0000020F, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_5) {
  float inp = 73.329959999;
  s21_decimal out = {{3211, 123145, 231, 312441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x5E334F75, 0x65C40958, 0x00000000, 0x00110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_6) {
  float inp = 0.003;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x86C08FA0, 0x45DA7512, 0x0018D0BF, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_7) {
  float inp = 0.00312345;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x267E2279, 0xB02F7FCD, 0x0019D629, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_8) {
  float inp = 0.00000003123959595945;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xCC664C59, 0xEF5D74CD, 0x00000010, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_9) {
  float inp = 0.0000000000000000093929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xDEA0B034, 0x00000015, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_10) {
  float inp = 0.00000000000000000000000000013929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_11) {
  float inp = .00000000000000000000000000000000193929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_float_12) {
  float inp = 2183182381923912939123.365656f;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000000, 0x59BE0000, 0x00000076, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_13) {
  float inp = 79215000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000000, 0x00000000, 0xFFF51D00, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_14) {
  float inp = 7015000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000000, 0x00000000, 0x16AAAC00, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_15) {
  float inp = 0.00000000000000000000000005646473736464;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000235, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_16) {
  float inp = 0.00000000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_17) {
  float inp = 0.00000000000000000000000858598287381972;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000218A, 0, 0, 0x001B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_18) {
  float inp = 0.000000000000000000000099999999999;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000001, 0, 0, 0x00160000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_19) {
  float inp = 0.00000000000000000000073766666662636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00708F1B, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_20) {
  float inp = 0.0000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x046520A6, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_21) {
  float inp = 0.00000000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_22) {
  float inp = -1.307818E+07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00C78EA4, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_23) {
  float inp = -30914.76;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE7462E79, 0x00001C1D, 0x00000000, 0x80090000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_24) {
  float inp = 1.965111E-26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000000C5, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_25) {
  float inp = -750.9904;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x3A5D541B, 0x010ACE2E, 0x00000000, 0x800E0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_26) {
  float inp = 72932.2;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xFB191A75, 0x00000010, 0x00000000, 0x00060000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_27) {
  float inp = 7.526432E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF0DB868A, 0x0239EB87, 0x00000198, 0x001B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_29) {
  float inp = -1.391184E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000000, 0x01EE3F72, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_30) {
  float inp = 3.693497E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xDDDDC255, 0x0093601A, 0x00000002, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_31) {
  float inp = 351871.4;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x31512811, 0x00000008, 0x00000000, 0x00050000}};
  ;
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_32) {
  float inp = 0.1175977;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x1F64369D, 0x7F977128, 0x0000027D, 0x00170000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_33) {
  float inp = -2.013319E-14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x3CAD9BFB, 0x0000B71C, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_34) {
  float inp = -280.7036;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xA3EA69FD, 0x00001987, 0x00000000, 0x800B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_35) {
  float inp = -3.196059E+18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000000, 0x2C5AAEC0, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_36) {
  float inp = -1.38892E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x50800000, 0x00007E52, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_37) {
  float inp = 6.068951E+09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x69BCD800, 0x00000001, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_38) {
  float inp = 1. / 0.;
  s21_decimal out;
  int error = s21_from_float_to_decimal(inp, &out);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(s21_float_39) {
  float inp = 2;
  s21_decimal *out = NULL;
  int error = s21_from_float_to_decimal(inp, out);
  ck_assert_ptr_eq(out, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(s21_float_40) {
  float inp = 2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_FLOAT_TO_DECIMAL=-\033[0m");
  TCase *tc = tcase_create("s21_from_float_to_decimal_tc");

  tcase_add_test(tc, s21_float_1);
  tcase_add_test(tc, s21_float_2);
  tcase_add_test(tc, s21_float_3);
  tcase_add_test(tc, s21_float_4);
  tcase_add_test(tc, s21_float_5);
  tcase_add_test(tc, s21_float_6);
  tcase_add_test(tc, s21_float_7);
  tcase_add_test(tc, s21_float_8);
  tcase_add_test(tc, s21_float_9);
  tcase_add_test(tc, s21_float_10);
  tcase_add_test(tc, s21_float_11);
  tcase_add_test(tc, s21_float_12);
  tcase_add_test(tc, s21_float_13);
  tcase_add_test(tc, s21_float_14);
  tcase_add_test(tc, s21_float_15);
  tcase_add_test(tc, s21_float_16);
  tcase_add_test(tc, s21_float_17);
  tcase_add_test(tc, s21_float_18);
  tcase_add_test(tc, s21_float_19);
  tcase_add_test(tc, s21_float_20);
  tcase_add_test(tc, s21_float_21);
  tcase_add_test(tc, s21_float_22);
  tcase_add_test(tc, s21_float_23);
  tcase_add_test(tc, s21_float_24);
  tcase_add_test(tc, s21_float_25);
  tcase_add_test(tc, s21_float_26);
  tcase_add_test(tc, s21_float_27);
  tcase_add_test(tc, s21_float_29);
  tcase_add_test(tc, s21_float_30);
  tcase_add_test(tc, s21_float_31);
  tcase_add_test(tc, s21_float_32);
  tcase_add_test(tc, s21_float_33);
  tcase_add_test(tc, s21_float_34);
  tcase_add_test(tc, s21_float_35);
  tcase_add_test(tc, s21_float_36);
  tcase_add_test(tc, s21_float_37);
  tcase_add_test(tc, s21_float_38);
  tcase_add_test(tc, s21_float_39);
  tcase_add_test(tc, s21_float_40);

  suite_add_tcase(s, tc);
  return s;
}
