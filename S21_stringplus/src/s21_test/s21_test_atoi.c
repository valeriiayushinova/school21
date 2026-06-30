#include "s21_test.h"

START_TEST(s21_test_atoi_1) {
  char src[] = "1234567890";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(s21_test_atoi_2) {
  char src[] = "Hello!";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(s21_test_atoi_3) {
  char src[] = "88Hello!";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(s21_test_atoi_4) {
  char src[] = " 88Hello!";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(s21_test_atoi_5) {
  char src[] = "-88Hello!";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(s21_test_atoi_6) {
  char src[] = "+88Hello!";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(s21_test_atoi_7) {
  char src[] = "";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

Suite *test_suite_atoi(void) {
  Suite *suite = suite_create("s21_atoi");
  TCase *tcase = tcase_create("s21_atoi_case");

  tcase_add_test(tcase, s21_test_atoi_1);
  tcase_add_test(tcase, s21_test_atoi_2);
  tcase_add_test(tcase, s21_test_atoi_3);
  tcase_add_test(tcase, s21_test_atoi_4);
  tcase_add_test(tcase, s21_test_atoi_5);
  tcase_add_test(tcase, s21_test_atoi_6);
  tcase_add_test(tcase, s21_test_atoi_7);

  suite_add_tcase(suite, tcase);

  return suite;
}
