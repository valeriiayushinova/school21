#include "s21_test.h"

START_TEST(test_s21_strpbrk_1) {
  char str1[] = "Hello World";
  char str2[] = "aaaaaaaaaaaaah";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str1[] = "Hello World";
  char str2[] = "aaaaaaaaaaaH";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str1[] = "Hello World";
  char str2[] = "aaaaaaaaaa";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char str1[] = "Hello World";
  char str2[] = "Hello";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char str1[] = "";
  char str2[] = "Hello";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_7) {
  char str1[] = "Hello";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_8) {
  char str1[] = "Hello World";
  char str2[] = "I'll love you always";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *test_suite_strpbrk() {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_1);
  tcase_add_test(tc_core, test_s21_strpbrk_2);
  tcase_add_test(tc_core, test_s21_strpbrk_3);
  tcase_add_test(tc_core, test_s21_strpbrk_4);
  tcase_add_test(tc_core, test_s21_strpbrk_5);
  tcase_add_test(tc_core, test_s21_strpbrk_6);
  tcase_add_test(tc_core, test_s21_strpbrk_7);
  tcase_add_test(tc_core, test_s21_strpbrk_8);

  suite_add_tcase(s, tc_core);

  return s;
}