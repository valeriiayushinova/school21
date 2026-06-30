#include "s21_string.h"

char *s21_strerror(int errnum) {
  static const char *error_messages[] = ERROR_MESSAGES;
  char *result;
  s21_size_t num_errors = sizeof(error_messages) / sizeof(error_messages[0]);
  if ((long unsigned int)errnum >= num_errors) {
    static char result_unkn_err[100] = {0};

#ifdef __APPLE__
    s21_sprintf(result_unkn_err, "Unknown error: %d", errnum);
#elif defined(__linux__)
    s21_sprintf(result_unkn_err, "Unknown error %d", errnum);
#endif

    result = result_unkn_err;
  } else
    result = (char *)error_messages[errnum];

  return result;
}