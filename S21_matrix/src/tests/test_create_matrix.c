#include "test_main.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(-4, 4, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(4, 0, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_CREATE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s21_create_matrix_tc");
  tcase_add_test(tc, s21_create_matrix_1);
  tcase_add_test(tc, s21_create_matrix_2);
  tcase_add_test(tc, s21_create_matrix_3);
  suite_add_tcase(s, tc);
  return s;
}