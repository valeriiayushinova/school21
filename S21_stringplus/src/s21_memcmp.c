#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char unsigned *s1 = (const unsigned char *)str1;
  const char unsigned *s2 = (const unsigned char *)str2;
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (result == 0) {
      if (s1[i] != s2[i]) result = s1[i] - s2[i];
    }
  }
  return result;
}