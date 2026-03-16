#include "s21_string.h"

char *s21_strchr(const char *s, int c) {
  while (*s != '\0') {
    if (*s == c) {
      return (char *)s;
    }
    s++;
  }
  if (c == '\0') {
    return (char *)s;
  }
  return s21_NULL;
}