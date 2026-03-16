#include "test_string.h"

START_TEST(memmove_1) {
  char s1[] = "Hello, world!";
  char s2[14] = {0};
  ck_assert_str_eq(memmove(s2, s1, 14), s21_memmove(s2, s1, 14));
}
END_TEST

START_TEST(memmove_2) {
  char s1[] = "Overlap test";
  char s2[] = "Overlap test";
  ck_assert_str_eq(memmove(s1, s2 + 3, 10), s21_memmove(s1, s1 + 3, 10));
}
END_TEST

START_TEST(memmove_3) {
  char s1[] = "Hello world";
  char s2[] = "Hello world";
  ck_assert_str_eq(memmove(s1, s2, 0), s21_memmove(s1, s1, 0));
}
END_TEST

START_TEST(memmove_4) {
  char s1[] = "A";
  char s2[2] = {0};
  ck_assert_ptr_eq(memmove(s2, s1, 1), s21_memmove(s2, s1, 1));
  ck_assert_str_eq(s2, s1);
}
END_TEST

START_TEST(memmove_5) {
  char s1[] = "Non-empty";
  char s2[20] = "Destination";
  ck_assert_ptr_eq(memmove(s2, s1, 0), s21_memmove(s2, s1, 0));
  ck_assert_str_eq(s2, "Destination");
}
END_TEST

START_TEST(memmove_6) {
  char s1[] = "";
  char s2[1] = {0};
  ck_assert_ptr_eq(memmove(s2, s1, 1), s21_memmove(s2, s1, 1));
  ck_assert_str_eq(s2, s1);
}
END_TEST

START_TEST(memmove_7) {
  char s1[1000] = {0};
  char s2[1000] = {0};
  for (int i = 0; i < 1000; i++) {
    s1[i] = (char)(i % 256);
  }
  ck_assert_ptr_eq(memmove(s2, s1, 1000), s21_memmove(s2, s1, 1000));
  ck_assert_mem_eq(s2, s1, 1000);

}
END_TEST

START_TEST(memmove_8) {
  char s1[] = "abcdefghij";
  char s2[] = "ababcdefgh";
  s21_memmove(s1 + 2, s1, 8);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(memmove_9) {
  char s1[] = "abcdefghij";
  char s2[] = "cdefghijij";
  ck_assert_str_eq(memmove(s1, s2, 8), s21_memmove(s1, s1 + 2, 8));
}
END_TEST

Suite *test_memmove(void) {
  Suite *s = suite_create("\033[42m-=S21_MEMMOVE=-\033[0m");
  TCase *tc = tcase_create("memmove_tc");

  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);
  tcase_add_test(tc, memmove_4);
  tcase_add_test(tc, memmove_5);
  tcase_add_test(tc, memmove_6);
  tcase_add_test(tc, memmove_7);
  tcase_add_test(tc, memmove_8);
  tcase_add_test(tc, memmove_9);
  suite_add_tcase(s, tc);
  return s;
}
