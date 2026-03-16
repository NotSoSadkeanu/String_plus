CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
CFLAGS_TEST = -fprofile-arcs -ftest-coverage
VALGRIND = valgrind --track-origins=yes --log-file=test/valgrind.log --tool=memcheck --leak-check=yes 

LIBRARY = s21_string.a
ADD_LIB = -L. -l:s21_string.a -lcheck -lm -lsubunit

SRCS := $(wildcard s21_*.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

TEST_SRCS := $(wildcard test/*.c)
TEST_OBJS := $(patsubst %.c,%.o,$(TEST_SRCS))

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIBRARY) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o test/test_string $(TEST_OBJS) $(ADD_LIB)
	$(VALGRIND)./test/test_string

gcov_report: CFLAGS += $(CFLAGS_TEST)
gcov_report: $(LIBRARY) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o test/test_string $(TEST_OBJS) $(ADD_LIB)
	./test/test_string || true
	lcov -c -i -d . -o s21_base.info
	lcov -c -d . -o s21_test.info
	lcov -a s21_base.info -a s21_test.info -o s21_total.info
	genhtml s21_total.info --legend -o report
	xdg-open report/index.html || open report/index.html

clean:
	rm -f $(OBJS) $(LIBRARY) $(TEST_OBJS) test/test_string
	rm -f test/*.log
	rm -f $(wildcard *.gcda *.gcno)
	rm -f $(wildcard test/*.gcda test/*.gcno)
	rm -rf *.info report

.PHONY: all test gcov_report clean
