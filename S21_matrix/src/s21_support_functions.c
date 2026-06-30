#include "s21_matrix.h"

int negative_size(int rows, int columns) { return rows <= 0 || columns <= 0; }

int null_pointer(matrix_t *A) { return A == NULL; }

int equal_size(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

int inf_or_nan(matrix_t *A) {
  int res = OK;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        res = CALCULATION_ERROR;
        j = A->columns;
        i = A->rows;
      }
    }
  }
  return res;
}

int size_of_mult(matrix_t *A, matrix_t *B) { return A->columns == B->rows; }

void record_determinant(matrix_t *A, int minor_rows, int minor_columns,
                        matrix_t *determinant) {
  for (int src_row = 0, det_rows = 0; src_row < A->rows; src_row++) {
    for (int src_column = 0, det_columns = 0; src_column < A->columns;
         src_column++) {
      if (src_row != minor_rows && src_column != minor_columns) {
        determinant->matrix[det_rows][det_columns] =
            A->matrix[src_row][src_column];
        det_columns++;
        if (det_columns == determinant->columns) {
          det_columns = 0;
          det_rows++;
        }
      }
    }
  }
}

void algebraic_complements(matrix_t *A, matrix_t *result) {
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      if ((m + n) % 2) {
        result->matrix[m][n] *= -1;
      }
    }
  }
}

void s21_initialize_matrix(matrix_t *A, double first_value,
                           double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = first_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}