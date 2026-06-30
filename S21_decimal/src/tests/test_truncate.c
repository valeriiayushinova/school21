#include "test_main.h"

START_TEST(s21_truncate_1) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_2) {
  int true_res = 0;
  s21_decimal number1 = {{0x2196602A, 0x03178923, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x000000DE, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_3) {
  int true_res = 0;
  s21_decimal number1 = {{0x7C103971, 0x5CB51098, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00001A18, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_4) {
  int true_res = 0;
  s21_decimal number1 = {{0x0477675D, 0x01AB24CC, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x00000078, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_5) {
  int true_res = 0;
  s21_decimal number1 = {{0xDBEC3C7B, 0x1464ECBB, 0x00000003, 0x80100000}};
  s21_decimal result = {{0x00001630, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_6) {
  int true_res = 0;
  s21_decimal number1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_7) {
  int true_res = 0;
  s21_decimal number1 = {{0x0FFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_8) {
  int true_res = 0;
  s21_decimal number1 = {{0xF88B5A22, 0x272CF139, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00000B06, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_9) {
  int true_res = 0;
  s21_decimal number1 = {{0x5D989704, 0x2731E70F, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00000B08, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_10) {
  int true_res = 0;
  s21_decimal number1 = {{0xDE38B005, 0x2174A46E, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x0000096A, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_11) {
  int true_res = 0;
  s21_decimal number1 = {{0x2E45C4FE, 0x1CCB0272, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x0000081A, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_12) {
  int true_res = 0;
  s21_decimal number1 = {{0x2580AADF, 0x50585FA0, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x0000169D, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_13) {
  int true_res = 0;
  s21_decimal number1 = {{0x4A070176, 0x4499E0C9, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x0000134F, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_14) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_15) {
  int true_res = 0;
  s21_decimal number1 = {{0x6887E5CF, 0x03C041E3, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x0000010E, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_16) {
  int true_res = 0;
  s21_decimal number1 = {{0xF2490891, 0x3FD907B2, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x000011F8, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_17) {
  int true_res = 0;
  s21_decimal number1 = {{0x743D8EE9, 0x38F693A9, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00001008, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_18) {
  int true_res = 0;
  s21_decimal number1 = {{0xFA6DF24F, 0x5A036D0E, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00001956, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_19) {
  int true_res = 0;
  s21_decimal number1 = {{0x485D4427, 0x2025A74A, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x0000090C, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_20) {
  int true_res = 0;
  s21_decimal number1 = {{0xD8ACC486, 0x826A7EA8, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x000024B5, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_21) {
  int true_res = 0;
  s21_decimal number1 = {{0x9FD77E04, 0x78196E35, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x000021CE, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_22) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_23) {
  int true_res = 0;
  s21_decimal number1 = {{0xCE87BF43, 0xBC80E33E, 0x00000001, 0x80100000}};
  s21_decimal result = {{0x00000C82, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_24) {
  int true_res = 0;
  s21_decimal number1 = {{0xBF09845A, 0x854C4734, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00002585, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_25) {
  int true_res = 0;
  s21_decimal number1 = {{0x1655801A, 0x4A63D6B5, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x000014F0, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_26) {
  int true_res = 0;
  s21_decimal number1 = {{0xD0FF64D5, 0x3A9CAB77, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x0000107F, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_27) {
  int true_res = 0;
  s21_decimal number1 = {{0xF8478856, 0x28E10F4C, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x00000B81, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_28) {
  int true_res = 0;
  s21_decimal number1 = {{0x8327DE9D, 0x99A8B727, 0x00000004, 0x80100000}};
  s21_decimal result = {{0x00002125, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_29) {
  int true_res = 0;
  s21_decimal number1 = {{0xBA65B169, 0x06E8F057, 0x00000000, 0x800E0000}};
  s21_decimal result = {{0x00001373, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_30) {
  int true_res = 0;
  s21_decimal number1 = {{0x9CF7FC13, 0x0C3C1359, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x00000371, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_31) {
  int true_res = 0;
  s21_decimal number1 = {{0x0FFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_32) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_33) {
  int true_res = 0;
  s21_decimal number1 = {{0x87C358F0, 0x7A4ABE23, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x0000226C, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_34) {
  int true_res = 0;
  s21_decimal number1 = {{0x19A43525, 0x3F8E0988, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x000011E3, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_35) {
  int true_res = 0;
  s21_decimal number1 = {{0xE217BCB8, 0x6BDE5666, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00001E5C, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_36) {
  int true_res = 0;
  s21_decimal number1 = {{0xCB0D1894, 0x20104774, 0x00000000, 0x000F0000}};
  s21_decimal result = {{0x00000906, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_37) {
  int true_res = 0;
  s21_decimal number1 = {{0xF718198C, 0x73458254, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x00002072, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_38) {
  int true_res = 0;
  s21_decimal number1 = {{0x0FFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_39) {
  int true_res = 0;
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_40) {
  int true_res = 0;
  s21_decimal number1 = {{0x6F09707A, 0x21F80E9D, 0x00000000, 0x800F0000}};
  s21_decimal result = {{0x0000098F, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(number1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_truncate(void) {
  Suite *s = suite_create("\033[45m-=S21_TRUNCATE=-\033[0m");
  TCase *tc = tcase_create("s21_truncate_tc");

  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_5);
  tcase_add_test(tc, s21_truncate_6);
  tcase_add_test(tc, s21_truncate_7);
  tcase_add_test(tc, s21_truncate_8);
  tcase_add_test(tc, s21_truncate_9);
  tcase_add_test(tc, s21_truncate_10);
  tcase_add_test(tc, s21_truncate_11);
  tcase_add_test(tc, s21_truncate_12);
  tcase_add_test(tc, s21_truncate_13);
  tcase_add_test(tc, s21_truncate_14);
  tcase_add_test(tc, s21_truncate_15);
  tcase_add_test(tc, s21_truncate_16);
  tcase_add_test(tc, s21_truncate_17);
  tcase_add_test(tc, s21_truncate_18);
  tcase_add_test(tc, s21_truncate_19);
  tcase_add_test(tc, s21_truncate_20);
  tcase_add_test(tc, s21_truncate_21);
  tcase_add_test(tc, s21_truncate_22);
  tcase_add_test(tc, s21_truncate_23);
  tcase_add_test(tc, s21_truncate_24);
  tcase_add_test(tc, s21_truncate_25);
  tcase_add_test(tc, s21_truncate_26);
  tcase_add_test(tc, s21_truncate_27);
  tcase_add_test(tc, s21_truncate_28);
  tcase_add_test(tc, s21_truncate_29);
  tcase_add_test(tc, s21_truncate_30);
  tcase_add_test(tc, s21_truncate_31);
  tcase_add_test(tc, s21_truncate_32);
  tcase_add_test(tc, s21_truncate_33);
  tcase_add_test(tc, s21_truncate_34);
  tcase_add_test(tc, s21_truncate_35);
  tcase_add_test(tc, s21_truncate_36);
  tcase_add_test(tc, s21_truncate_37);
  tcase_add_test(tc, s21_truncate_38);
  tcase_add_test(tc, s21_truncate_39);
  tcase_add_test(tc, s21_truncate_40);

  suite_add_tcase(s, tc);
  return s;
}
