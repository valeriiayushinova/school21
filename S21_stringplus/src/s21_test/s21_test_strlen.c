#include "s21_test.h"

START_TEST(strlen1) {
  char string[14] = "hello potatoes";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen2) {
  char string[20] = "1=98";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen3) {
  char string[1] = "";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen4) {
  char string[50] = "This is a longer string for testing.";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

Suite *test_suite_strlen() {
  Suite *s1 = suite_create("s21_strlen");
  TCase *tc1_1 = tcase_create("Core");

  tcase_add_test(tc1_1, strlen1);
  tcase_add_test(tc1_1, strlen2);
  tcase_add_test(tc1_1, strlen3);
  tcase_add_test(tc1_1, strlen4);

  suite_add_tcase(s1, tc1_1);
  return s1;
}
