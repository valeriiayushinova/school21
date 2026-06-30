#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (null_pointer(A) || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns || inf_or_nan(A)) {
    return CALCULATION_ERROR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  matrix_t determinant;

  if (A->rows > 1) {
    s21_create_matrix(A->rows - 1, A->columns - 1, &determinant);
  } else {
    result->matrix[0][0] = 1.;
  }

  for (int minor_rows = 0; minor_rows < A->rows && A->rows > 1; minor_rows++) {
    for (int minor_columns = 0; minor_columns < A->columns; minor_columns++) {
      record_determinant(A, minor_rows, minor_columns, &determinant);
      s21_determinant(&determinant, &result->matrix[minor_rows][minor_columns]);
    }
  }

  if (A->rows > 1) {
    s21_remove_matrix(&determinant);
    algebraic_complements(A, result);
  }
  return OK;
}