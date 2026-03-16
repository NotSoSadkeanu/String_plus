#include <check.h>

#include "../s21_sprintf.h"
#include "test_string.h"

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  int res1 = s21_sprintf(str1, str3, a, b, c, d, e);
  int res2 = sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  int res1 = s21_sprintf(str1, str3, a, b, c, d, e);
  int res2 = sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;

  int res1 = s21_sprintf(str1, str3, a, b, c, d, e);
  int res2 = sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  char a = 0;

  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";

  int res1 = s21_sprintf(str1, str3, ' ', 'n', '5', '%', '\\');
  int res2 = sprintf(str2, str3, ' ', 'n', '5', '%', '\\');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = s21_sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c');
  int res2 = sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";

  int res1 = s21_sprintf(str1, str3, 'b', '4', '#', '@', '\0');
  int res2 = sprintf(str2, str3, 'b', '4', '#', '@', '\0');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = s21_sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J');
  int res2 = sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_15_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test %-7c Test %-50c Test % 54c Test %0188c";
  int a = 112;
  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_17_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 1: Простое форматирование указателя
START_TEST(sprintf_1_p) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "Pointer is: %p";
  void *val = (void *)0x1234;
  int res1 = s21_sprintf(str1, format, val);
  int res2 = sprintf(str2, format, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 2: Три указателя с разными значениями
START_TEST(sprintf_2_p) {
  char str1[100];
  char str2[100];
  char *format = "%p and %p and %p";
  void *val1 = (void *)0x1234;
  void *val2 = (void *)0x5678;
  void *val3 = (void *)0x9ABC;
  int res1 = s21_sprintf(str1, format, val1, val2, val3);
  int res2 = sprintf(str2, format, val1, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 3: Указатели разной длины
START_TEST(sprintf_3_p) {
  char str1[100];
  char str2[100];
  char *format = "%p | %p | %p";
  long int *val1 = (void *)0x1000000000000000;
  long long int *val2 = (void *)0x200000000;
  unsigned short int *val3 = (void *)0x3000;
  int res1 = s21_sprintf(str1, format, val1, val2, val3);
  int res2 = sprintf(str2, format, val1, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 4: Разные ширины для указателей
START_TEST(sprintf_4_p) {
  char str1[100];
  char str2[100];
  char *format = "%4p %8p %12p";
  void *val1 = (void *)0x01;
  void *val2 = (void *)0x2345;
  void *val3 = (void *)0x67890ABCD;
  int res1 = s21_sprintf(str1, format, val1, val2, val3);
  int res2 = sprintf(str2, format, val1, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 5: Разная точность и ширина
START_TEST(sprintf_5_p) {
  char str1[200];
  char str2[200];
  char *format = "%5.3p | %.7p | %7.p";
  void *val1 = (void *)0xAB;
  void *val2 = (void *)0x1234567;
  void *val3 = (void *)0x89;
  int res1 = s21_sprintf(str1, format, val1, val2, val3);
  int res2 = sprintf(str2, format, val1, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 6: Флаг минуса для указателей
START_TEST(sprintf_6_p) {
  char str1[200];
  char str2[200];
  char *format = "%-10p | %-5p | %-15p";
  void *val1 = (void *)0x123;
  void *val2 = (void *)0x4567;
  void *val3 = (void *)0x89ABCDEF;
  int res1 = s21_sprintf(str1, format, val1, val2, val3);
  int res2 = sprintf(str2, format, val1, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 7: Флаги нулей
START_TEST(sprintf_7_p) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %06p Test %05.7p TEST %0.7p Oof %0.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 8: Пробелы
START_TEST(sprintf_8_p) {
  char str1[200];
  char str2[200];
  char *str3 = "% p Test % 3.p Test % 5.7p TEST % 10p GOD %.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "23";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 9: Использование символа `#`
START_TEST(sprintf_9_p) {
  char str1[200];
  char str2[200];
  char *format = "%#p | %#5p | %#10p";
  void *val1 = (void *)0x1;
  void *val2 = (void *)0x12;
  void *val3 = (void *)0x123;
  int res1 = s21_sprintf(str1, format, val1, val2, val3);
  int res2 = sprintf(str2, format, val1, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 10: Использование знаков `*` для ширины и точности
START_TEST(sprintf_10_p) {
  char str1[200];
  char str2[200];
  char *format = "%*p | %-*p | %*.*p";
  int width1 = 5;
  int width2 = 10;
  int precision = 6;
  void *val1 = (void *)0x1;
  void *val2 = (void *)0x12;
  void *val3 = (void *)0x123456;
  int res1 = s21_sprintf(str1, format, width1, val1, width2, val2, width2,
                         precision, val3);
  int res2 = sprintf(str2, format, width1, val1, width2, val2, width2,
                     precision, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST
// Тест 1: Строка с одним параметром
START_TEST(sprintf_1_s) {
  char str1[100];
  char str2[100];
  char *str3 = "Example: %s";
  char *val = "Test String";
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 2: Три строковых параметра
START_TEST(sprintf_2_s) {
  char str1[100];
  char str2[100];
  char *str3 = "First: %s, Second: %s, Third: %s";
  char *val = "Alpha";
  char *val2 = "Beta";
  char *val3 = "Gamma";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 3: Строки с различной шириной и точностью
START_TEST(sprintf_3_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%5s | %10.5s | %3.2s";
  char *val = "Short";
  char *val2 = "MediumLength";
  char *val3 = "LongerText";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 4: Использование флага минуса
START_TEST(sprintf_4_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%-10s | %-15s";
  char *val = "Left";
  char *val2 = "Aligned";
  int res1 = s21_sprintf(str1, str3, val, val2);
  int res2 = sprintf(str2, str3, val, val2);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 5: Ширина и точность
START_TEST(sprintf_5_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%10.5s | %.8s | %3.2s";
  char *val = "ShortText";
  char *val2 = "This is a longer text";
  char *val3 = "AnotherText";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 6: Пустая строка и строка с нулевым символом
START_TEST(sprintf_6_s) {
  char str1[100];
  char str2[100];
  char *str3 = "Empty: %s | NullChar: %s";
  char *val = "";
  char *val2 = "\0";
  int res1 = s21_sprintf(str1, str3, val, val2);
  int res2 = sprintf(str2, str3, val, val2);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 7: Заполнение пробелами и нулями
START_TEST(sprintf_7_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%10s | %010s";
  char *val = "Spaces";
  char *val2 = "Zeros";
  int res1 = s21_sprintf(str1, str3, val, val2);
  int res2 = sprintf(str2, str3, val, val2);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 8: Пробелы перед строками
START_TEST(sprintf_8_s) {
  char str1[100];
  char str2[100];
  char *str3 = "% 10s | % 5s";
  char *val = "Leading";
  char *val2 = "Spaces";
  int res1 = s21_sprintf(str1, str3, val, val2);
  int res2 = sprintf(str2, str3, val, val2);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 9: Пробелы и плюсы
START_TEST(sprintf_9_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%+10s | % 5s";
  char *val = "Plus";
  char *val2 = "Space";
  int res1 = s21_sprintf(str1, str3, val, val2);
  int res2 = sprintf(str2, str3, val, val2);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 10: Пробелы и плюс в строке
START_TEST(sprintf_10_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%+10s | %+5s";
  char *val = "Test";
  char *val2 = "Space";
  int res1 = s21_sprintf(str1, str3, val, val2);
  int res2 = sprintf(str2, str3, val, val2);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 11: Обычные и длинные строки
START_TEST(sprintf_11_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%-20s | %20s";
  char *val = "LeftAligned";
  char *val2 = "RightAligned";
  int res1 = s21_sprintf(str1, str3, val, val2);
  int res2 = sprintf(str2, str3, val, val2);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 12: Использование звёздочек для ширины и точности
START_TEST(sprintf_12_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s | %-*s | %.*s";
  char *val = "VariableWidth";
  char *val2 = "Left";
  char *val3 = "Precision";
  int width = 15;
  int leftWidth = 10;
  int precision = 5;

  int res1 =
      s21_sprintf(str1, str3, width, val, leftWidth, val2, precision, val3);
  int res2 = sprintf(str2, str3, width, val, leftWidth, val2, precision, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 13: Пустые строки и символы
START_TEST(sprintf_13_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%s | %s | %s";
  char *val = "";
  char *val2 = "\0";
  char *val3 = "Normal";

  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 14: Обработка строк с нулевыми символами
START_TEST(sprintf_14_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%s | %s | %s";
  char *val = "Text";
  char *val2 = "With\0Null";
  char *val3 = "End";

  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 15: Форматирование строк с экранированием
START_TEST(sprintf_15_s) {
  char str1[200];
  char str2[200];
  char *str3 = "Escaped: %% | Literal: %s";
  char *val = "Test";

  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Тест 16: Строки с разными форматами
START_TEST(sprintf_16_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%s | %10s | %-10s | %05s";
  char *val = "Test";
  char *val2 = "Right";
  char *val3 = "Left";
  char *val4 = "Zeros";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_printCSP(void) {
  Suite *s = suite_create("\033[44m-=S21_PRINTCSP=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_4_c);
  tcase_add_test(tc, sprintf_5_c);
  tcase_add_test(tc, sprintf_11_c);
  tcase_add_test(tc, sprintf_12_c);
  tcase_add_test(tc, sprintf_13_c);
  tcase_add_test(tc, sprintf_14_c);
  tcase_add_test(tc, sprintf_15_c);
  tcase_add_test(tc, sprintf_16_c);
  tcase_add_test(tc, sprintf_17_c);

  tcase_add_test(tc, sprintf_1_p);
  tcase_add_test(tc, sprintf_2_p);
  tcase_add_test(tc, sprintf_3_p);
  tcase_add_test(tc, sprintf_4_p);
  tcase_add_test(tc, sprintf_5_p);
  tcase_add_test(tc, sprintf_6_p);
  tcase_add_test(tc, sprintf_7_p);
  tcase_add_test(tc, sprintf_8_p);
  tcase_add_test(tc, sprintf_9_p);
  tcase_add_test(tc, sprintf_10_p);

  tcase_add_test(tc, sprintf_1_s);
  tcase_add_test(tc, sprintf_2_s);
  tcase_add_test(tc, sprintf_3_s);
  tcase_add_test(tc, sprintf_4_s);
  tcase_add_test(tc, sprintf_5_s);
  tcase_add_test(tc, sprintf_6_s);
  tcase_add_test(tc, sprintf_7_s);
  tcase_add_test(tc, sprintf_8_s);
  tcase_add_test(tc, sprintf_9_s);
  tcase_add_test(tc, sprintf_10_s);
  tcase_add_test(tc, sprintf_11_s);
  tcase_add_test(tc, sprintf_12_s);
  tcase_add_test(tc, sprintf_13_s);
  tcase_add_test(tc, sprintf_14_s);
  tcase_add_test(tc, sprintf_15_s);
  tcase_add_test(tc, sprintf_16_s);
  suite_add_tcase(s, tc);
  return s;
}