#include "test_string.h"
// обычные буквы

START_TEST(sprintf_1_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %o Test %x";
  unsigned long int val = 158;
  unsigned long int val2 = 900;
  unsigned long int val3 = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ширина с минусом и без него
START_TEST(sprintf_2_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%10u Test %-10o Test %-10x";
  unsigned long int val = 158;
  unsigned long int val2 = 900;
  unsigned long int val3 = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// точность
START_TEST(sprintf_3_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%.10u Test %.10o Test %.5x";
  unsigned long int val = 158;
  unsigned long int val2 = 900;
  unsigned long int val3 = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// точность + ширина
START_TEST(sprintf_4_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23o Test %3.x Test %6.5x Test %.6x";
  unsigned long int val = 158;
  unsigned long int val2 = 900;
  unsigned long int val3 = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val3, val3, val3),
                   s21_sprintf(str2, str3, val, val2, val3, val3, val3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// отрицательная ширина + точность
START_TEST(sprintf_5_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%-6.5u Test %-.23o Test %-3.x Test %-6.5x Test %-.6x";
  unsigned long int val = 158;
  unsigned long int val2 = 900;
  unsigned long int val3 = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val3, val3, val3),
                   s21_sprintf(str2, str3, val, val2, val3, val3, val3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// флаг ноль + точность
START_TEST(sprintf_6_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0.o Test %0.0x Test %0x Test %.x";
  unsigned long int val = 158;
  unsigned long int val2 = 900;
  unsigned long int val3 = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val3, val3, val3),
                   s21_sprintf(str2, str3, val, val2, val3, val3, val3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// флаг 0 плюс число 0
START_TEST(sprintf_7_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0.o Test %0.0x Test %0x Test %.x";
  unsigned long int val = 0;
  unsigned long int val2 = 0;
  unsigned long int val3 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val3, val3, val3),
                   s21_sprintf(str2, str3, val, val2, val3, val3, val3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// флаг решетка плюс число 0
START_TEST(sprintf_8_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Test %#03.u Test %#05.7o Test %#010o Test %#0.o";
  unsigned long int val = 0;
  unsigned long int val2 = 0;
  unsigned long int val3 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val3, val3, val3),
                   s21_sprintf(str2, str3, val, val2, val3, val3, val3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// флаг решетка с числами
START_TEST(sprintf_9_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Test %#03.u Test %#05.7o Test %#010o Test %#0.o";
  unsigned long int val = 18;
  unsigned long int val2 = 325;
  unsigned long int val3 = 900;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val3, val3, val3),
                   s21_sprintf(str2, str3, val, val2, val3, val3, val3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// флаг решетка с х
START_TEST(sprintf_10_U) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#03.x Test %#05.7x Test %#010x Test %#.x";
  unsigned long int val = 18;
  unsigned long int val2 = 325;
  unsigned long int val3 = 900;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val3, val3, val3),
                   s21_sprintf(str2, str3, val, val2, val3, val3, val3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_printU(void) {
  Suite *s = suite_create("\033[44m-=S21_PRINTU=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_U);
  tcase_add_test(tc, sprintf_2_U);
  tcase_add_test(tc, sprintf_3_U);
  tcase_add_test(tc, sprintf_4_U);
  tcase_add_test(tc, sprintf_5_U);
  tcase_add_test(tc, sprintf_6_U);
  tcase_add_test(tc, sprintf_7_U);
  tcase_add_test(tc, sprintf_8_U);
  tcase_add_test(tc, sprintf_9_U);
  tcase_add_test(tc, sprintf_10_U);
  suite_add_tcase(s, tc);
  return s;
}
