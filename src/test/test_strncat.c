#include "test_string.h"

// Тесты для функции s21_strncat

START_TEST(strncat_1) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  strncpy(dest, "Hello", 6);
  strncpy(s21_dest, "Hello", 6);
  s21_size_t n = 8;
  char *src = " World!";

  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncat_2) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  strncpy(dest, "Hello", 6);
  strncpy(s21_dest, "Hello", 6);
  s21_size_t n = 8;
  char *src = " W\0rld!";

  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncat_3) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  strncpy(dest, "Hello", 6);
  strncpy(s21_dest, "Hello", 6);
  s21_size_t n = 8;
  char *src = "";

  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncat_4) {
  char *dest = malloc(28 * sizeof(char));
  char *s21_dest = malloc(28 * sizeof(char));
  strncpy(dest, "Hello", 6);
  strncpy(s21_dest, "Hello", 6);
  s21_size_t n = 28;
  char *src = " World!";

  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncat_5) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  strncpy(dest, "Hello", 6);
  strncpy(s21_dest, "Hello", 6);
  s21_size_t n = 2;
  char *src = " World!";

  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncat_6) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  strncpy(dest, "Hello", 6);
  strncpy(s21_dest, "Hello", 6);
  s21_size_t n = 0;
  char *src = " World!";

  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

START_TEST(strncat_7) {
  char *dest = malloc(13 * sizeof(char));
  char *s21_dest = malloc(13 * sizeof(char));
  strncpy(dest, "Hello", 6);
  strncpy(s21_dest, "Hello", 6);
  s21_size_t n = 8;
  char *src = "\0";

  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, src, n));

  free(dest);
  free(s21_dest);
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[43m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);

  suite_add_tcase(s, tc);

  return s;
}