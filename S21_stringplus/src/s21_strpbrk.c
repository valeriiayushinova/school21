#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *p1;
  const char *p2;
  char *answer;
  int flag = 0;
  for (p1 = str1; *p1 != '\0'; p1++) {
    for (p2 = str2; *p2 != '\0'; p2++) {
      if (*p1 == *p2 && flag != 1) {
        answer = (char *)p1;
        flag = 1;
      }
    }
  }
  return flag ? answer : s21_NULL;
}