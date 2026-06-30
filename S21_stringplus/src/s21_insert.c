#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  s21_size_t whole_len = src_len + str_len;

  if (!src || !str) {
    return s21_NULL;
  } else if (start_index > src_len) {
    return s21_NULL;
  } else {
    char *result_str = (char *)malloc((whole_len + 1) * sizeof(char));
    s21_size_t i;
    s21_size_t j;
    s21_size_t pos = 0;

    for (i = 0; i < src_len; i++) {
      if (i == start_index) {
        for (j = 0; j < str_len; j++) {
          result_str[pos++] = str[j];
        }
      }

      result_str[pos++] = src[i];
    }

    if (start_index == src_len) {
      for (j = 0; j < str_len; j++) {
        result_str[pos++] = str[j];
      }
    }

    result_str[whole_len] = '\0';
    return (void *)result_str;
  }
}
