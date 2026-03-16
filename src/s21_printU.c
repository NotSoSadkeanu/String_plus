#include "s21_sprintf.h"

// Устанавливаем систему счисления и регистр для вывода
Spec set_number_system(Spec specs, char format) {
  if (format == 'o')
    specs.number_system = 8;
  else if (format == 'x' || format == 'X')
    specs.number_system = 16;
  if (format == 'X') specs.upper_case = 1;
  return specs;
}

// Функция для преобразования unsigned чисел в строку и форматирования
char *print_u(char *str, Spec specs, va_list *arguments) {
  unsigned long int num = 0;

  // Определяем тип целочисленного аргумента
  if (specs.length == 'l') {
    num = va_arg(*arguments, unsigned long int);
  } else if (specs.length == 'h') {
    num = (unsigned short)va_arg(*arguments, unsigned int);
  } else {
    num = va_arg(*arguments, unsigned int);
  }

  // Вычисляем необходимый размер буфера
  s21_size_t size_to_num = get_buf_size_unsigned_decimal(&specs, num);
  char *str_to_num = malloc(sizeof(char) * (size_to_num + 25));
  if (str_to_num == s21_NULL) {
    return s21_NULL;
  }

  int i = decimal_to_base(num, specs, str_to_num);
  add_space_null(&i, specs, &str, &str_to_num, false);
  // Завершаем строку нулевым символом
  *str = '\0';
  free(str_to_num);

  return str;  // Возвращаем указатель на обновленную строку
}

char *print_p(char *str, void *pointer, Spec specs) {
  char *result;
  int total_len;
  bool flag = false;

  // Вычисляем необходимый размер буфера
  s21_size_t buffer_size =
      get_buf_size_unsigned_decimal(&specs, (unsigned long)pointer);
  result = (char *)malloc(buffer_size + 25);  // +1 для нулевого символа

  if (result == s21_NULL) {
    // Обработка ошибки выделения памяти
    return s21_NULL;
  }

  if (pointer == s21_NULL) {
    s21_strncpy(result, "(nil)", 5);
    total_len = 5;  // Длина "(nil)"
  } else {
    // Преобразуем адрес в шестнадцатеричную строку с использованием
    // decimal_to_base
    Spec temp_specs = specs;
    temp_specs.number_system =
        16;  // Устанавливаем систему счисления для шестнадцатеричной
    temp_specs.upper_case = 0;  // Устанавливаем нижний регистр
    temp_specs.hash = 0;  // Устанавливаем нижний регистр

    int hex_len = decimal_to_base((unsigned long)pointer, temp_specs, result);
    result[hex_len] = '\0';  // Завершаем строку нулевым символом

    total_len = hex_len + 2;  // Длина с учетом "0x"

    for (int i = hex_len - 1; i >= 0; i--) {
      result[i + 2] = result[i];
    }
    result[0] = '0';
    result[1] = 'x';
  }
  if (specs.plus && !pointer == 0) {
    s21_memmove(result + 1, result, total_len);
    result[0] = '+';
    total_len++;
  } else if (specs.space && !pointer == 0) {
    s21_memmove(result + 1, result, total_len);
    result[0] = ' ';
    total_len++;
  }
  // Вычисляем отступ
  add_space_null(&total_len, specs, &str, &result, flag);

  *str = '\0';  // Завершаем строку н
  // Освобождаем динамически выделенную память
  free(result);

  return str;
}

// Пример функции для преобразования десятичного числа в строку в любой системе
// счисления
int decimal_to_base(unsigned long int num, Spec spec, char *str_to_num) {
  const char *digits =
      spec.upper_case ? "0123456789ABCDEF" : "0123456789abcdef";
  int index = 0;

  if (num == 0) {
    if (spec.precision_zero && spec.dot) {
      // Если точность установлена в 0 и число равно 0, и если есть флаги
      // пробела или плюса
      if (spec.hash > 0 && spec.number_system == 8) {
        str_to_num[index++] = '0';
      }
      return index;
    }
    if (spec.accuracy > 0) {
      while (index < spec.accuracy) {
        str_to_num[index++] = '0';
      }
    } else {
      str_to_num[index++] = '0';
    }
  } else {
    // Преобразуем число в строку с учетом точности
    while (num > 0) {
      int remainder = num % spec.number_system;
      str_to_num[index++] = digits[remainder];
      num /= spec.number_system;
    }

    if (spec.hash > 0 && spec.number_system == 8) {
      str_to_num[index++] = '0';
    }

    // Добавляем ведущие нули до указанной точности
    while (index < spec.accuracy) {
      str_to_num[index++] = '0';
    }

    if ((spec.hash > 0 && spec.number_system == 16) &&
        !(spec.zero && !spec.dot)) {
      str_to_num[index++] = spec.upper_case ? 'X' : 'x';
      str_to_num[index++] = '0';
    }
  }

  // Разворачиваем строку, чтобы получить правильный результат
  for (int i = 0; i < index / 2; i++) {
    char temp = str_to_num[i];
    str_to_num[i] = str_to_num[index - 1 - i];
    str_to_num[index - 1 - i] = temp;
  }

  return index;
}

// Пример функции для вычисления размера буфера для unsigned чисел
s21_size_t get_buf_size_unsigned_decimal(Spec *specs, unsigned long int num) {
  s21_size_t result = 0;
  unsigned long int copy_num = num;

  do {
    copy_num /= specs->number_system;
    result++;
  } while (copy_num > 0);

  if ((s21_size_t)specs->accuracy > result) {
    result = specs->accuracy;
  }

  if ((s21_size_t)specs->width > result) {
    result = specs->width;
  }

  return result;
}
