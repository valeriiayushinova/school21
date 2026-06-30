#include "s21_test.h"

START_TEST(test_s21_trim_normal) {
  char *src = "   Hello potatoes   ";
  char *trim_chars = " ";
  char *expected = "Hello potatoes";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_leading_and_trailing) {
  char *src = "###Hello potatoes###";
  char *trim_chars = "#";
  char *expected = "Hello potatoes";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_all_trimmed) {
  char *src = "   ";
  char *trim_chars = " ";
  char *expected = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_null_src) {
  char *src = s21_NULL;
  char *trim_chars = " ";
  ck_assert_ptr_eq(s21_trim(src, trim_chars), s21_NULL);
}
END_TEST

START_TEST(test_s21_trim_empty_trim_chars) {
  char *src = "   Hello potatoes   ";
  char *trim_chars = "";
  char *expected = "   Hello potatoes   ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_only_trim_chars) {
  char *src = "###";
  char *trim_chars = "#";
  char *expected = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *test_suite_trim() {
  Suite *s = suite_create("s21_trim");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_trim_normal);
  tcase_add_test(tc_core, test_s21_trim_leading_and_trailing);
  tcase_add_test(tc_core, test_s21_trim_all_trimmed);
  tcase_add_test(tc_core, test_s21_trim_null_src);
  tcase_add_test(tc_core, test_s21_trim_empty_trim_chars);
  tcase_add_test(tc_core, test_s21_trim_only_trim_chars);

  suite_add_tcase(s, tc_core);

  return s;
}
