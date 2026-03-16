#include "test_string.h"

// Тесты для функции s21_strncpy

START_TEST(strncpy_1) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  s21_size_t n = 13;
  char *src = "Hello World!";

  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncpy_2) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  s21_size_t n = 13;
  char *src = "Hello W\0rld!";

  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncpy_3) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  s21_size_t n = 13;
  char *src = "";

  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncpy_4) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  s21_size_t n = 13;
  char *src = "Hello";

  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncpy_5) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  s21_size_t n = 4;
  char *src = "Hello World!";

  s21_memset(dest, 0, 13);
  s21_memset(s21_dest, 0, 13);

  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncpy_6) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  s21_size_t n = 0;
  char *src = "Hello World!";

  s21_memset(dest, 0, 13);
  s21_memset(s21_dest, 0, 13);

  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncpy_7) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  s21_size_t n = 12;
  char *src = "\0";

  s21_memset(dest, 0, 13);
  s21_memset(s21_dest, 0, 13);

  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("\033[43m-=S21_STRNCPY=-\033[0m");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);

  suite_add_tcase(s, tc);

  return s;
}