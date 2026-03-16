#include <ctype.h>

#include "s21_sprintf.h"

void add_padding(char **str, int space, char padding_char) {
  s21_memset(*str, padding_char, space);
  *str += space;
}
// Функция копирования строки
void add_string(char **str, const char *src, int len) {
  s21_strncpy(*str, src, len);
  *str += len;
}

// Основная функция для форматирования указателя в шестнадцатеричное
// представление

char *print_c(char *str, Spec specs, va_list *arguments) {
  char c =
      (char)va_arg(*arguments, int);  // Извлекаем символ из списка аргументов
  char temp[2] = {c, '\0'};  // Создаем строку из одного символа

  int len = 1;  // Длина строки с символом
  int space = (specs.width > len)
                  ? specs.width - len
                  : 0;  // Вычисляем количество пробелов для выравнивания

  // Добавляем ведущие пробелы, если ширина указана и флаг minus не установлен
  if (!specs.minus) {
    add_padding(&str, space, ' ');
  }

  // Копируем символ в строку
  add_string(&str, temp, 1);

  // Добавляем завершающие пробелы, если ширина указана и флаг minus установлен
  if (specs.minus) {
    add_padding(&str, space, ' ');
  }

  *str = '\0';  // Завершаем строку нулевым символом
  return str;
}

char *print_s(char *str, Spec specs, va_list *arguments) {
  char *src = va_arg(*arguments, char *);

  // Если указатель на строку равен NULL, используем "(null)"
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
    int len = s21_strlen(src);  // Определяем длину строки

    // Обработка точности
    if (specs.dot) {
      if (specs.accuracy == 0) {
        len = 0;  // Если точность 0, строка должна быть пустой
      } else if (specs.accuracy < len) {
        len = specs.accuracy;  // Обрезаем строку до указанной точности
      }
    }

    int space = (specs.width > len) ? specs.width - len : 0;

    // Если флаг minus не установлен, добавляем пробелы перед строкой
    if (!specs.minus && space > 0) {
      add_padding(&str, space, ' ');
    }

    // Добавляем строку в буфер, если ее длина больше 0
    if (len > 0) {
      add_string(&str, src, len);
    }

    // Если флаг minus установлен, добавляем пробелы после строки
    if (specs.minus && space > 0) {
      add_padding(&str, space, ' ');
    }
  }
  // Завершаем строку нулевым символом
  *str = '\0';

  return str;
}
