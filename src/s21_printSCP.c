#include <ctype.h>

#include "s21_sprintf.h"

void add_padding(char **str, int space, char padding_char) {
  s21_memset(*str, padding_char, space);
  *str += space;
}

void add_string(char **str, const char *src, int len) {
  s21_strncpy(*str, src, len);
  *str += len;
}

char *print_c(char *str, Spec specs, va_list *arguments) {
  char c =
      (char)va_arg(*arguments, int);
  char temp[2] = {c, '\0'};
  int len = 1;
  int space = (specs.width > len)
                  ? specs.width - len
                  : 0;

  if (!specs.minus) {
    add_padding(&str, space, ' ');
  }

  add_string(&str, temp, 1);

  if (specs.minus) {
    add_padding(&str, space, ' ');
  }

  *str = '\0';
  return str;
}

char *print_s(char *str, Spec specs, va_list *arguments) {
  char *src = va_arg(*arguments, char *);

  if (src == NULL) {
    src = "(null)";
    int len = 6;
    if (!specs.accuracy && !specs.dot) {
      specs.accuracy = 6;
    }
    if (specs.accuracy < len) {
      int space = specs.width;
      add_padding(&str, space, ' ');
    } else {
      if (specs.width > specs.accuracy) {
        add_padding(&str, specs.width - specs.accuracy, ' ');
      }
      add_string(&str, src, len);
    }
  } else {
    int len = s21_strlen(src);
    if (specs.dot) {
      if (specs.accuracy == 0) {
        len = 0;
      } else if (specs.accuracy < len) {
        len = specs.accuracy;
      }
    }

    int space = (specs.width > len) ? specs.width - len : 0;

    if (!specs.minus && space > 0) {
      add_padding(&str, space, ' ');
    }

    if (len > 0) {
      add_string(&str, src, len);
    }

    if (specs.minus && space > 0) {
      add_padding(&str, space, ' ');
    }
  }
  *str = '\0';

  return str;
}
