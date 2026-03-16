#include "s21_string.h"

void *s21_memset(void *str, int v, s21_size_t n) {
  unsigned char *s = str;
  unsigned char value = v;
  while (n--) {
    *s++ = value;
  }
  return str;
}