#include "s21_test.h"

START_TEST(test_memcmp_1) {
  char* a = "catdogcat";
  ck_assert_int_eq(s21_memcmp("catdogcat", a, 10), memcmp("catdogcat", a, 10));
}
END_TEST

START_TEST(test_memcmp_2) {
  char* a = "catcd;dog";
  ck_assert_int_eq(s21_memcmp("cat!cd;dog", a, 10),
                   memcmp("cat!cd;dog", a, 10));
}
END_TEST

START_TEST(test_memcmp_3) {
  char* a = "vv";
  ck_assert_int_eq(s21_memcmp("av", a, 2), memcmp("av", a, 2));
}
END_TEST

START_TEST(test_memcmp_4) {
  char* a = "koala";
  ck_assert_int_eq(s21_memcmp("krug", a, 5), memcmp("krug", a, 5));
}
END_TEST

START_TEST(test_memcmp_5) {
  char* a = "";
  ck_assert_int_eq(s21_memcmp("", a, 1), memcmp("", a, 1));
}
END_TEST

START_TEST(test_memcmp_6) {
  char* a = "";
  ck_assert_int_eq(s21_memcmp("lol", a, 1), memcmp("lol", a, 1));
}
END_TEST

START_TEST(test_memcmp_7) {
  char* a = "";
  ck_assert_int_eq(s21_memcmp(a, "lol", 1), memcmp(a, "lol", 1));
}
END_TEST

START_TEST(test_memcmp_8) {
  int str1[] = {48, 49, 2, 3, 4, 5, 6, 7, 8, 9};
  int str2[] = {48, 49, 2, 3, 4, 5, 6, 7, 8, 9};
  ck_assert_int_eq(s21_memcmp(str1, str2, 9), memcmp(str1, str2, 9));
}
END_TEST

START_TEST(test_memcmp_9) {
  int str1[] = {48, 49, 2, 27, 4, 5, 6, 7, 8, 9};
  int str2[] = {48, 49, 2, 3, 4, 5, 6, 7, 8, 9};
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
}
END_TEST

START_TEST(test_memcmp_10) {
  int str1[] = {48, 49, 2, 3, 4, 5, 6, 7, 8, 9};
  int str2[] = {48, 49, 2, 3, 99, 5, 6, 7, 8, 9};
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
}
END_TEST

Suite* test_suite_memcmp() {
  Suite* suite = suite_create("s21_memcmp");
  TCase* tcase = tcase_create("s21_memcmp_case");

  tcase_add_test(tcase, test_memcmp_1);
  tcase_add_test(tcase, test_memcmp_2);
  tcase_add_test(tcase, test_memcmp_3);
  tcase_add_test(tcase, test_memcmp_4);
  tcase_add_test(tcase, test_memcmp_5);
  tcase_add_test(tcase, test_memcmp_6);
  tcase_add_test(tcase, test_memcmp_7);
  tcase_add_test(tcase, test_memcmp_8);
  tcase_add_test(tcase, test_memcmp_9);
  tcase_add_test(tcase, test_memcmp_10);

  suite_add_tcase(suite, tcase);

  return suite;
}