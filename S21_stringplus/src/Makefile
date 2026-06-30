CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
SRC=*.c
OBJ=$(SRC:.c=.o)
TSRC=s21_test/*.c
TOBJ=$(TSRC:.c=.o)
LIB_NAME=s21_string.a
NAME=s21_string
UNAME=$(shell uname -s)

ifeq ($(UNAME), Linux)
	LIBS=-lcheck -lm -lrt -lpthread -lsubunit
endif
ifeq ($(UNAME), Darwin)
	LIBS=-lcheck
endif

all: $(LIB_NAME)

clean:
	rm -rf $(OBJ) $(TOBJ) s21_string s21_test_gc report coverage.info *.o *.a *.gcda *.gcno

test: $(TOBJ)
	$(CC) $^ $(CFLAGS) -o $(NAME) $(LIBS)
	./$(NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^
	
$(TOBJ): $(TSRC)
	$(CC) $(CFLAGS) -c $^
	mv *.o s21_test

rebuild: clean $(LIB_NAME) test

check_style: 
	@cp ../materials/linters/.clang-format ./
	@clang-format -n *.c *.h
	@clang-format -n s21_test/*.c s21_test/*.h
	@rm -rf .clang-format

fix_style: 
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c *.h
	@clang-format -i s21_test/*.c s21_test/*.h
	@rm -rf .clang-format

gcov_report:
	$(CC) $(CFLAGS) --coverage $(SRC) $(TSRC) $(LIBS) -o s21_test_gc
	./s21_test_gc
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	open report/index.html

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./s21_string