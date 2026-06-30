#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *p = str;
  int flag = 0;
  for (long unsigned i = 0; flag == 0 && i < n; i++) {
    if (p[i] == c) {
      if (c != '\0') {
        p += i;
        flag = 1;
      }
    }
  }
  return flag ? (void *)p : s21_NULL;
}