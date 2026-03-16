#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char specificators[] = "duoxXcpsEenfi%";
  // изначальное положение str записываем в src чтобы узнать сколько символов мы
  // записали
  char *src = str;
  va_list arguments;
  va_start(arguments, format);
  // s21_sprintf(str1, "hello 4+-014.6d %d %f %c", 148, 129, 2.0, 's');
  while (*format) {  // пока не достигним \0 в формате
    if (*format == '%') {  // если встречаем %
      format++;
      Spec specs = {0};  // нашей структуре присваиваем всем переменный 0
      specs.number_system = 10;  // система счисления десятичная
      format =
          set_specs(&specs, format,
                    &arguments);  // функция которая обрабатывает спецификаторы
                                  // тоесть + - 0 ширина точность
      // мы распарсили наши флаги на данный момент у мы подошли к "d"
      while (!s21_strchr(specificators, *format))
        format++;  // бегаем по строке пока не найдем нашу "d" по логике сразу
                   // натыкаемся на него
      // включаем наш парсер который будет записывать в нашу строку
      str = parser(str, src, format, specs, &arguments);
    } else {  // если не встретили процент то записали символ в строку str
              // тоесть запишется hello
      *str = *format;
      str++;
    }
    format++;
  }
  *str = '\0';
  va_end(arguments);
  return (str - src);
}

char *parser(char *str, char *src, const char *format, Spec specs,
             va_list *arguments) {
  if (*format == 'd' || *format == 'i') {
    str = print_decimal(str, specs, arguments);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    specs = set_number_system(specs, *format);
    str = print_u(str, specs, arguments);
  } else if (*format == 'f') {
    str = print_float(str, specs, arguments, format);
  } else if ((*format == 'e') || (*format == 'E')) {
    str = print_e(str, specs, arguments, format);
  } else if (*format == 'c') {
    str = print_c(str, specs, arguments);
  } else if (*format == 'p') {
    void *pointer = va_arg(*arguments, void *);
    str = print_p(str, pointer, specs);
  } else if (*format == 's') {
    str = print_s(str, specs, arguments);
  } else if (*format == 'n') {
    int *count = va_arg(*arguments, int *);
    *count = str - src;
  } else if (*format == '%') {
    *str = '%';
    str++;
  } else {
    str = s21_NULL;
  }
  if (!str) *src = '\0';
  return str;
}