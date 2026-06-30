#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (null_pointer(result) || negative_size(rows, columns)) {
    return INCORRECT_MATRIX;
  }

  int res = OK;

  result->matrix = (double **)calloc(rows + rows * columns, sizeof(double));
  if (result->matrix == NULL) {
    return INCORRECT_MATRIX;
  }

  double *start = (double *)(result->matrix + rows);

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = start + i * columns;
  }

  result->rows = rows;
  result->columns = columns;

  return res;
}