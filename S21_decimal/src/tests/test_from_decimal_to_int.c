#include "test_main.h"

START_TEST(s21_to_int_1) {
  int true_res = 1;
  s21_decimal number1 = {{0xC657011F, 0xD3CA7CC2, 0x429D8BC7, 0x80060000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_2) {
  int true_res = 1;
  s21_decimal number1 = {{0x0553D374, 0x31F17BDA, 0x5BDE9DC7, 0x000F0000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_3) {
  int true_res = 1;
  s21_decimal number1 = {{0x9499FB51, 0xBF753BB8, 0xAFB443EC, 0x000F0000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_4) {
  int true_res = 1;
  s21_decimal number1 = {{0xC551C40B, 0x72AD57BE, 0x7384FB62, 0x00080000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_5) {
  int true_res = 1;
  s21_decimal number1 = {{0x5E99C4B7, 0xDA29D2CF, 0x710789DA, 0x00000000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_6) {
  int true_res = 1;
  s21_decimal number1 = {{0x1137EB61, 0x184592D4, 0x03D45570, 0x80000000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_7) {
  int true_res = 1;
  s21_decimal number1 = {{0xC49C0BB0, 0xB60FDBCF, 0xA5B4A5FE, 0x80070000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_8) {
  int true_res = 1;
  s21_decimal number1 = {{0x49236127, 0x927CDE13, 0x120D099D, 0x80000000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_9) {
  int true_res = 1;
  s21_decimal number1 = {{0x0F332B73, 0x456148DA, 0x1C8294B2, 0x000D0000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_10) {
  int true_res = 1;
  s21_decimal number1 = {{0xA391D6CD, 0x1D2BACFC, 0x111F12D3, 0x800A0000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_11) {
  int true_res = 1;
  s21_decimal number1 = {{0xFEB80A2B, 0x3709FED0, 0x69FF9CBB, 0x80070000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_12) {
  int true_res = 1;
  s21_decimal number1 = {{0x0D67B467, 0x286E2CD8, 0x5A91BFBA, 0x80000000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_13) {
  int true_res = 1;
  s21_decimal number1 = {{0xDC4B174E, 0xC2B71CB8, 0xE4CD7AAF, 0x80040000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_14) {
  int true_res = 0;
  s21_decimal number1 = {{0x6C769702, 0x5857BE88, 0x50C72729, 0x80140000}};
  int result = -249995619;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_15) {
  int true_res = 0;
  s21_decimal number1 = {{0x5D179938, 0x4F9EA81C, 0x1579C023, 0x00180000}};
  int result = 6646;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_16) {
  int true_res = 1;
  s21_decimal number1 = {{0x89CA705F, 0x6B7B9505, 0xBF0F75DA, 0x800F0000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_17) {
  int true_res = 1;
  s21_decimal number1 = {{0x9D3FD329, 0x3FE92DCD, 0xE7F90CE6, 0x00040000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_18) {
  int true_res = 1;
  s21_decimal number1 = {{0x48BB3178, 0x40F0EC34, 0xE2943E47, 0x80130000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_19) {
  int true_res = 0;
  s21_decimal number1 = {{0x667BE2A4, 0x07FEC1FB, 0xF326E5CC, 0x00180000}};
  int result = 75251;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_20) {
  int true_res = 1;
  s21_decimal number1 = {{0x2A7D8E62, 0x72CAAA03, 0x470D92F8, 0x80110000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_21) {
  int true_res = 0;
  s21_decimal number1 = {{0x72412201, 0xA832D10B, 0xDA95B3F2, 0x801A0000}};
  int result = -676;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_22) {
  int true_res = 1;
  s21_decimal number1 = {{0x72F47F4E, 0x2035C75E, 0x8B3370CA, 0x00020000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_23) {
  int true_res = 1;
  s21_decimal number1 = {{0x6290E469, 0xA0B3A584, 0xB309A5DE, 0x00020000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_24) {
  int true_res = 0;
  s21_decimal number1 = {{0x466B30E5, 0xF73EE9F9, 0xB403487E, 0x00190000}};
  int result = 5571;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_25) {
  int true_res = 1;
  s21_decimal number1 = {{0x359A9E5C, 0xFCE54253, 0x3A5EE64D, 0x00090000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_26) {
  int true_res = 1;
  s21_decimal number1 = {{0x2BADE160, 0x4FEFCFBA, 0x7CA92937, 0x00110000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_27) {
  int true_res = 0;
  s21_decimal number1 = {{0x649D4539, 0x8098B813, 0x03501F32, 0x80180000}};
  int result = -1025;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_28) {
  int true_res = 1;
  s21_decimal number1 = {{0x7CCA563C, 0x7B837603, 0x4E2F0F79, 0x00010000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_29) {
  int true_res = 1;
  s21_decimal number1 = {{0x30673041, 0xFB9A9821, 0x2091953B, 0x80110000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_30) {
  int true_res = 0;
  s21_decimal number1 = {{0xE2034FB7, 0x7BAD5F08, 0x473AE916, 0x00160000}};
  int result = 2204465;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_31) {
  int true_res = 1;
  s21_decimal number1 = {{0xC7E86EF6, 0xEFBDE1C2, 0x85142E4A, 0x800D0000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_32) {
  int true_res = 1;
  s21_decimal number1 = {{0x608A3082, 0xFE811B83, 0xAF9B3298, 0x00020000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_33) {
  int true_res = 1;
  s21_decimal number1 = {{0x814DC17E, 0x8AF52CCB, 0xBCC5511D, 0x80000000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_34) {
  int true_res = 1;
  s21_decimal number1 = {{0x40F93CDD, 0xDF772E15, 0x3BEC89B0, 0x00120000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_35) {
  int true_res = 1;
  s21_decimal number1 = {{0xD9E2A1B9, 0xC374EEC5, 0x1DB1DB99, 0x00090000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_36) {
  int true_res = 1;
  s21_decimal number1 = {{0xB000D66F, 0x230001EA, 0x733DEB18, 0x00120000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_37) {
  int true_res = 0;
  s21_decimal number1 = {{0x92ADA7FE, 0x1D249B72, 0x149164FA, 0x00180000}};
  int result = 6365;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_38) {
  int true_res = 0;
  s21_decimal number1 = {{0x65B62461, 0x9EA1799D, 0x033202A9, 0x80130000}};
  int result = -98891389;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_39) {
  int true_res = 1;
  s21_decimal number1 = {{0xDA075AAB, 0xC0D16C1E, 0x8A66E6D5, 0x800C0000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_40) {
  int true_res = 1;
  s21_decimal number1 = {{0x59F6F3DB, 0x0C539291, 0xCE05CC13, 0x00030000}};
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_to_int_41) {
  int true_res = 0;
  s21_decimal number1 = {{0x80000000, 0, 0, 0x80000000}};
  int result = -0x80000000;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(number1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_from_decimal_to_int(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_INT=-\033[0m");
  TCase *tc = tcase_create("s21_from_decimal_to_int_tc");

  tcase_add_test(tc, s21_to_int_1);
  tcase_add_test(tc, s21_to_int_2);
  tcase_add_test(tc, s21_to_int_3);
  tcase_add_test(tc, s21_to_int_4);
  tcase_add_test(tc, s21_to_int_5);
  tcase_add_test(tc, s21_to_int_6);
  tcase_add_test(tc, s21_to_int_7);
  tcase_add_test(tc, s21_to_int_8);
  tcase_add_test(tc, s21_to_int_9);
  tcase_add_test(tc, s21_to_int_10);
  tcase_add_test(tc, s21_to_int_11);
  tcase_add_test(tc, s21_to_int_12);
  tcase_add_test(tc, s21_to_int_13);
  tcase_add_test(tc, s21_to_int_14);
  tcase_add_test(tc, s21_to_int_15);
  tcase_add_test(tc, s21_to_int_16);
  tcase_add_test(tc, s21_to_int_17);
  tcase_add_test(tc, s21_to_int_18);
  tcase_add_test(tc, s21_to_int_19);
  tcase_add_test(tc, s21_to_int_20);
  tcase_add_test(tc, s21_to_int_21);
  tcase_add_test(tc, s21_to_int_22);
  tcase_add_test(tc, s21_to_int_23);
  tcase_add_test(tc, s21_to_int_24);
  tcase_add_test(tc, s21_to_int_25);
  tcase_add_test(tc, s21_to_int_26);
  tcase_add_test(tc, s21_to_int_27);
  tcase_add_test(tc, s21_to_int_28);
  tcase_add_test(tc, s21_to_int_29);
  tcase_add_test(tc, s21_to_int_30);
  tcase_add_test(tc, s21_to_int_31);
  tcase_add_test(tc, s21_to_int_32);
  tcase_add_test(tc, s21_to_int_33);
  tcase_add_test(tc, s21_to_int_34);
  tcase_add_test(tc, s21_to_int_35);
  tcase_add_test(tc, s21_to_int_36);
  tcase_add_test(tc, s21_to_int_37);
  tcase_add_test(tc, s21_to_int_38);
  tcase_add_test(tc, s21_to_int_39);
  tcase_add_test(tc, s21_to_int_40);
  tcase_add_test(tc, s21_to_int_41);

  suite_add_tcase(s, tc);
  return s;
}
