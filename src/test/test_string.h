#ifndef SRC_TESTS_STRING_H
#define SRC_TESTS_STRING_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 400

#include "../s21_string.h"

// тута добавляем наши функции 1 функция = 1 .с файл

Suite *test_strlen(void);
Suite *test_strcspn(void);
Suite *test_strchr(void);
Suite *test_strrchr(void);
Suite *test_strpbrk(void);
Suite *test_strstr(void);
Suite *test_memchr(void);
Suite *test_strerror(void);
Suite *test_memcpy(void);
Suite *test_memmove(void);
Suite *test_strncmp(void);
Suite *test_memcmp(void);
Suite *test_strncpy(void);
Suite *test_strncat(void);
Suite *test_strtok(void);
Suite *test_memset(void);
Suite *test_sprintf(void);
Suite *test_printU(void);
Suite *test_printCSP(void);
Suite *test_to_lower(void);
Suite *test_to_upper(void);
Suite *test_insert(void);
Suite *test_trim(void);
Suite *test_sprintf_c(void);
Suite *test_sprintf_signed(void);
Suite *test_sprintf_e(void);
Suite *test_sprintf_f(void);
// Suite *test_sprintf_g(void);
Suite *test_sprintf_hex(void);
Suite *test_sprintf_HEX(void);
Suite *test_sprintf_signed_i(void);
Suite *test_sprintf_n(void);
Suite *test_sprintf_octal(void);
Suite *test_sprintf_percent(void);
Suite *test_sprintf_pointer(void);
Suite *test_sprintf_string(void);
Suite *test_sprintf_unsigned(void);
Suite *test_sprintff(void);

#endif  // SRC_TESTS_STRING_H
