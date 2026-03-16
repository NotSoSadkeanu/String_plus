#include "s21_string.h"
static char *new_token = s21_NULL;

char *s21_strtok(char *str, const char *delim) {
  char *token;

  if (str != s21_NULL) {
    new_token = str;
  }

  if (new_token == s21_NULL) {
    return s21_NULL;
  }

  while (*new_token && s21_strchr(delim, *new_token)) {
    new_token++;
  }

  if (*new_token == '\0') {
    new_token = s21_NULL;
    return new_token;
  }

  token = new_token;

  while (*new_token && !s21_strchr(delim, *new_token)) {
    new_token++;
  }

  if (*new_token != '\0') {
    *new_token = '\0';
    new_token++;
  } else {
    new_token = s21_NULL;
  }

  return token;
}
