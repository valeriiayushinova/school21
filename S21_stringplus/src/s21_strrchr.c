#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_occurrence = s21_NULL;
  unsigned char ch = (unsigned char)c;
  int flag = 0;
  while (*str != '\0') {
    if (*str == ch) {
      last_occurrence = str;
    }
    str++;
  }

  if (ch == '\0') {
    flag = 1;
  }

  return flag ? (char *)str : (char *)last_occurrence;
}