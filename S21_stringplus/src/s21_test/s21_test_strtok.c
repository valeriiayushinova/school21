#include "s21_test.h"

START_TEST(test_strtok_1) {
  char str[] = "12.48.01";
  const char delimeter[] = ".";

  char *res_lib1 = strtok(str, delimeter);
  char *my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
}
END_TEST

START_TEST(test_strtok_2) {
  char str[] = "Hello World";
  const char delimeter[] = " ?";

  char *res_lib1 = strtok(str, delimeter);
  char *my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
}
END_TEST

START_TEST(test_strtok_3) {
  char str[] =
      "Hi, baby! Let go of attachments and embrace the present moment.";
  const char delimeter[] = " ";

  char *res_lib1 = strtok(str, delimeter);
  char *my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
  res_lib1 = strtok(str, delimeter);
  my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
  res_lib1 = strtok(str, delimeter);
  my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
}
END_TEST

START_TEST(test_strtok_4) {
  char str[] = "\'\\0\'";
  const char delimeter[] = ".";

  char *res_lib1 = strtok(str, delimeter);
  char *my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
}
END_TEST

START_TEST(test_strtok_5) {
  char str[] = "Hello ? World ? CRAZY ? ";
  const char delimeter[] = " ?";

  char *res_lib1 = strtok(str, delimeter);
  char *my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
}
END_TEST

START_TEST(test_strtok_6) {
  char str[] = " DELIMETR   - SPACE    ";
  const char delimeter[] = " ";

  char *res_lib1 = strtok(str, delimeter);
  char *my_res1 = s21_strtok(str, delimeter);
  ck_assert_str_eq(my_res1, res_lib1);
}
END_TEST

Suite *test_suite_strtok() {
  Suite *suite = suite_create("s21_strtok");
  TCase *tcase = tcase_create("s21_strtok_case");

  tcase_add_test(tcase, test_strtok_1);
  tcase_add_test(tcase, test_strtok_2);
  tcase_add_test(tcase, test_strtok_3);
  tcase_add_test(tcase, test_strtok_4);
  tcase_add_test(tcase, test_strtok_5);
  tcase_add_test(tcase, test_strtok_6);
  suite_add_tcase(suite, tcase);

  return suite;
}