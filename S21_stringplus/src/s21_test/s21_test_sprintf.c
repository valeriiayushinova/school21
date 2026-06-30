#include "s21_test.h"

START_TEST(only_int) {
  char str1[1024];
  char str2[1024];

  char *format = "hihi potatoes %d";
  int val = 52;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(accurate_int) {
  char str1[1024];
  char str2[1024];

  char *format = "%.4i";
  int val = 52;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[1024];
  char str2[1024];

  char *format = "%5d";
  int val = 70;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[1024];
  char str2[1024];

  char *format = "%-4i";
  int val = 52;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[1024];
  char str2[1024];

  char *format = "%+12d";
  int val = 78;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_width_int) {
  char str1[1024];
  char str2[1024];

  char *format = "%012i";
  int val = 84;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_accur_long) {
  char str1[1024];
  char str2[1024];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_accur_short) {
  char str1[1024];
  char str2[1024];

  char *format = "%-16.8hi";
  short int val = 7456;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(accurate_zero_int) {
  char str1[1024];
  char str2[1024];
  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_int) {
  char str1[1024];
  char str2[1024];
  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(only_unsigned) {
  char str1[1024];
  char str2[1024];
  char *format = "%u";
  unsigned int val = 17684;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_unsigned) {
  char str1[1024];
  char str2[1024];

  char *format = "%13u";
  unsigned int val = 15678;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_unsigned) {
  char str1[1024];
  char str2[1024];

  char *format = "%-16u";
  unsigned int val = 12330;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(accurate_unsigned) {
  char str1[1024];
  char str2[1024];

  char *format = "%.47u";
  unsigned int val = 12457;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(space_accur_width_unsigned) {
  char str1[1024];
  char str2[1024];

  char *format = "% 4.47u";
  unsigned int val = 16759;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(short_unsigned) {
  char str1[1024];
  char str2[1024];

  char *format = "%hu";
  unsigned short int val = 11230;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(long_unsigned) {
  char str1[1024];
  char str2[1024];

  char *format = "%lu";
  unsigned long int val = 7676895904;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_width) {
  char str1[1024];
  char str2[1024];

  char *format = "%18o";
  int val = 12456;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_octal) {
  char str1[1024];
  char str2[1024];

  char *format = "%-13o";
  int val = 17560;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(accurate_octal) {
  char str1[1024];
  char str2[1024];

  char *format = "%.47o";
  int val = 16540;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_accur_oct) {
  char str1[1024];
  char str2[1024];

  char *format = "%-6.44o";
  int val = 146760;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(only_octal) {
  char str1[1024];
  char str2[1024];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hash_octal) {
  char str1[1024];
  char str2[1024];

  char *format = "%#o";
  int val = 56573;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(short_octal) {
  char str1[1024];
  char str2[1024];

  char *format = "%hd";
  short int val = 15670;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(long_octal) {
  char str1[1024];
  char str2[1024];

  char *format = "%lo";
  long int val = 6538539508;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(long_octal2) {
  char str1[1024];
  char str2[1024];

  char *format = "%lo";
  long int val = 84568;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(just_unsigned) {
  char str1[1024];
  char str2[1024];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%5x";
  unsigned val = 5758590;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hash_min_width_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%#-12x";
  unsigned val = 989789770;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(accurate_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_many_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 87970098;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hash_width_accur_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%#-5.10x";
  unsigned val = 45586909;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hash_hex_zero) {
  char str1[1024];
  char str2[1024];
  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_hash) {
  char str1[1024];
  char str2[1024];
  char *format = "%#x";
  unsigned val = 16786;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(short_hex) {
  char str1[1024];
  char str2[1024];
  char *format = "%#hx";
  unsigned short val = 17979;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hash_long_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%#lx";
  unsigned long val = 86869606060;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hash_width_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hash_longwidth_hex) {
  char str1[1024];
  char str2[1024];

  char *format = "%#31x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(only_char) {
  char str1[1024];
  char str2[1024];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(accurate_char) {
  char str1[1024];
  char str2[1024];

  char *format = "%.6c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_char) {
  char str1[1024];
  char str2[1024];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char) {
  char str1[1024];
  char str2[1024];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(min_width_accur_char) {
  char str1[1024];
  char str2[1024];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[1024];
  char str2[1024];

  char *format = "%s";
  char *val = "HELLO potatoes";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_accurate) {
  char str1[1024];
  char str2[1024];

  char *format = "%.11s";
  char *val = "HELLO potatoes";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width) {
  char str1[1024];
  char str2[1024];

  char *format = "%15s";
  char *val = "WE are doing a project";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(min_width_accur_str) {
  char str1[1024];
  char str2[1024];

  char *format = "%-16.8s";
  char *val = "MY PROJECT";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(only_long_str) {
  char str1[1024];
  char str2[1024];

  char *format = "%s";
  char *val =
      "WE LOVE IT WE WILL BE PROGRAMMERS WE LOVE SCHOOL 21 DO YOU LOVE IT";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(only_pointer) {
  char str1[1024];
  char str2[1024];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(pointer_width) {
  char str1[1024];
  char str2[1024];

  char *format = "%14p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(pointer_accurate) {
  char str1[1024];
  char str2[1024];

  char *format = "%.3p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_high_width) {
  char str1[1024];
  char str2[1024];
  char *val = "meowmeowmeow";
  char *format = "%110s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specif_n) {
  char str1[1024];
  char str2[1024];
  int ret = 0;
  char *format = "Meow we love cats %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(l_float_accurate) {
  char str1[1024];
  char str2[1024];
  char *format = "%Lf";
  long double val = 456678.3454646809;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(l_float_width) {
  char str1[1024];
  char str2[1024];
  char *format = "%10Lf";
  long double val = 11.48;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(l_float_accurate_zero) {
  char str1[1024];
  char str2[1024];
  char *format = "%.0Lf";
  long double val = 11.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(l_float_accurate_empty) {
  char str1[1024];
  char str2[1024];
  char *format = "%.Lf";
  long double val = 19.05;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(l_float_high_accurate) {
  char str1[1024];
  char str2[1024];
  char *format = "%.15Lf";
  long double val = 15.67;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(l_float_high_accurate_negative) {
  char str1[1024];
  char str2[1024];
  char *format = "%.16Lf";
  long double val = -12.387665;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(l_float_high) {
  char str1[1024];
  char str2[1024];
  char *format = "%Lf";
  long double val = 76849440.7686869;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(space_float) {
  char str1[1024];
  char str2[1024];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(le_accurate_zero) {
  char str1[1024];
  char str2[1024];
  char *format = "%.0Le";
  long double val = 13.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(le_accurate) {
  char str1[1024];
  char str2[1024];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(le_accurate_high) {
  char str1[1024];
  char str2[1024];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(le_accurate_high_negative) {
  char str1[1024];
  char str2[1024];
  char *format = "%.15Le";
  long double val = -14.39988989;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(le_high) {
  char str1[1024];
  char str2[1024];
  char *format = "%Le";
  long double val = 6768008076.475869;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_specif) {
  char str1[1024];
  char str2[1024];
  char *format = "%011E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_width) {
  char str1[1024];
  char str2[1024];
  char *format = "%14e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(no_spec) {
  char str1[1024];
  char str2[1024];
  ck_assert_int_eq(s21_sprintf(str1, "nono"), sprintf(str2, "nono"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(no_specif) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "yes"), sprintf(str2, "yes"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_char) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_string) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Go to school"),
                   sprintf(str2, "%s", "Go to school"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_d_only) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 123), sprintf(str2, "%d", 123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_int_only) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -1), sprintf(str2, "%i", -1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_float_only) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0002),
                   sprintf(str2, "%f", 0.0002));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_unsign_only) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 103),
                   sprintf(str2, "%u", (unsigned)103));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_char_left) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%7c", '\t'), sprintf(str2, "%7c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_char_right) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%-7c", '\t'),
                   sprintf(str2, "%-7c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_low) {
  char str1[1024];
  char str2[1024];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_upp) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_low_left) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%-4x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-4x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-4x", 0), sprintf(str2, "%-4x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-4x", INT32_MAX),
                   sprintf(str2, "%-4x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_low_right) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_upp_left) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%-50X", INT32_MIN),
                   sprintf(str2, "%-50X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-50X", 0), sprintf(str2, "%-50X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-50X", INT32_MAX),
                   sprintf(str2, "%-50X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_upp_right) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%6X", (unsigned)INT32_MIN),
                   sprintf(str2, "%6X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%6X", 0), sprintf(str2, "%6X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%6X", INT32_MAX),
                   sprintf(str2, "%6X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_hash) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_upp_hash) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_low_len) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -12),
                   sprintf(str2, "%hx", (unsigned short)-12));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 12),
                   sprintf(str2, "%hx", (unsigned short)12));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_hex_upp_len) {
  char str1[1024];
  char str2[1024];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf1) {
  char str1[1024];
  char str2[1024];
  char format[] = "%9ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf2) {
  char str1[1024];
  char str2[1024];
  char format[] = "%1.2f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.2), sprintf(str2, format, 1.2));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf3) {
  char str1[1024];
  char str2[1024];
  char format[] = "%6.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'm'), sprintf(str2, format, 'm'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf4) {
  char str1[1024];
  char str2[1024];
  char format[] = "%+4.3d mimi";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf6) {
  char str1[1024];
  char str2[1024];
  char format[] = "%1.3f";

  ck_assert_int_eq(s21_sprintf(str1, format, 12.89097),
                   sprintf(str2, format, 12.89097));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf7) {
  char str1[1024];
  char str2[1024];
  char format[] = "%6.1s";

  ck_assert_int_eq(s21_sprintf(str1, format, "potatoes"),
                   sprintf(str2, format, "potatoes"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf8) {
  char str1[1024];
  char str2[1024];
  char format[] = "%8.1u";

  ck_assert_int_eq(s21_sprintf(str1, format, 132453579),
                   sprintf(str2, format, 132453579));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf16) {
  char str1[1024];
  char str2[1024];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'c'), sprintf(str2, format, 'c'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf17) {
  char str1[1024];
  char str2[1024];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "hello Moscow"),
                   sprintf(str2, format, "hello Moscow"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf19) {
  char str1[1024];
  char str2[1024];
  char format[] = "%170s";

  ck_assert_int_eq(s21_sprintf(str1, format, "wowowowow\0WOWOWOW"),
                   sprintf(str2, format, "wowowowow\0WOWOWOW"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf20) {
  char str1[1024];
  char str2[1024];
  char format[] = "%-103s";

  ck_assert_int_eq(s21_sprintf(str1, format, "dream team"),
                   sprintf(str2, format, "dream team"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf25) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 876.103),
                   sprintf(str2, format, 876.103));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf29) {
  char str1[1024];
  char str2[1024];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 222.101),
                   sprintf(str2, format, 222.101));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf30) {
  char str1[1024];
  char str2[1024];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 232), sprintf(str2, format, 232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf31) {
  char str1[1024];
  char str2[1024];
  char format[] = "%e";
  double x = 333;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf33) {
  char str1[1024];
  char str2[1024];
  char format[] = "%Le";
  long double x = 144.1456;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf35) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.11e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf37) {
  char str1[1024];
  char str2[1024];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.7878787),
                   sprintf(str2, format, 0.7878787));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf41) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.Lf";
  long double a = 5.69697887;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf42) {
  char str1[1024];
  char str2[1024];
  char format[] = "%#4p";
  int a = 4;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf43) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 98765),
                   sprintf(str2, format, 98765));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf44) {
  char str1[1024];
  char str2[1024];
  char format[] = "%#6lX";
  long value = 646735635683;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_zero) {
  char str1[1024];
  char str2[1024];
  char format[] = "%g";
  double m = 0.77801;
  ck_assert_int_eq(s21_sprintf(str1, format, m), sprintf(str2, format, m));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_high) {
  char str1[1024];
  char str2[1024];
  char format[] = "%g";
  double m = 53443.8875;
  ck_assert_int_eq(s21_sprintf(str1, format, m), sprintf(str2, format, m));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_low) {
  char str1[1024];
  char str2[1024];
  char format[] = "%g";
  double value = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_accurate) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.6g";
  double value = 0.130970;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_accurate_zero) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.0g";
  double value = 0.128000;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_accurate_test) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.g";
  double value = 0.121000;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_g_zeros) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.g";
  double value = 0.0003;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_val_zero) {
  char str1[1024];
  char str2[1024];
  char format[] = "%g";
  double value = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_accur_zero) {
  char str1[1024];
  char str2[1024];
  char format[] = "%.7g";
  double value = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_exp) {
  char str1[1024];
  char str2[1024];
  char format[] = "%g";
  double value = 0.0000004;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_exp_flags) {
  char str1[1024];
  char str2[1024];
  char format[] = "%5.3g";
  double value = 0.0000004;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_no_exp) {
  char str1[1024];
  char str2[1024];
  char format[] = "%g";
  double value = 0.007;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(LG_specs) {
  char str1[1024];
  char str2[1024];
  char format[] = "%LG";
  long double value = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, value),
                   sprintf(str2, format, value));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(wide_str) {
  char str1[1024];
  char str2[1024];

  char *format = "hello World! %ls";
  wchar_t w[] = L"N";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wide_str1) {
  char str1[1024];
  char str2[1024];

  char *format = "hello World! %3.11ls";
  wchar_t w[] = L"F";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wide_str2) {
  char str1[1024];
  char str2[1024];

  char *format = "hello World! %110ls MOSCOW";
  wchar_t w[] = L"Z";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wide_str3) {
  char str1[1024];
  char str2[1024];

  char *format = "hello World! %-23ls";
  wchar_t w[] = L"S";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wide_str4) {
  char str1[1024];
  char str2[1024];

  char *format = "cats dogs cats dogs %23ls";
  wchar_t w[] = L"POTATOES";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *test_suite_sprintf(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("s21_sprintf_tc");
  tcase_add_test(tc, only_int);
  tcase_add_test(tc, accurate_int);
  tcase_add_test(tc, width_int);
  tcase_add_test(tc, minus_width_int);
  tcase_add_test(tc, plus_width_int);
  tcase_add_test(tc, zero_width_int);
  tcase_add_test(tc, plus_width_accur_long);
  tcase_add_test(tc, minus_width_accur_short);
  tcase_add_test(tc, accurate_zero_int);
  tcase_add_test(tc, space_int);
  tcase_add_test(tc, only_unsigned);
  tcase_add_test(tc, width_unsigned);
  tcase_add_test(tc, minus_width_unsigned);
  tcase_add_test(tc, accurate_unsigned);
  tcase_add_test(tc, space_accur_width_unsigned);
  tcase_add_test(tc, short_unsigned);
  tcase_add_test(tc, long_unsigned);
  tcase_add_test(tc, long_octal2);
  tcase_add_test(tc, octal_width);
  tcase_add_test(tc, minus_width_octal);
  tcase_add_test(tc, accurate_octal);
  tcase_add_test(tc, minus_width_accur_oct);
  tcase_add_test(tc, short_octal);
  tcase_add_test(tc, long_octal);
  tcase_add_test(tc, only_octal);
  tcase_add_test(tc, hash_octal);
  tcase_add_test(tc, just_unsigned);
  tcase_add_test(tc, width_hex);
  tcase_add_test(tc, hash_min_width_hex);
  tcase_add_test(tc, accurate_hex);
  tcase_add_test(tc, minus_many_hex);
  tcase_add_test(tc, hash_width_accur_hex);
  tcase_add_test(tc, hash_hex_zero);
  tcase_add_test(tc, hex_hash);
  tcase_add_test(tc, short_hex);
  tcase_add_test(tc, hash_long_hex);
  tcase_add_test(tc, hash_width_hex);
  tcase_add_test(tc, hash_longwidth_hex);
  tcase_add_test(tc, only_char);
  tcase_add_test(tc, accurate_char);
  tcase_add_test(tc, minus_width_char);
  tcase_add_test(tc, width_char);
  tcase_add_test(tc, min_width_accur_char);
  tcase_add_test(tc, string);
  tcase_add_test(tc, string_accurate);
  tcase_add_test(tc, string_width);
  tcase_add_test(tc, min_width_accur_str);
  tcase_add_test(tc, only_long_str);
  tcase_add_test(tc, only_pointer);
  tcase_add_test(tc, pointer_width);
  tcase_add_test(tc, pointer_accurate);
  tcase_add_test(tc, specif_n);
  tcase_add_test(tc, l_float_accurate);
  tcase_add_test(tc, l_float_width);
  tcase_add_test(tc, g_exp);
  tcase_add_test(tc, g_exp_flags);
  tcase_add_test(tc, g_no_exp);
  tcase_add_test(tc, specif_n);
  tcase_add_test(tc, string_high_width);
  tcase_add_test(tc, l_float_accurate_zero);
  tcase_add_test(tc, l_float_accurate_empty);
  tcase_add_test(tc, l_float_high_accurate);
  tcase_add_test(tc, l_float_high_accurate_negative);
  tcase_add_test(tc, l_float_high);
  tcase_add_test(tc, space_float);
  tcase_add_test(tc, le_accurate_zero);
  tcase_add_test(tc, le_accurate);
  tcase_add_test(tc, le_accurate_high);
  tcase_add_test(tc, le_accurate_high_negative);
  tcase_add_test(tc, le_high);
  tcase_add_test(tc, e_width);
  tcase_add_test(tc, e_specif);
  tcase_add_test(tc, no_spec);
  tcase_add_test(tc, no_specif);
  tcase_add_test(tc, test_char);
  tcase_add_test(tc, test_string);
  tcase_add_test(tc, test_d_only);
  tcase_add_test(tc, test_int_only);
  tcase_add_test(tc, test_float_only);
  tcase_add_test(tc, test_unsign_only);
  tcase_add_test(tc, test_char_left);
  tcase_add_test(tc, test_char_right);
  tcase_add_test(tc, test_hex_low);
  tcase_add_test(tc, test_hex_upp);
  tcase_add_test(tc, test_hex_low_left);
  tcase_add_test(tc, test_hex_low_right);
  tcase_add_test(tc, test_hex_upp_left);
  tcase_add_test(tc, test_hex_upp_right);
  tcase_add_test(tc, test_one_hex_hash);
  tcase_add_test(tc, test_hex_upp_hash);
  tcase_add_test(tc, test_hex_low_len);
  tcase_add_test(tc, test_hex_upp_len);
  tcase_add_test(tc, test_s21_sprintf1);
  tcase_add_test(tc, test_s21_sprintf2);
  tcase_add_test(tc, test_s21_sprintf3);
  tcase_add_test(tc, test_s21_sprintf4);
  tcase_add_test(tc, test_s21_sprintf6);
  tcase_add_test(tc, test_s21_sprintf7);
  tcase_add_test(tc, test_s21_sprintf8);
  tcase_add_test(tc, test_s21_sprintf16);
  tcase_add_test(tc, test_s21_sprintf17);
  tcase_add_test(tc, test_s21_sprintf19);
  tcase_add_test(tc, test_s21_sprintf20);
  tcase_add_test(tc, test_s21_sprintf25);
  tcase_add_test(tc, test_s21_sprintf29);
  tcase_add_test(tc, test_s21_sprintf30);
  tcase_add_test(tc, test_s21_sprintf31);
  tcase_add_test(tc, test_s21_sprintf33);
  tcase_add_test(tc, test_s21_sprintf35);
  tcase_add_test(tc, test_s21_sprintf37);
  tcase_add_test(tc, test_s21_sprintf41);
  tcase_add_test(tc, test_s21_sprintf42);
  tcase_add_test(tc, test_s21_sprintf43);
  tcase_add_test(tc, test_s21_sprintf44);
  tcase_add_test(tc, g_zero);
  tcase_add_test(tc, g_high);
  tcase_add_test(tc, g_low);
  tcase_add_test(tc, g_accurate);
  tcase_add_test(tc, g_accurate_zero);
  tcase_add_test(tc, g_accurate_test);
  tcase_add_test(tc, test_g_zeros);
  tcase_add_test(tc, g_val_zero);
  tcase_add_test(tc, LG_specs);
  tcase_add_test(tc, g_accur_zero);
  tcase_add_test(tc, wide_str);
  tcase_add_test(tc, wide_str1);
  tcase_add_test(tc, wide_str2);
  tcase_add_test(tc, wide_str3);
  tcase_add_test(tc, wide_str4);
  suite_add_tcase(s, tc);
  return s;
}
