#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *h, *n;
  if (*needle == '\0') {
    return (char *)haystack;
  }
  for (h = haystack; *h != '\0'; h++) {
    for (n = needle; *h != '\0' && *n != '\0' && *h == *n; h++, n++) {
      if (*n == '\0') {
        return (char *)h - (n - needle);
      }
    }
    if (*n == '\0') {
      return (char *)h - (n - needle);
    }
    h = h - (n - needle);
  }
  return s21_NULL;
}