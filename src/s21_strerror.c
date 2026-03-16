#include "s21_strerror.h"

#include "s21_string.h"

char *s21_strerror(int errnum) {
  const char **strerrors;

#if defined(__linux__)
  strerrors = strerrors_linux;
#elif defined(__APPLE__)
  strerrors = strerrors_mac;
#endif

  return (char *)strerrors[errnum];
}
