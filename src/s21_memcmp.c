#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  s21_size_t i = 0;

  const unsigned char *s = (const unsigned char *)str1;
  const unsigned char *d = (const unsigned char *)str2;
  while (i < n && s[i] == d[i]) {
    i++;
  }

  if (i == n) {
    return 0;
  } else {
    return s[i] - d[i];
  }
}
