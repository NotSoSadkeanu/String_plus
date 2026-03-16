#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int len = s21_strlen(str);
  const char *ptr = str + len - 1;
  char *result = s21_NULL;
  if (c == '\0') {
    return (char *)(str + len);
  }
  while (ptr >= str) {
    if (*ptr == (char)c) {
      result = (char *)ptr;
    }
    ptr--;
  }
  return result;
}
