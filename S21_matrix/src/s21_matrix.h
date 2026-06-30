#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

enum result_code { OK = 0, INCORRECT_MATRIX = 1, CALCULATION_ERROR = 2 };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int negative_size(int rows, int columns);
int null_pointer(matrix_t *A);
int equal_size(matrix_t *A, matrix_t *B);
int inf_or_nan(matrix_t *A);
int size_of_mult(matrix_t *A, matrix_t *B);
void record_determinant(matrix_t *A, int minor_rows, int minor_columns,
                        matrix_t *determinant);
void algebraic_complements(matrix_t *A, matrix_t *result);
void s21_initialize_matrix(matrix_t *A, double first_value,
                           double iteration_step);

#endif  // S21_MATRIX_H