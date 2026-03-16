#include "s21_string.h"
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;

  while (*str1 && !result) {
    s21_size_t j = 0;
    while (str2[j] != '\0') {
      if (*str1 == str2[j]) result = (char *)str1;
      j++;
    }
    str1++;
  }
  return (result);
}
