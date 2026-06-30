#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = s21_NULL;
  char *token_start;
  int flag = 0;

  if (str != s21_NULL) {
    last_token = str;
  }
  while (*last_token != '\0' && s21_strchr(delim, *last_token) != s21_NULL) {
    last_token++;
  }

  if (*last_token == '\0') flag = 1;

  token_start = last_token;
  while (*last_token != '\0' && s21_strchr(delim, *last_token) == s21_NULL) {
    last_token++;
  }

  return flag ? s21_NULL : token_start;
}