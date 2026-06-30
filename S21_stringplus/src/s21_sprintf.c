#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  flags flag = {0};
  va_list valist;
  va_start(valist, format);
  char *start_of_str = str;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&flag, 0, sizeof(flags));
    }

    format = get_flag(format, &flag);
    format = get_width(format, &flag, valist);
    format = get_accuracy(format, &flag, valist);
    format = get_length(format, &flag);

    flag.specifier = *format;
    format++;

    char buffer[1024] = {'\0'};
    process_val(flag, buffer, valist);
    for (int i = 0; buffer[i]; i++, str++) *str = buffer[i];

    if (flag.specifier == 'n') {
      int *quantity_char = va_arg(valist, int *);
      *quantity_char = str - start_of_str;
    }
  }

  *str = '\0';
  va_end(valist);
  return str - start_of_str;
}

const char *get_flag(const char *format, flags *flag) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '-':
        flag->minus = 1;
        break;
      case '+':
        flag->plus = 1;
        break;
      case '0':
        flag->zero = 1;
        break;
      case ' ':
        flag->space = 1;
        break;
      case '#':
        flag->hash = 1;
        break;
    }
    format++;
  }
  return format;
}

const char *get_width(const char *format, flags *flag, va_list valist) {
  if (*format == '*') {
    format++;
    flag->width = va_arg(valist, int);
  } else if (s21_isdigit(*format)) {
    char current[1024] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) current[i] = *format;
    flag->width = s21_atoi(current);
  }
  return format;
}

const char *get_accuracy(const char *format, flags *flag, va_list valist) {
  if (*format == '.') {
    flag->is_accuracy_set = 1;
    format++;
  }

  if (*format == '*') {
    format++;
    flag->accuracy = va_arg(valist, int);
  }
  if (s21_isdigit(*format)) {
    char current[1024] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) current[i] = *format;
    flag->accuracy = s21_atoi(current);
  }
  return format;
}

const char *get_length(const char *format, flags *flag) {
  switch (*format) {
    case 'h':
      flag->length = 'h';
      format++;
      break;
    case 'l':
      flag->length = 'l';
      format++;
      break;
    case 'L':
      flag->length = 'L';
      format++;
  }
  return format;
}

void process_val(flags flag, char *buffer, va_list valist) {
  if (flag.specifier == 'd' || flag.specifier == 'i')
    parse_int(flag, buffer, valist);
  else if (flag.specifier == 'o')
    parse_octal_num(flag, buffer, valist);
  else if (flag.specifier == 'x' || flag.specifier == 'X')
    parse_hexadecimal_num(flag, buffer, valist);
  else if (flag.specifier == 'u')
    parse_unsigned(flag, buffer, valist);
  else if (flag.specifier == 'c')
    parse_char(flag, buffer, valist);
  else if (flag.specifier == 's')
    parse_string(flag, buffer, valist);
  else if (flag.specifier == 'f')
    parse_float(flag, buffer, valist);
  else if (flag.specifier == 'p')
    parse_pointer(flag, buffer, valist);
  else if (flag.specifier == 'e' || flag.specifier == 'E')
    parse_exponent(flag, buffer, valist);
  else if (flag.specifier == 'g' || flag.specifier == 'G')
    parse_shortest_float(flag, buffer, valist);
  else if (flag.specifier == '%')
    buffer[0] = '%';
  if (flag.specifier == 'G' || flag.specifier == 'E' || flag.specifier == 'X')
    to_upper(buffer);
}

void parse_int(flags flag, char *buffer, va_list valist) {
  int64_t value = va_arg(valist, int64_t);

  switch (flag.length) {
    case 0:
      value = (int32_t)value;
      break;
    case 'h':
      value = (int16_t)value;
  }
  integer_to_str(value, buffer, 10);
  option_accuracy(buffer, flag);
  option_flags(buffer, flag);
}

void integer_to_str(int64_t value, char *num_to_str, int system) {
  char current[1024] = {'\0'};
  int idex = 1024 - 2;

  int negative_num = value < 0 ? 1 : 0;
  value = negative_num ? -value : value;

  if (value == 0) current[idex] = '0';

  while (value > 0) {
    idex--;
    current[idex] = "0123456789abcdef"[value % system];
    value /= system;
  }
  for (int j = 0; current[idex]; idex++, j++) {
    if (negative_num && j == 0) {
      num_to_str[j++] = '-';
    }

    num_to_str[j] = current[idex];
  }
}

void option_accuracy(char *buffer, flags flag) {
  char current[1024] = {'\0'};

  int minus = 0;
  int len = s21_strlen(buffer);

  if (buffer[0] == '-') {
    current[0] = '-';
    len--;
    minus = 1;
  }

  if (flag.accuracy > len) {
    int idex;
    for (idex = minus; idex < flag.accuracy - len + minus; idex++)
      current[idex] = '0';

    for (int i = minus; buffer[i]; i++, idex++) current[idex] = buffer[i];

    s21_strcpy(buffer, current);
  }

  if (flag.is_accuracy_set && flag.accuracy == 0 &&
      check_int_specifier(flag.specifier) && buffer[0] == '0')
    buffer[0] = '\0';
}

int check_int_specifier(char ch) {
  char specif[] = {'d', 'i', 'o', 'u', 'x', 'X'};
  int result = 0;
  for (s21_size_t i = 0; i < sizeof(specif) && result == 0; i++) {
    if (specif[i] == ch) {
      result = 1;
    }
  }
  return result;
}

void option_flags(char *buffer, flags flag) {
  char current[1024 + 1] = {'\0'};
  if (flag.plus && flag.specifier != 'u') {
    current[0] = buffer[0] == '-' ? buffer[0] : '+';
    s21_strcpy(current + 1, buffer[0] == '-' ? buffer + 1 : buffer);
    s21_strcpy(buffer, current);
  } else if (flag.space && buffer[0] != '-' && flag.specifier != 'u') {
    current[0] = ' ';
    s21_strcpy(current + 1, buffer);
    s21_strcpy(buffer, current);
  }
  if (flag.width > (int)s21_strlen(buffer)) {
    int idex = flag.width - s21_strlen(buffer);
    if (!flag.minus) {
      s21_memset(current, flag.zero ? '0' : ' ', idex);
      s21_strcpy(current + idex, buffer);
    } else {
      s21_strcpy(current, buffer);
      s21_memset(current + s21_strlen(current), ' ', idex);
    }
    s21_strcpy(buffer, current);
  }
}

void parse_unsigned(flags flag, char *buffer, va_list valist) {
  uint64_t value = va_arg(valist, uint64_t);
  switch (flag.length) {
    case 'h':
      value = (uint16_t)value;
      break;
    case 'l':
      value = (uint64_t)value;
      break;
    case 0:
      value = (uint32_t)value;
  }
  unsigned_num_to_string(value, buffer, 10);
  option_accuracy(buffer, flag);
  option_flags(buffer, flag);
}

void unsigned_num_to_string(uint64_t value, char *num_to_str, int system) {
  char array[1024 + 1] = {'\0'};
  int idex = 1024 - 1;
  if (value == 0) {
    array[idex] = '0';
    idex--;
  }

  for (; value && idex; --idex, value /= system)
    array[idex] = "0123456789abcdef"[value % system];
  for (int j = 0; array[idex + 1]; idex++, j++) num_to_str[j] = array[idex + 1];
}

void parse_octal_num(flags flag, char *buffer, va_list valist) {
  buffer[0] = '0';
  integer_to_str(va_arg(valist, int64_t), buffer + flag.hash, 8);
  option_accuracy(buffer, flag);
  option_flags(buffer, flag);
}

void to_upper(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') *str = *str - 'a' + 'A';
    str++;
  }
}

void parse_hexadecimal_num(flags flag, char *buffer, va_list valist) {
  uint64_t value = va_arg(valist, uint64_t);
  switch (flag.length) {
    case 0:
      value = (uint32_t)value;
      break;
    case 'h':
      value = (uint16_t)value;
      break;
    case 'l':
      value = (uint64_t)value;
      break;
  }
  unsigned_num_to_string(value, buffer, 16);
  option_accuracy(buffer, flag);
  if (flag.hash) {
    add_ox(buffer, flag);
  }
  option_flags(buffer, flag);
}

void add_ox(char *buffer, flags flag) {
  if (!all_zeros(buffer) || flag.specifier == 'p') {
    s21_memmove(buffer + 2, buffer, s21_strlen(buffer));
    buffer[0] = '0';
    buffer[1] = 'x';
  }
}

int all_zeros(char *buffer) {
  int flag_zero = 1;
  for (int i = 0; buffer[i]; i++)
    if (buffer[i] != '0') flag_zero = 0;
  return flag_zero;
}

void parse_char(flags flag, char *buffer, va_list valist) {
  if (flag.length == 'l') {
    wchar_t w_ch;
    w_ch = va_arg(valist, wchar_t);
    form_wchar(flag, buffer, w_ch);
  } else {
    char c;
    c = va_arg(valist, int);
    form_char(flag, buffer, c);
  }
}

void form_wchar(flags flag, char *buffer, wchar_t w_ch) {
  if (!flag.minus && flag.width) {
    char current[1024] = {'\0'};
    wcstombs(current, &w_ch, 1024);
    for (s21_size_t i = 0; i < flag.width - s21_strlen(current); i++)
      buffer[i] = ' ';
    s21_strcat(buffer, current);
  } else if (flag.width) {
    wcstombs(buffer, &w_ch, 1024);
    for (int i = s21_strlen(buffer); i < flag.width; i++) buffer[i] = ' ';
  } else {
    wcstombs(buffer, &w_ch, 1024);
  }
}
void form_char(flags flag, char *buffer, char ch) {
  if (!flag.minus && flag.width) {
    for (int i = 0; i < flag.width; i++) {
      buffer[i] = ' ';
      if (i == flag.width - 1) buffer[i] = ch;
    }
  } else if (flag.width) {
    buffer[0] = ch;
    for (int i = 1; i < flag.width; i++) buffer[i] = ' ';
  } else {
    buffer[0] = ch;
  }
}

void parse_string(flags flag, char *buffer, va_list valist) {
  if (flag.length == 'l') {
    wchar_t *w_str = va_arg(valist, wchar_t *);
    format_w_str(flag, buffer, w_str);
  } else {
    char *str = va_arg(valist, char *);
    format_str(flag, buffer, str);
  }
}
void format_str(flags flag, char *buffer, char *str) {
  char current[1024] = {'\0'};
  s21_strcpy(current, str);
  if (flag.is_accuracy_set) current[flag.accuracy] = '\0';

  int spaces = flag.width - s21_strlen(current);
  int len = s21_strlen(current);

  if (flag.minus && spaces > 0) {
    s21_strcpy(buffer, current);
    s21_memset(buffer + len, ' ', spaces);
  } else if (spaces > 0) {
    s21_memset(buffer, ' ', spaces);
    s21_strcpy(buffer + spaces, current);
  } else {
    s21_strcpy(buffer, current);
  }
}

void format_w_str(flags flag, char *buffer, wchar_t *w_str) {
  char current[1024] = {'\0'};
  char str[1024] = {'\0'};

  wcstombs(str, w_str, 1024);
  s21_strcpy(current, str);
  if (flag.is_accuracy_set) current[flag.accuracy] = '\0';

  int spaces = flag.width - s21_strlen(current);
  int len = s21_strlen(current);

  if (flag.minus && spaces > 0) {
    s21_strcpy(buffer, current);
    s21_memset(buffer + len, ' ', spaces);
  } else if (spaces > 0) {
    s21_memset(buffer, ' ', spaces);
    s21_strcpy(buffer + spaces, current);
  } else {
    s21_strcpy(buffer, current);
  }
}

void parse_pointer(flags flag, char *buffer, va_list valist) {
  unsigned_num_to_string(va_arg(valist, uint64_t), buffer, 16);
  option_accuracy(buffer, flag);
  add_ox(buffer, flag);
  option_flags(buffer, flag);
}

void parse_float(flags flag, char *buffer, va_list valist) {
  long double value = 0;
  if (flag.length == 'L') {
    value = va_arg(valist, long double);
  } else {
    value = va_arg(valist, double);
  }

  if (!flag.is_accuracy_set) {
    flag.accuracy = 6;
  }

  l_double_to_str(value, buffer, flag);
  option_flags(buffer, flag);
}
void l_double_to_str(long double value, char *num_to_str, flags flag) {
  char buffer[1024] = {'\0'};
  int idex = 1024 - 2;
  int negative_num = value < 0 ? 1 : 0;
  value = negative_num ? value * -1 : value;
  long double integer_part = 0, fractional_part = modfl(value, &integer_part);
  if (flag.accuracy == 0) {
    integer_part = roundl(value);
    fractional_part = 0;
  }
  char fractional_part_to_str[1024] = {'\0'};
  for (int i = 0; i < flag.accuracy; i++) {
    fractional_part = fractional_part * 10;
    fractional_part_to_str[i] = (int)fractional_part + '0';
  }
  long long right = roundl(fractional_part), left = integer_part;
  if (!right) {
    for (int i = 0; i < flag.accuracy; idex--, i++) buffer[idex] = '0';
  } else {
    for (int i = s21_strlen(fractional_part_to_str); right || i > 0;
         right /= 10, idex--, i--)
      buffer[idex] = (int)(right % 10 + 0.05) + '0';
  }
  if ((flag.is_accuracy_set && flag.accuracy != 0) || (int)fractional_part ||
      (!flag.is_accuracy_set && value == 0) ||
      s21_strlen(fractional_part_to_str))
    buffer[idex--] = '.';
  if (!left) {
    buffer[idex] = '0';
    idex--;
  } else {
    for (; left; left /= 10, idex--) buffer[idex] = (int)(left % 10) + '0';
  }
  for (int i = 0; buffer[idex + 1]; idex++, i++) {
    if (negative_num && i == 0) {
      num_to_str[i] = '-';
      i++;
    }
    num_to_str[i] = buffer[idex + 1];
  }
}

void parse_exponent(flags flag, char *buffer, va_list valist) {
  long double value = 0;
  if (flag.length == 'L') {
    value = va_arg(valist, long double);
  } else {
    value = va_arg(valist, double);
  }
  int power = 0;
  char sign = (int)value == 0 ? '-' : '+';

  if ((int)value - value) {
    while ((int)value == 0) {
      power++;
      value *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)value / 10 != 0) {
    power++;
    value /= 10;
  }

  if (!flag.is_accuracy_set) flag.accuracy = 6;
  l_double_to_str(value, buffer, flag);
  add_exponent(buffer, power, sign);
  option_flags(buffer, flag);
}

void add_exponent(char *str, int power, char sign) {
  int len = s21_strlen(str);
  str[len] = 'e';
  str[len + 1] = sign;
  str[len + 3] = power % 10 + '0';
  power /= 10;
  str[len + 2] = power % 10 + '0';
  str[len + 4] = '\0';
}

void parse_shortest_float(flags flag, char *buffer, va_list valist) {
  long double value = 0;
  if (flag.length == 'L') {
    value = va_arg(valist, long double);
  } else {
    value = va_arg(valist, double);
  }

  if (!flag.is_accuracy_set) {
    flag.accuracy = 6;
  }
  if (flag.accuracy == 0) flag.accuracy = 1;
  int accuracy = flag.accuracy;
  long double m_value = value;
  int power = 0;
  if ((int)value - value) {
    while ((int)m_value == 0) {
      power++;
      m_value *= 10;
    }
  }
  if (power > 4) {
    flag.accuracy = 0;
    l_double_to_str(m_value, buffer, flag);
  } else {
    flag.accuracy = 10;
    l_double_to_str(value, buffer, flag);
  }
  form_g_G_accuracy(buffer, accuracy);
  if (power > 4) add_exponent(buffer, power, '-');
  remove_zeros_at_end(buffer);
  option_flags(buffer, flag);
}

void form_g_G_accuracy(char *buffer, int accuracy) {
  int sign_num = 0;
  s21_size_t len = s21_strlen(buffer);
  int no_zero = 0;
  int flag_accuracy = 0;
  for (s21_size_t i = 0; i < s21_strlen(buffer); i++) {
    if ((buffer[i] == '0' && !no_zero) || buffer[i] == '.') {
    } else {
      no_zero = 1;
    }
    if (s21_isdigit(buffer[i]) && no_zero) {
      sign_num++;
    }
    if (sign_num == accuracy && i + 1 < len && flag_accuracy == 0) {
      int next = buffer[i + 1] == '.' ? 2 : 1;
      buffer[i] =
          buffer[i + next] - '0' > 5 ? (char)(buffer[i] + 1) : buffer[i];
      buffer[i + 1] = '\0';
      flag_accuracy = 1;
    }
  }
}

void remove_zeros_at_end(char *buffer) {
  int len = s21_strlen(buffer);
  char *point = s21_strchr(buffer, '.');
  if (point) {
    for (int i = len - 1; buffer[i] != '.'; i--) {
      if (buffer[i] == '0')
        buffer[i] = '\0';
      else
        break;
    }
    if (point[1] == '\0') point[0] = '\0';
  }
}

int s21_isdigit(char ch) { return (ch >= '0' && ch <= '9'); }

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *src_m = (char *)src;
  char *dest_m = (char *)dest;

  char *current = (char *)malloc(sizeof(char) * n);

  if (current) {
    s21_memcpy(current, src_m, n);
    s21_memcpy(dest_m, current, n);
    free(current);
  }
  return dest;
}

char *s21_strcpy(char *dest, const char *src) {
  for (int i = 0; src[i]; i++) {
    dest[i] = src[i];
  }
  dest[s21_strlen(src)] = '\0';
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  int dest_len = s21_strlen(dest);
  int i = 0;
  for (; src[i]; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}