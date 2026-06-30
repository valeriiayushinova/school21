#include "s21_test.h"

START_TEST(test_strerror_1) { ck_assert_pstr_eq(s21_strerror(1), strerror(1)); }
END_TEST

START_TEST(test_strerror_2) { ck_assert_pstr_eq(s21_strerror(0), strerror(0)); }
END_TEST

START_TEST(test_strerror_3) {
  ck_assert_pstr_eq(s21_strerror(88888), strerror(88888));
}
END_TEST

START_TEST(test_strerror_4) {
  ck_assert_pstr_eq(s21_strerror(-10), strerror(-10));
}
END_TEST

START_TEST(test_strerror_5) {
  ck_assert_pstr_eq(s21_strerror(89), strerror(89));
}
END_TEST

Suite *test_suite_strerror() {
  Suite *suite = suite_create("s21_strerror");
  TCase *tcase = tcase_create("s21_strerror_case");

  tcase_add_test(tcase, test_strerror_1);
  tcase_add_test(tcase, test_strerror_2);
  tcase_add_test(tcase, test_strerror_3);
  tcase_add_test(tcase, test_strerror_4);
  tcase_add_test(tcase, test_strerror_5);

  suite_add_tcase(suite, tcase);

  return suite;
}