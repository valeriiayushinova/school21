#include "s21_test.h"

START_TEST(test_strncpy_1) {
  char d1[] = "HELL0 World";
  char s1[] = "12389983";
  char d2[] = "HELL0 World";
  char s2[] = "12389983";
  strncpy(d1, s1, 11);
  s21_strncpy(d2, s2, 11);
  ck_assert_pstr_eq(d1, d2);
}
END_TEST

START_TEST(test_strncpy_2) {
  char d1[] = "potatoes";
  char s1[] = "00000000000";
  char d2[] = "potatoes";
  char s2[] = "00000000000";
  strncpy(d1, s1, 8);
  s21_strncpy(d2, s2, 8);
  ck_assert_pstr_eq(d1, d2);
}
END_TEST

START_TEST(test_strncpy_3) {
  char d1[] = "\0";
  char s1[] = "strncpy";
  char d2[] = "\0";
  char s2[] = "strncpy";
  strncpy(d1, s1, 1);
  s21_strncpy(d2, s2, 1);
  ck_assert_pstr_eq(d1, d2);
}
END_TEST

START_TEST(test_strncpy_4) {
  char d1[] = "strncpy";
  char s1[] = "\0";
  char d2[] = "strncpy";
  char s2[] = "\0";
  strncpy(d1, s1, 2);
  s21_strncpy(d2, s2, 2);
  ck_assert_pstr_eq(d1, d2);
}
END_TEST

START_TEST(test_strncpy_5) {
  char d1[] = "cats";
  char s1[] = "";
  char d2[] = "cats";
  char s2[] = "";
  strncpy(d1, s1, 4);
  s21_strncpy(d2, s2, 5);
  ck_assert_pstr_eq(d1, d2);
}
END_TEST

START_TEST(test_strncpy_6) {
  char d1[] = "";
  char s1[] = "";
  char d2[] = "";
  char s2[] = "";
  strncpy(d1, s1, 1);
  s21_strncpy(d2, s2, 1);
  ck_assert_pstr_eq(d1, d2);
}
END_TEST

Suite *test_suite_strncpy() {
  Suite *suite = suite_create("s21_strncpy");
  TCase *tcase = tcase_create("s21_strncpy_case");

  tcase_add_test(tcase, test_strncpy_1);
  tcase_add_test(tcase, test_strncpy_2);
  tcase_add_test(tcase, test_strncpy_3);
  tcase_add_test(tcase, test_strncpy_4);
  tcase_add_test(tcase, test_strncpy_5);
  tcase_add_test(tcase, test_strncpy_6);

  suite_add_tcase(suite, tcase);

  return suite;
}