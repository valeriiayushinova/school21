#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char ch = (char)c;
  char *result = s21_NULL;
  int flag = 0;
  while (*str != '\0') {
    if (*str == ch && flag == 0) {
      result = (char *)str;
      flag = 1;
    }
    str++;
  }
  return result;
}
