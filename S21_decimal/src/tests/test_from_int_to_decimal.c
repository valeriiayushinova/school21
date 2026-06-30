#include "test_main.h"

START_TEST(s21_from_int_to_decimal_1) {
  int inp = -1673116978;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x63B9BD32, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  int inp = -589404005;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x23219765, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
  int inp = 1291320926;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x4CF7FE5E, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_4) {
  int inp = -1973534755;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x75A1C023, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_5) {
  int inp = 1145102366;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x4440E01E, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_6) {
  int inp = 1051398138;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x3EAB0FFA, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_7) {
  int inp = -51613149;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x03138DDD, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_8) {
  int inp = -318903841;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x13021621, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_9) {
  int inp = 641065231;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x2635E10F, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_10) {
  int inp = -1895891910;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x710103C6, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_11) {
  int inp = 856135424;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x33079700, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_12) {
  int inp = 1121029;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x00111B05, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_13) {
  int inp = -686356390;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x28E8F7A6, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_14) {
  int inp = 829075809;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x316AB161, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_15) {
  int inp = -2140287028;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x7F923034, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_16) {
  int inp = 1812654605;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x6C0AEA0D, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_17) {
  int inp = -592812235;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x235598CB, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_18) {
  int inp = 104074045;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x06340B3D, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_19) {
  int inp = 1606881365;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x5FC71055, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_20) {
  int inp = -641293626;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x26395D3A, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_21) {
  int inp = -1257513505;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x4AF42221, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_22) {
  int inp = -1185946382;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x46B01B0E, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_23) {
  int inp = 99325770;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x05EB974A, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_24) {
  int inp = 793098876;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x2F45BA7C, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_25) {
  int inp = 1237714930;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x49C607F2, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_26) {
  int inp = 1336208234;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x4FA4EB6A, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_27) {
  int inp = -1034313779;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x3DA66033, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_28) {
  int inp = 277692567;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x108D4097, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_29) {
  int inp = 1630510559;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x612F9DDF, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_30) {
  int inp = 1797520420;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x6B23FC24, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_31) {
  int inp = -1216160737;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x487D23E1, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_32) {
  int inp = 974225428;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x3A118014, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_33) {
  int inp = 785945215;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x2ED8927F, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_34) {
  int inp = -1034458146;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x3DA89422, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_35) {
  int inp = 876285665;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x343B0EE1, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_36) {
  int inp = -368248092;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x15F3051C, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_37) {
  int inp = 871716970;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x33F5586A, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_38) {
  int inp = -212752571;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x0CAE58BB, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_39) {
  int inp = 1903718589;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x717870BD, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_40) {
  int inp = -1891020902;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0x70B6B066, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_41) {
  int inp = 1995698117;
  s21_decimal *out = NULL;
  int error = s21_from_int_to_decimal(inp, out);
  ck_assert_int_eq(error, 1);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=s21_FROM_INT_TO_DECIMAL=-\033[0m");
  TCase *tc = tcase_create("s21_from_int_to_decimal_tc");

  tcase_add_test(tc, s21_from_int_to_decimal_1);
  tcase_add_test(tc, s21_from_int_to_decimal_2);
  tcase_add_test(tc, s21_from_int_to_decimal_3);
  tcase_add_test(tc, s21_from_int_to_decimal_4);
  tcase_add_test(tc, s21_from_int_to_decimal_5);
  tcase_add_test(tc, s21_from_int_to_decimal_6);
  tcase_add_test(tc, s21_from_int_to_decimal_7);
  tcase_add_test(tc, s21_from_int_to_decimal_8);
  tcase_add_test(tc, s21_from_int_to_decimal_9);
  tcase_add_test(tc, s21_from_int_to_decimal_10);
  tcase_add_test(tc, s21_from_int_to_decimal_11);
  tcase_add_test(tc, s21_from_int_to_decimal_12);
  tcase_add_test(tc, s21_from_int_to_decimal_13);
  tcase_add_test(tc, s21_from_int_to_decimal_14);
  tcase_add_test(tc, s21_from_int_to_decimal_15);
  tcase_add_test(tc, s21_from_int_to_decimal_16);
  tcase_add_test(tc, s21_from_int_to_decimal_17);
  tcase_add_test(tc, s21_from_int_to_decimal_18);
  tcase_add_test(tc, s21_from_int_to_decimal_19);
  tcase_add_test(tc, s21_from_int_to_decimal_20);
  tcase_add_test(tc, s21_from_int_to_decimal_21);
  tcase_add_test(tc, s21_from_int_to_decimal_22);
  tcase_add_test(tc, s21_from_int_to_decimal_23);
  tcase_add_test(tc, s21_from_int_to_decimal_24);
  tcase_add_test(tc, s21_from_int_to_decimal_25);
  tcase_add_test(tc, s21_from_int_to_decimal_26);
  tcase_add_test(tc, s21_from_int_to_decimal_27);
  tcase_add_test(tc, s21_from_int_to_decimal_28);
  tcase_add_test(tc, s21_from_int_to_decimal_29);
  tcase_add_test(tc, s21_from_int_to_decimal_30);
  tcase_add_test(tc, s21_from_int_to_decimal_31);
  tcase_add_test(tc, s21_from_int_to_decimal_32);
  tcase_add_test(tc, s21_from_int_to_decimal_33);
  tcase_add_test(tc, s21_from_int_to_decimal_34);
  tcase_add_test(tc, s21_from_int_to_decimal_35);
  tcase_add_test(tc, s21_from_int_to_decimal_36);
  tcase_add_test(tc, s21_from_int_to_decimal_37);
  tcase_add_test(tc, s21_from_int_to_decimal_38);
  tcase_add_test(tc, s21_from_int_to_decimal_39);
  tcase_add_test(tc, s21_from_int_to_decimal_40);
  tcase_add_test(tc, s21_from_int_to_decimal_41);

  suite_add_tcase(s, tc);
  return s;
}
