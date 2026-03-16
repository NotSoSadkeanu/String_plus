#include "s21_sprintf.h"
// ширина 6 точность 5
//%6.5d, -3015;
//-03015
//-003015

// сейчас str = "hello" мы встретили % вызвалась функция set_specs для
// Обрабатываем спецификаторы, ширину и точность формата
const char *set_specs(Spec *specs, const char *format, va_list *arguments) {
  format = get_specs(
      format,
      specs);  // проверяем наличие спецификаторов после того как встретили %
  format = get_width(format, &specs->width, arguments);  // проверяем ширину 10d
  format = get_precision(format, specs, arguments);  // проверяем точность .2d
  format = get_length(format, specs);  // обрабатываем длину

  // проверка на отрицательную ширину если проходит отрицательное число то
  //  то убираем флаг ширина и ставим флаг минус
  if (specs->width < 0) {
    specs->width = -specs->width;
    specs->minus = 1;
  }
  return format;
}

// Обрабатываем спецификаторы флагов (+, -, 0, пробел и #) поднимаем флаги
const char *get_specs(const char *format, Spec *specs) {
  while (*format) {
    if (*format == '+') {
      specs->plus = 1;
    } else if (*format == '-') {
      specs->minus = 1;
    } else if (*format == '0') {
      specs->zero = 1;
    } else if (*format == ' ') {
      specs->space = 1;
    } else if (*format == '#') {
      specs->hash = 1;
    } else {
      break;  // Выходим из цикла при любом другом символе
    }
    format++;
  }
  // У нас не может быть и плюс и пробел одновременно, и 0 и минус одновременно
  if (specs->plus) specs->space = 0;
  if (specs->minus) specs->zero = 0;

  return format;
}

// Обрабатываем ширину поля
const char *get_width(const char *format, int *width, va_list *arguments) {
  *width = 0;
  // sprintf("%*d" 14, 15);
  if (*format == '*') {  // Если ширина задана звездочкой
    *width = va_arg(*arguments, int);  // вытаскиваем первый аргумент
    format++;
  } else {
    while ('0' <= *format && *format <= '9') {  // Если ширина задана числом
      *width = *width * 10 + (*format - '0');  // переводим из символа в число
      format++;
    }
  }

  return format;
}

// Обрабатываем точность (если присутствует)
// sprintf("%.5d", 155);
const char *get_precision(const char *format, Spec *specs, va_list *arguments) {
  if (*format == '.') {  // Если есть точка, значит есть точность
    specs->dot = 1;  // указываем флаг точности
    specs->zero = (!specs->minus && specs->zero) ? -1 : 0;  // зануляем флаг 0
    format++;
    // считываем число и записываем его в accuracy
    format = get_width(format, &specs->accuracy, arguments);
    if (specs->accuracy == 0) {
      specs->precision_zero = 1;  // Устанавливаем флаг, если точность равна 0
    }
  }

  return format;
}

// Обрабатываем длину (l, h, L)
const char *get_length(const char *format, Spec *specs) {
  if (*format == 'L' || *format == 'l' || *format == 'h') {
    specs->length = *format;
    format++;
  }
  return format;
}