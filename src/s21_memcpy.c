#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const unsigned char *s = src;
  unsigned char *d = dest;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}