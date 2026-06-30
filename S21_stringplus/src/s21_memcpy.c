#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const unsigned char *src_p = (const unsigned char *)src;
  unsigned char *dest_p = (unsigned char *)dest;
  for (s21_size_t i = 0; i < n; i++) {
    dest_p[i] = src_p[i];
  }
  return dest;
}
