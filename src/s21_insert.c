#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index > src_len) {
    return s21_NULL;
  }

  char *result = (char *)malloc((src_len + str_len + 1) * sizeof(char));
  if (result == s21_NULL) {
    return s21_NULL;
  }

  for (s21_size_t i = 0; i < src_len + str_len; i++) {
    if (i < start_index) {
      result[i] = src[i];
    } else if (i < start_index + str_len) {
      result[i] = str[i - start_index];
    } else {
      result[i] = src[i - str_len];
    }
  }

  result[src_len + str_len] = '\0';

  return result;
}