#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *p = str;
  while (*p != '\0') {
    p++;
  }
  return p - str;
}