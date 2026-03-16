#include "s21_string.h"
void *s21_memchr(const void *str, int c, s21_size_t n) {
  
  const unsigned char *result = (const unsigned char *)str;
  const unsigned char target = (unsigned char)c;
  s21_size_t x = 0;
  void *found = s21_NULL;

  while (x < n && result[x] != target) {
    x++;
  }

  if (x < n) {
    found = (void *)(result + x);
  }

  return found;
}