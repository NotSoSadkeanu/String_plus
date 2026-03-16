#ifndef SRC_S21_SPRINTF_H
#define SRC_S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

typedef struct s21_sprintf {
  int minus;  // к левому краю
  int plus;   // знак
  int space;  // +символ под знак
  int hash;  // вывод 16 и 8 ричных числе в формате 0х и 0
  int zero;  // заполнять свободное пространство не пробелами а 0
  int width;          // ширина
  int accuracy;       // точность
  char length;        // тип переменной (lf, Lf, Ld, и тд)
  int number_system;  // система счисления
  int flag_to_size;  // если число отрицательное или есть + или space
  int dot;  // наличие точки говорит о наличии точности в числе
  int upper_case;  // если спецификатор буква в верхнем регистре
  int precision_zero;  // флаг для особого случая с точностью;
  int g;               // спецификатор г
  int e;  // если необходимо записать число в научной натации
} Spec;
/** @param параметр str это С строка в которую запишется форматированный вывод
 * @param format это С строка содержащая один или несколько следующих элементов
 * пробельные символы непробельный символы и спецификаторы формата
 * спецификатор формата для печатающих функций следует прототипу %[флаги]
 * [ширина] [точность] [длина] [спецификатор]
 * @param ... представляет другие параметры такие как ширина, точность, длина и
 * спецификатор
 * @return функция sprintf имеет возвращающий целочисленный тип в случае успеха
 * функция возвращает количество символов записанных в буфер за исключением
 * заверщающего нулевого символа. в случае ошибки функция возвращает
 * отрицательный целочисленные значения printf("hello %d%d%f%c", 148,123,2.0,
 * 's') где то что "" это format а то что после это ... ???
 */

int s21_sprintf(char *str1, const char *format, ...);

const char *set_specs(Spec *specs, const char *format, va_list *arguments);
const char *get_specs(const char *format, Spec *specs);
const char *get_width(const char *format, int *width, va_list *arguments);
const char *get_precision(const char *format, Spec *specs, va_list *arguments);
const char *get_length(const char *format, Spec *specs);

char *parser(char *str, char *src, const char *format, Spec specs,
             va_list *arguments);
char *print_decimal(char *str, Spec specs, va_list *arguments);
int decimal_to_string(Spec specs, long int num, char *str_to_num,
                      bool *negativ);
s21_size_t get_size_to_decimal(Spec *specs, long int num);
void add_space_null(int *i, Spec specs, char **str, char **str_to_num,
                    bool negative);

char *print_c(char *str, Spec specs, va_list *arguments);
char *print_p(char *str, void *pointer, Spec specs);
char *print_s(char *str, Spec specs, va_list *arguments);
void add_string(char **str, const char *src, int len);
void add_padding(char **str, int space, char pad_char);

Spec set_number_system(Spec specs, char format);
char *print_u(char *str, Spec specs, va_list *arguments);
s21_size_t get_buf_size_unsigned_decimal(Spec *specs, unsigned long int num);
int decimal_to_base(unsigned long int num, Spec spec, char *str_to_num);

// L f e E
char *print_float(char *str, Spec specs, va_list *arguments,
                  const char *format);
char *print_e(char *str, Spec specs, va_list *arguments, const char *format);
int float_counter(long double num, int flag);
s21_size_t get_size_to_float(Spec *specs, long double num, int exp,
                             const char *format);
int enum_to_string(Spec specs, long double number, char *str, bool *negative,
                   int exp, char symbol);
int fnum_to_string(bool null, Spec specs, long double number,
                   long double n_head, long double n_tail, char *str,
                   bool *negative);
void add_space_null_e(int *i, Spec specs, char **str, char **str_to_num,
                      bool negative);

#endif