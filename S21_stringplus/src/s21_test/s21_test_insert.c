#include "s21_test.h"

START_TEST(test_s21_insert_1) {
  char str1[] = "HOHOHO ";
  char str2[] = "potatoes make the project";
  s21_size_t index = 18;
  char expected[] = "potatoes make the HOHOHO project";
  char *got = (char *)s21_insert(str2, str1, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char str1[] = "HOHOHO, ";
  char str2[] = "HAHAHA potatoes make the project";
  s21_size_t index = 0;
  char expected[] = "HOHOHO, HAHAHA potatoes make the project";
  char *got = (char *)s21_insert(str2, str1, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t index = 0;
  char *expected = "";
  char *got = (char *)s21_insert(str2, str1, index);
  ck_assert_pstr_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char *str2 = s21_NULL;
  char *str1 = s21_NULL;
  s21_size_t index = 0;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(str2, str1, index);
  ck_assert_ptr_eq(got, expected);
  free(got);
}
END_TEST
START_TEST(test_s21_insert_5) {
  char str1[] = "Potatoes";
  char str2[] = "HOHOHO ";
  s21_size_t index = 7;
  char expected[] = "HOHOHO Potatoes";
  char *got = (char *)s21_insert(str2, str1, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(test_s21_insert_6) {
  char str1[] = "HOHOHO";
  char str2[] = "HAHAHA";
  s21_size_t index = 4;
  char expected[] = "HAHAHOHOHOHA";
  char *got = (char *)s21_insert(str2, str1, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST
START_TEST(insert_str_null) {
  char *str1 = s21_NULL;
  char str2[] = "potatoes  ";
  s21_size_t index = 6;
  void *expected = s21_NULL;
  char *got = (char *)s21_insert(str2, str1, index);
  ck_assert_pstr_eq(got, expected);
  free(got);
}
END_TEST

Suite *test_suite_insert() {
  Suite *s = suite_create("s21_insert");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_insert_1);
  tcase_add_test(tc_core, test_s21_insert_2);
  tcase_add_test(tc_core, test_s21_insert_3);
  tcase_add_test(tc_core, test_s21_insert_4);
  tcase_add_test(tc_core, test_s21_insert_5);
  tcase_add_test(tc_core, test_s21_insert_6);
  tcase_add_test(tc_core, insert_str_null);

  suite_add_tcase(s, tc_core);

  return s;
}