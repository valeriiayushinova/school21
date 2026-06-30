#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (null_pointer(A) || A->matrix == NULL || null_pointer(result)) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns || inf_or_nan(A)) {
    return CALCULATION_ERROR;
  }
  int res = OK;
  double determinant = 0.;
  s21_determinant(A, &determinant);
  if (determinant) {
    matrix_t complements, transpose;
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);
    s21_mult_number(&transpose, 1 / determinant, result);
    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  } else {
    res = CALCULATION_ERROR;
  }
  return res;
}