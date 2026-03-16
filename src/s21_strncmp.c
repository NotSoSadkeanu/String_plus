
#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  while (n > 0) {
    if (*str1 != *str2) {
      return (unsigned char)(*str1) - (unsigned char)(*str2);
    }
    if (*str1 == '\0') {
      return 0;
    }
    str1++;
    str2++;
    n--;
  }
  return 0;
}
