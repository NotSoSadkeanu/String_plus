#include <stdlib.h>

#include "s21_string.h"

/* void *s21_to_lower(const char *str) {
    if (str == s21_NULL ) {
        return s21_NULL;
    }

    s21_size_t len = s21_strlen(str);
    char *lower_str = (char *)malloc((len + 1) * sizeof(char));
    if (lower_str == s21_NULL) {
        return s21_NULL;
    }

    for (s21_size_t i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            lower_str[i] = str[i] + 32;
        } else {
            lower_str[i] = str[i];
        }
    }


      return lower_str;
} */

void *s21_to_lower(const char *str) {
  char *str_res = s21_NULL;
  if (str != s21_NULL) {
    str_res = malloc(sizeof(char) * (s21_strlen(str) + 1));
    s21_size_t curr_index = 0;

    for (curr_index = 0; str[curr_index] != '\0'; curr_index++) {
      if (str[curr_index] >= 'A' && str[curr_index] <= 'Z')
        str_res[curr_index] = str[curr_index] + 32;
      else
        str_res[curr_index] = str[curr_index];
    }

    str_res[curr_index] = '\0';
  } else
    str_res = s21_NULL;

  return str_res;
}
