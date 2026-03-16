#include "s21_sprintf.h"

int float_counter(long double num, int flag) {
  int counter = 0;
  switch (flag) {
    case 1:
      while ((int)num != 0) {
        num /= 10;
        counter++;
      }
      break;
    case 2:
      if (fabsl(num) > 10) {
        while (fabsl(num) > 10) {
          num /= 10;
          counter++;
        }
      } else if (fabsl(num) < 1) {
        while (fabsl(num) < 1) {
          num *= 10;
          counter--;
        }
      }
      break;
    default:
      break;
  }

  return counter;
}

void add_space_null_e(int *i, Spec specs, char **str, char **str_to_num,
                      bool negative) {
  if (specs.minus) {
    for (int j = 0; j < *i; j++) {
      (*str)[j] = (*str_to_num)[j];
    }
    *str += *i;
    while (*i < specs.width) {
      **str = ' ';
      (*str)++;
      (*i)++;
    }
  } else if (specs.zero && !specs.dot) {
    if (negative && *i < specs.width) {
      (*str_to_num)[0] = '0';
    }
    while (*i < specs.width) {
      for (int j = *i - 1; j >= 0; j--) {
        (*str_to_num)[j + 1] = (*str_to_num)[j];
      }
      (*str_to_num)[0] = '0';
      (*i)++;
    }
    if (negative) {
      (*str_to_num)[0] = '-';
    }

    for (int j = 0; j < *i; j++) {
      (*str)[j] = (*str_to_num)[j];
    }
    *str += *i;
  } else {
    while (*i < specs.width) {
      for (int j = *i - 1; j >= 0; j--) {
        (*str_to_num)[j + 1] = (*str_to_num)[j];
      }
      if (abs(specs.zero) != 1) {
        (*str_to_num)[0] = ' ';
      }
      (*i)++;
    }
    for (int j = 0; j < *i; j++) {
      (*str)[j] = (*str_to_num)[j];
    }
    *str += *i;
  }
}

int fnum_to_string(bool null, Spec specs, long double number,
                   long double n_head, long double n_tail, char *str,
                   bool *negative) {
  long double constant = -9223372036854775807;
  long long int num = (long long int)roundl(number);
  long long int head = (long long int)roundl(n_head);
  long long int tail = (long long int)(n_tail);
  int l = 0;

  if ((num <= (long int)constant) || (!num)) {
    l = 1;
  }

  specs.accuracy = specs.accuracy ? specs.accuracy : 6;
  int i = 0;
  int is_negative = (number < 0);

  if (is_negative) {
    num = -num;
    *negative = true;
  }

  if ((head + tail) == 0) {
    if (specs.precision_zero && specs.dot) {
      str[i++] = '0';
    } else {
      int j = 0;
      do {
        str[i++] = '0';
        j++;
      } while (j < specs.accuracy);
      str[i++] = '.';
      str[i++] = '0';
    }
  } else {
    if ((specs.hash) && (specs.precision_zero)) {
      str[i++] = '.';
    }

    if (l) {
      do {
        str[i++] = (char)((tail % 10) + '0');
        tail /= 10;
      } while (tail > 0);

      while (i < specs.accuracy) {
        str[i++] = '0';
      }
      if (!specs.precision_zero) {
        str[i++] = '.';
      }
      do {
        str[i++] = (char)((head % 10) + '0');
        head /= 10;
      } while (head > 0);

    } else {
      do {
        if ((i == specs.accuracy) && (!specs.precision_zero)) {
          str[i++] = '.';
        }
        str[i++] = (char)((num % 10) + '0');
        num /= 10;
      } while (num > 0);

      if (null) {
        str[i++] = '.';
        str[i++] = '0';
      }
    }

    while ((i < specs.width - 1) && (abs(specs.zero) == 1)) {
      str[i++] = '0';
    }
  }

  if (is_negative) {
    str[i++] = '-';
  } else {
    if (specs.plus) {
      str[i++] = '+';
    }
  }
  if (specs.space && !is_negative && !specs.plus) {
    str[i++] = ' ';
  }

  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }
  return i;
}

int enum_to_string(Spec specs, long double number, char *str, bool *negative,
                   int exp, char symbol) {
  long int num = (long int)round(number);
  int abs_exp = abs(exp);

  int i = 0;
  int is_negative = (num < 0);

  if (is_negative) {
    num = -num;
    *negative = true;
  }

  if (num == 0) {
    str[i++] = '0';
    str[i++] = '0';
    str[i++] = '+';
    str[i++] = symbol;
    if (specs.precision_zero && specs.dot) {
      str[i++] = '0';
    } else {
      specs.accuracy = specs.accuracy ? specs.accuracy : 6;
      int j = 0;
      do {
        str[i++] = '0';
        j++;
      } while (j < specs.accuracy);
      str[i++] = '.';
      str[i++] = '0';
    }
  } else {
    do {
      str[i++] = (char)((abs_exp % 10) + '0');
      abs_exp /= 10;
    } while (abs_exp > 0);
    if (exp < 10) {
      str[i++] = '0';
    }
    str[i++] = exp >= 0 ? '+' : '-';
    str[i++] = symbol;

    if ((specs.hash) && (specs.precision_zero)) {
      str[i++] = '.';
    }

    do {
      str[i++] = (char)((num % 10) + '0');
      num /= 10;
    } while (num > 10);

    if (!specs.precision_zero) {
      str[i++] = '.';
      str[i++] = (char)((num % 10) + '0');
    }

    while ((i < specs.width - 1) && (abs(specs.zero) == 1)) {
      str[i++] = '0';
    }
  }

  if (is_negative) {
    str[i++] = '-';

  } else if (specs.plus) {
    str[i++] = '+';
  } else if (specs.space) {
    str[i++] = ' ';
  }

  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }
  return i;
}

s21_size_t get_size_to_float(Spec *specs, long double num, int exp,
                             const char *format) {
  s21_size_t result = 0;
  long int copy_num = (long int)num;
  int copy_exp = exp;

  if (copy_num < 0) copy_num = -copy_num;

  do {
    copy_num /= 10;
    result++;
  } while (copy_num > 0);

  if ((s21_size_t)specs->accuracy > result) {
    result = specs->accuracy;
  }

  if (copy_exp < 0) copy_exp = -copy_exp;

  if (*format == 'e' || *format == 'E') {
    do {
      copy_exp /= 10;
      result++;
    } while (copy_exp > 0);
    result += 2;
  }

  if (num < 0 || specs->plus || specs->space) {
    specs->flag_to_size = 1;
    result++;
  }

  if ((s21_size_t)specs->width > result) {
    result = specs->width;
  }

  return result;
}

char *print_e(char *str, Spec specs, va_list *arguments, const char *format) {
  int exp = 0;
  char symbol = (*format == 'E') ? 'E' : 'e';
  long double num = (specs.length == 'L')
                        ? va_arg(*arguments, long double)
                        : (long double)va_arg(*arguments, double);

  if (num != 0) exp = float_counter(num, 2);

  int accuracy = 6;

  if (specs.accuracy) {
    accuracy = specs.accuracy;
  }
  if (specs.dot && !specs.accuracy) {
    accuracy = 0;
  }
  if (exp <= 0) {
    num = num * powl(10, (abs(exp) + accuracy));
  }
  if (exp > 0) {
    num = num / powl(10, (abs(exp) - accuracy));
  }

  s21_size_t size = get_size_to_float(&specs, num, exp, format);
  bool negative = 0;
  char *char_number = malloc(sizeof(char) * (size + 25));

  int i = enum_to_string(specs, num, char_number, &negative, exp, symbol);
  add_space_null_e(&i, specs, &str, &char_number, negative);
  free(char_number);

  *str = '\0';
  return str;
}

char *print_float(char *str, Spec specs, va_list *arguments,
                  const char *format) {
  long double num = (specs.length == 'L')
                        ? va_arg(*arguments, long double)
                        : (long double)va_arg(*arguments, double);
  bool null = (num) < 1 && (num > 0) ? true : false;

  int accuracy = 6;

  if (specs.accuracy) {
    accuracy = specs.accuracy;
  }
  if (specs.dot && !specs.accuracy) {
    accuracy = 0;
  }
  long double num_head;
  long double num_tail = modfl(fabsl(num), &num_head) * powl(10, accuracy);

  num *= powl(10, accuracy);

  s21_size_t size = get_size_to_float(&specs, num, 0, format);
  bool negative = 0;
  char *char_number = malloc(sizeof(char) * (size + 25));
  int i = fnum_to_string(null, specs, num, num_head, num_tail, char_number,
                         &negative);

  add_space_null_e(&i, specs, &str, &char_number, negative);
  free(char_number);

  *str = '\0';
  return str;
}