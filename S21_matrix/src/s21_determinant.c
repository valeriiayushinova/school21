#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (null_pointer(A) || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns || inf_or_nan(A)) {
    return CALCULATION_ERROR;
  }
  matrix_t A_copy;
  s21_create_matrix(A->rows, A->columns, &A_copy);

  for (int i = 0; i < A_copy.rows; i++) {
    for (int k = 0; k < A_copy.columns; k++) {
      A_copy.matrix[i][k] = A->matrix[i][k];
    }
  }
  int not_zero = 0, all_zero = 1, sign = 1;
  double *temp = NULL;
  *result = 1.;
  for (int rows = 0; rows < A_copy.rows - 1 && *result; rows++) {
    for (not_zero = rows, all_zero = 1; not_zero < A_copy.rows; not_zero++) {
      if (A_copy.matrix[not_zero][rows] != 0) {
        temp = A_copy.matrix[not_zero];
        all_zero = 0;
        break;
      }
    }

    if (A_copy.matrix[rows][rows] == 0. && temp) {
      A_copy.matrix[not_zero] = A_copy.matrix[rows];
      A_copy.matrix[rows] = temp;
      sign *= -1;
    }

    if (all_zero) {
      *result = 0.;
    } else {
      for (int m = rows + 1; m < A_copy.rows; m++) {
        double temp = A_copy.matrix[m][rows] / A_copy.matrix[rows][rows];

        for (int n = rows; n < A_copy.columns; n++) {
          A_copy.matrix[m][n] -= temp * A_copy.matrix[rows][n];
        }
      }
    }
  }
  for (int k = 0; k < A_copy.rows; k++) {
    *result *= A_copy.matrix[k][k];
  }
  *result *= sign;
  s21_remove_matrix(&A_copy);
  return OK;
}