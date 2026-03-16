#include "test_string.h"

//  тесты для s21_memcmp

START_TEST(memcmp_1) {
  // пустые строки
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  // одинаковые строки
  char str1[] = "hello";
  char str2[] = "hello";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  // отличные строки
  char str1[] = "hello";
  char str2[] = "world";
  s21_size_t n = 5;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_4) {
  // сравнениеодного байта
  char str1[] = "a";
  char str2[] = "b";
  s21_size_t n = 1;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_5) {
  // сравнение нескольких байт
  char str1[] = "abcdef";
  char str2[] = "abcxyz";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  //  стр разной длины
  char str1[] = "hello world";
  char str2[] = "hello";
  s21_size_t n = 6;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_7) {
  // непечатнык символы
  char str1[] = "\x01\x02\x03";
  char str2[] = "\x01\x02\x04";
  s21_size_t n = 3;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_8) {
  // отрицательные числа
  char str1[] = "-123";
  char str2[] = "-456";
  s21_size_t n = 3;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_9) {
  // положительные числа
  char str1[] = "123";
  char str2[] = "456";
  s21_size_t n = 3;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_10) {
  // вещественные числа
  char str1[] = "3.14";
  char str2[] = "2.71";
  s21_size_t n = 4;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_11) {
  // стр с пробелами
  char str1[] = "hello world";
  char str2[] = "hello   world";
  s21_size_t n = 11;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_12) {
  // большое значение n
  char str1[] = "hello world";
  char str2[] = "hello";
  s21_size_t n = 100;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

// Создание и конфигурация набора тестов для s21_strcmp
Suite *test_memcmp(void) {
  Suite *s =
      suite_create("\033[46m-=S21_MEMCMP=-\033[0m");  // Создание нового набора
                                                      // тестов с именем
  TCase *tc =
      tcase_create("memcmp_tc");  // Создание нового тестового случая с именем

  // Добавление тестов в тестовый случай
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, memcmp_12);

  suite_add_tcase(s, tc);  // Добавление тестового случая в набор тестов

  return s;  // Возврат созданного набора тестов
}