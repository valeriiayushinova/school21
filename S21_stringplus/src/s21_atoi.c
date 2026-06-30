#include "s21_string.h"

int s21_atoi(const char *str) {
  int answer = 0;
  int mark = 1;

  while (*str == ' ') str++;

  if (*str == '-') {
    str++;
    mark = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && *str >= '0' && *str <= '9') {
    answer = answer * 10 + (*str - '0');
    str++;
  }
  answer *= mark;
  return answer;
}
