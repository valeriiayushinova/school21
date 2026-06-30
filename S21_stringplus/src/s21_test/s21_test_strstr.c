#include "s21_test.h"

START_TEST(test_strstr_1) {
  char str1[] = "potatoes make the project";
  char str2[] = "pot";
  char *ptr1 = 0;

  char str11[] = "potatoes make the project";
  char str22[] = "pot";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_2) {
  char str1[] = "Hello Crazy CRAZY World";
  char str2[] = "Hello";
  char *ptr1 = 0;

  char str11[] = "Hello Crazy CRAZY World";
  char str22[] = "Hello";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_3) {
  char str1[] = "333333333333331";
  char str2[] = "1";
  char *ptr1 = 0;

  char str11[] = "333333333333331";
  char str22[] = "1";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_4) {
  char str1[] = "";
  char str2[] = "0";
  char *ptr1 = 0;

  char str11[] = "";
  char str22[] = "0";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_5) {
  char str1[] = "potatoes make the project";
  char str2[] = "";
  char *ptr1 = 0;

  char str11[] = "potatoes make the project";
  char str22[] = "";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_6) {
  char str1[] = "";
  char str2[] = "";
  char *ptr1 = 0;

  char str11[] = "";
  char str22[] = "";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_7) {
  char str1[] = "Hello Crazy";
  char str2[] = "CRAZY";
  char *ptr1 = 0;

  char str11[] = "Hello Crazy";
  char str22[] = "CRAZY";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_8) {
  char str1[] = "popopopo";
  char str2[] = " ";
  char *ptr1 = 0;

  char str11[] = "popopopo";
  char str22[] = " ";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_9) {
  char str1[] = "popo popo";
  char str2[] = " ";
  char *ptr1 = 0;

  char str11[] = "popo popo";
  char str22[] = " ";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_10) {
  char str1[] = "potatoes make the project";
  char str2[] = " ";
  char *ptr1 = 0;

  char str11[] = "potatoes make the project";
  char str22[] = " ";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_strstr_11) {
  char str1[] = "   ";
  char str2[] = " ";
  char *ptr1 = 0;

  char str11[] = "   ";
  char str22[] = " ";
  char *ptr2 = 0;

  ptr1 = strstr(str1, str2);
  ptr2 = s21_strstr(str11, str22);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST

Suite *test_suite_strstr() {
  Suite *suite = suite_create("s21_strstr");
  TCase *tcase = tcase_create("s21_strstr_case");

  tcase_add_test(tcase, test_strstr_1);
  tcase_add_test(tcase, test_strstr_2);
  tcase_add_test(tcase, test_strstr_3);
  tcase_add_test(tcase, test_strstr_4);
  tcase_add_test(tcase, test_strstr_5);
  tcase_add_test(tcase, test_strstr_6);
  tcase_add_test(tcase, test_strstr_7);
  tcase_add_test(tcase, test_strstr_8);
  tcase_add_test(tcase, test_strstr_9);
  tcase_add_test(tcase, test_strstr_10);
  tcase_add_test(tcase, test_strstr_11);

  suite_add_tcase(suite, tcase);

  return suite;
}
