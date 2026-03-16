#include "s21_sprintf.h"

char *print_decimal(char *str, Spec specs, va_list *arguments) {
  long int num = 0;
  bool negative = false;
  if (specs.length == 'l') {
    num = va_arg(*arguments, long int);
  } else if (specs.length == 'h') {
    num = (short)va_arg(*arguments, int);
  } else {
    num = va_arg(*arguments, int);
  }

  s21_size_t size_to_decimal = get_size_to_decimal(&specs, num);

  char *str_to_num = malloc(sizeof(char) * (size_to_decimal + 25));
  if (!str_to_num) return NULL;

  int i = decimal_to_string(specs, num, str_to_num, &negative);
  add_space_null(&i, specs, &str, &str_to_num, negative);
  *str = '\0';
  free(str_to_num);

  return str;  // Возвращаем указатель на обновленную строку
}

s21_size_t get_size_to_decimal(Spec *specs, long int num) {
  s21_size_t result = 0;
  long int copy_num = num;

  // Если число отрицательное, преобразуем его в положительное для подсчета цифр
  if (copy_num < 0) copy_num = -copy_num;

  // Считаем количество цифр в числе
  do {
    copy_num /= 10;
    result++;
  } while (copy_num > 0);

  // Учитываем точность
  if ((s21_size_t)specs->accuracy > result) {
    result = specs->accuracy;
  }

  // Учитываем отрицательный знак или флаги плюса/пробела
  if (num < 0 || specs->plus || specs->space) {
    specs->flag_to_size = 1;
    result++;
  }

  // Учитываем ширину
  if ((s21_size_t)specs->width > result) {
    result = specs->width;
  }

  return result;
}

int decimal_to_string(Spec specs, long int num, char *str_to_num,
                      bool *negative) {
  int i = 0;
  int is_negative = (num < 0);

  // Если число отрицательное, делаем его положительным для дальнейшего
  // преобразования
  if (is_negative) {
    num = -num;
    *negative = true;
  }

  // Обработка специального случая для числа 0 с точностью > 0
  if (num == 0) {
    if (specs.precision_zero && specs.dot) {
      // Если точность установлена в 0 и число равно 0, и если есть флаги
      // пробела или плюса
      if (specs.plus) {
        str_to_num[i++] = '+';
      } else if (specs.space) {
        str_to_num[i++] = ' ';
      }
      return i;
    }

    // Если точность задана, заполняем нулями до указанной точности
    if (specs.accuracy > 0) {
      while (i < specs.accuracy) {
        str_to_num[i++] = '0';
      }
    } else {
      str_to_num[i++] = '0';
    }
  } else {
    // Преобразуем число в строку с учетом точности
    do {
      str_to_num[i++] = (char)((num % 10) + '0');
      num /= 10;
    } while (num > 0);

    // Добавляем ведущие нули до указанной точности
    while (i < specs.accuracy) {
      str_to_num[i++] = '0';
    }
  }

  // Добавляем отрицательный знак, плюс или пробел
  if (is_negative) {
    str_to_num[i++] = '-';

  } else if (specs.plus) {
    str_to_num[i++] = '+';
  } else if (specs.space) {
    str_to_num[i++] = ' ';
  }

  // Разворачиваем строку
  for (int j = 0; j < i / 2; j++) {
    char temp = str_to_num[j];
    str_to_num[j] = str_to_num[i - j - 1];
    str_to_num[i - j - 1] = temp;
  }

  return i;  // Возвращаем длину строки
}
void add_space_null(int *i, Spec specs, char **str, char **str_to_num,
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
    if (specs.hash > 0 && specs.number_system == 16) {
      (*str_to_num)[1] = specs.upper_case ? 'X' : 'x';
      (*str_to_num)[0] = '0';
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
      (*str_to_num)[0] = ' ';
      (*i)++;
    }
    for (int j = 0; j < *i; j++) {
      (*str)[j] = (*str_to_num)[j];
    }
    *str += *i;
  }
}
