#include "s21_test.h"

START_TEST(s21_to_lower_test_1) {
  char vod[] = "POTATOES MAKE THE PROJECT";
  char pol[] = "potatoes make the project";
  char *program = s21_to_lower(vod);
  ck_assert_str_eq(program, pol);
  if (program) free(program);
}
END_TEST

START_TEST(s21_to_lower_test_2) {
  char vod_2[] = "CAT CAT";
  char pol_2[] = "cat cat";
  char *program_2 = s21_to_lower(vod_2);
  ck_assert_str_eq(program_2, pol_2);
  if (program_2) free(program_2);
}
END_TEST

START_TEST(s21_to_lower_test_3) {
  char vod_3[] = "POTATOES COOL5COOL";
  char pol_3[] = "potatoes cool5cool";
  char *program_3 = s21_to_lower(vod_3);
  ck_assert_str_eq(program_3, pol_3);
  if (program_3) free(program_3);
}
END_TEST

Suite *test_suite_to_lower(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_to_lower_test_1);
  tcase_add_test(tc_core, s21_to_lower_test_2);
  tcase_add_test(tc_core, s21_to_lower_test_3);

  suite_add_tcase(s, tc_core);
  return s;
}
