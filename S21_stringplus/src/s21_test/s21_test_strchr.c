#include "s21_test.h"

START_TEST(test_strchr_1) {
  ck_assert_str_eq(s21_strchr("koshka", 's'), strchr("koshka", 's'));
}
END_TEST

START_TEST(test_strchr_2) {
  char testStr[] = "koshka";
  ck_assert_pstr_eq(s21_strchr(testStr, 'n'), strchr(testStr, 'n'));
}
END_TEST

START_TEST(test_strchr_3) {
  ck_assert_str_eq(s21_strchr("koshkovod", 'o'), strchr("koshkovod", 'o'));
}
END_TEST

START_TEST(test_strchr_4) {
  ck_assert_pstr_eq(s21_strchr("", 'a'), strchr("", 'a'));
}
END_TEST

Suite *test_suite_strchr() {
  Suite *suite = suite_create("s21_strchr");
  TCase *tcase = tcase_create("s21_strchr_case");

  tcase_add_test(tcase, test_strchr_1);
  tcase_add_test(tcase, test_strchr_2);
  tcase_add_test(tcase, test_strchr_3);
  tcase_add_test(tcase, test_strchr_4);

  suite_add_tcase(suite, tcase);

  return suite;
}