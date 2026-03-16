#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL) {
    return s21_NULL;
  }

  if (trim_chars == s21_NULL) {
    trim_chars = " ";  // по умолчанию обрезаем пробелы
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t start = 0;
  s21_size_t end = src_len;

  // находим первый символ слева, не входящий в trim_chars
  while (start < src_len && s21_strchr(trim_chars, src[start]) != s21_NULL) {
    start++;
  }

  // находим первый символ справа, не входящий в trim_chars
  while (end > start && s21_strchr(trim_chars, src[end - 1]) != s21_NULL) {
    end--;
  }

  // создаем новую строку без указанных символов слева и справа
  char *result = (char *)malloc((end - start + 1) * sizeof(char));
  if (result == s21_NULL) {
    return s21_NULL;
  }

  // копируем символы из исходной строки в новую строку
  for (s21_size_t i = start; i < end; i++) {
    result[i - start] = src[i];
  }
  result[end - start] = '\0';

  return result;
}