#include "test_main.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_initialize_matrix(&A, 1, 2);
  s21_initialize_matrix(&B, 1, 2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_initialize_matrix(&A, 1, 2);
  s21_initialize_matrix(&B, 1, 3);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_initialize_matrix(&A, 1, 2);
  s21_initialize_matrix(&B, 1, 2);
  B.matrix[1][1] += 1e-7;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_EQ_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s21_eq_matrix_tc");
  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);
  tcase_add_test(tc, s21_eq_matrix_5);
  suite_add_tcase(s, tc);
  return s;
}