CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OPTION_FLAGS = -g
FOR_GCOV_FLAGS = -fprofile-arcs -ftest-coverage
EXTRA_FLAGS= -lm -lpthread
INCL_GOFLAGS = -lgcov

LIB_NAME = s21_matrix.a
TEST_LIB_NAME = $(addprefix test_, $(LIB_NAME))

GCOV = gcov
GCOV_DIR = gcov_report

ifeq ($(shell uname -p), arm)
		CC = gcc-13
		GCOV = gcov-13

endif

UNAME=$(shell uname -s)

HOW_TO_OPEN = vi
ifeq ($(UNAME), Linux)
		HOW_TO_OPEN = xdg-open
endif
ifeq ($(UNAME), Darwin)
		HOW_TO_OPEN = open
endif


INCL_FLAGS = $(shell pkg-config --cflags check)
INCL_LIBS_FLAGS = $(shell pkg-config --cflags --libs check)

TESTS_DIR = tests
BUILD_DIR = build
BUILD_TEST_DIR = build_tests
TEST_BUILD_DIR = test_build
 
S21_SOURCES = $(wildcard s21_*.c)
TESTS_F = $(wildcard $(TESTS_DIR)/test_*.c)
S21_OBJECTS=$(addprefix $(BUILD_DIR)/, $(S21_SOURCES:.c=.o))
TEST_S21_OBJECTS=$(addprefix $(TEST_BUILD_DIR)/, $(S21_SOURCES:.c=.o))
TEST_OBJECTS=$(addprefix $(BUILD_TEST_DIR)/, $(notdir $(TESTS_F:.c=.o)))

all: $(LIB_NAME) test 

run_test: test
	./test

test: $(TEST_OBJECTS) $(TEST_LIB_NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(INCL_LIBS_FLAGS) $(INCL_GOFLAGS) $(EXTRA_FLAGS)

$(TEST_OBJECTS): $(BUILD_TEST_DIR)/%.o : $(TESTS_DIR)/%.c $(TESTS_DIR)/test_main.h
	@mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(CFLAGS) $(INCL_FLAGS) -c $< -o $@
	
$(TEST_LIB_NAME): $(TEST_S21_OBJECTS)
	ar -rcs $@ $^

$(TEST_S21_OBJECTS): $(TEST_BUILD_DIR)/%.o : %.c $(LIB_NAME:.a=.h)
	@mkdir -p $(TEST_BUILD_DIR)
	$(CC) $(CFLAGS) $(OPTION_FLAGS) $(FOR_GCOV_FLAGS) -c $< -o $@

$(LIB_NAME): $(S21_OBJECTS)
	ar -rcs $@ $^

$(S21_OBJECTS): $(BUILD_DIR)/%.o : %.c $(LIB_NAME:.a=.h)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

gcov: gcov_report
	@$(HOW_TO_OPEN) ./$(GCOV_DIR)/gcov_report.html

gcov_report: $(LIB_NAME) test run_test $(GCOV_DIR)/gcov_report.html

$(GCOV_DIR)/gcov_report.html : $(LIB_NAME) test
	@mkdir -p gcov_report
	gcovr -r . --gcov-executable $(GCOV) --html --html-details -o $(GCOV_DIR)/gcov_report.html

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose ./test

check_style: 
	@cp ../materials/linters/.clang-format ./
	@clang-format -n *.c *.h
	@clang-format -n tests/*.c tests/*.h
	@rm -rf .clang-format

fix_style: 
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c *.h
	@clang-format -i tests/*.c tests/*.h
	@rm -rf .clang-format

clean:
	@rm -rf $(BUILD_DIR) $(GCOV_DIR) $(BUILD_TEST_DIR) $(TEST_BUILD_DIR)
	@rm -rf *.html
	@rm -rf a.out test
	@rm -rf *.a

rebuild : 
	$(MAKE) clean
	$(MAKE) all
