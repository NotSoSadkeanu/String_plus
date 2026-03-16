#include <stdio.h>
#include <string.h>

#include "s21_string.h"
#define BUFF_SIZE 400

// gcc -Wall -Werror -Wextra test.c s21_*.c -lm
int main(void) {
  char str1[200];
  char str2[200];
  char* str3 = "%#p Test %#3p Test %#5.7p TEST %#.7p Oof %#.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "8894";
  sprintf(str1, str3, val, val2, val3, val4, val5),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5);

  printf("%s streln %ld\n", str1, strlen(str1));
  printf("%s strlen %ld\n", str2, strlen(str2));

  /*
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-11.11li%-35.5lu%-3.5ld%33.16Lf";
    long double k = 333.33213;

      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k);

    printf("%s\n",str1);
    printf("%s\n",str2);

    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

    s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
    sprintf(str2, format, 1, 222, 33333333333, -166513.1232);

      printf("%s\n",str1);
    printf("%s\n",str2);
  */

  return 0;
}