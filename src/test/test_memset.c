#include "test_string.h"

START_TEST(memset_1) {
  char str[1] = "";
  s21_memset(str, 'a', 0);
  ck_assert_str_eq(str, "");
}
END_TEST

START_TEST(memset_2) {
  char str[6] = "hello";
  s21_memset(str, '\0', 5);
  for (size_t i = 0; i < 5; i++) {
    ck_assert_int_eq(str[i], '\0');
  }
}
END_TEST

START_TEST(memset_3) {
  char str[6] = "hello";
  s21_memset(str, 'a', 5);
  ck_assert_str_eq(str, "aaaaa");
}
END_TEST

START_TEST(memset_4) {
  int arr[5] = {1, 2, 3, 4, 5};
  s21_memset(arr, 0, 5 * sizeof(int));
  for (size_t i = 0; i < 5; i++) {
    ck_assert_int_eq(arr[i], 0);
  }
}
END_TEST

START_TEST(memset_5) {
  char str[2] = "a";
  s21_memset(str, 'b', 1);
  ck_assert_str_eq(str, "b");
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("\033[42m-=S21_MEMSET=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  suite_add_tcase(s, tc);

  return s;
}