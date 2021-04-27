##
## EPITECH PROJECT, 2019
## CPE_corewar_2019
## File description:
## Makefile
##

SRC     =		src/help.c 		\
				src/op.c 		\
				src/get_file_input.c	\
				src/clean_file.c	\
				src/check_name.c 	\
				src/init_struct.c 	\
				src/init_prog.c 	\
				src/create_file.c	\
				src/magic_int.c		\
				src/recup_other_args.c		\
				src/recup_instru.c	\
				src/recup_params.c	\
				src/add_int_tab.c	\
				src/recup_params.c 		\
				src/create_special_tab_int.c	\
				src/error_label.c		\
				src/instru.c			\
				src/parameter.c			\
				src/label.c				\
				src/encode.c			\
				src/write_core.c		\
				src/binary_and_bytes.c	\
				src/verif.c				\
				src/append.c			\
				src/check_error_dir.c	\
				src/check_label.c		\
				src/check_int_params.c	\
				src/check_condi_magic_int.c		\
				src/error_name.c		\

SHELL	=	bash

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_SRC	=	tests/unit_test.c 		\
				tests/unit_test2.c		\
				tests/unit_test3.c		\
				tests/unit_test4.c		\
				tests/unit_test5.c		\
				tests/unit_test6.c		\
				tests/unit_test7.c		\
				tests/unit_test8.c		\
				tests/unit_test9.c		\
				tests/unit_test10.c		\
				tests/unit_test11.c		\
				tests/unit_test12.c		\
				tests/unit_test13.c		\
				tests/unit_test14.c		\
				tests/unit_test15.c		\

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -pedantic -g3

LFLAGS	=	-L./lib -lmy

TEST_LFLAGS	=	-lcriterion

COVERAGE	=	$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)	\
				$(MAIN_SRC:.c=.gcda)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\

TARGET	=	asm

TARGET_TEST	=	unit_tests

all:	$(TARGET)

$(TARGET) : build_lib build

build_lib:
	@$(MAKE) -C ./lib/my/ --silent
	@cp ./lib/my/libmy.a ./lib/libmy.a
	@cp ./lib/my/my.h ./include/my.h

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

build: $(OBJ) $(MAIN_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@printf "\e[1;33mLinking all object files...\e[0m\n"
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)
	@printf "\e[1;33mLinked all object files\e[0m\n"

clean_lib:
	@$(MAKE) -C ./lib/my/ --silent clean

fclean_lib:
	@$(MAKE) -C ./lib/my/ --silent fclean
	@rm -f lib/libmy.a

clean: clean_lib
	@printf "\e[1;31mRemoving object files...\e[0m\n"
	@rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ)
	@printf "\e[1;31mRemoved object files\e[0m\n"
	@printf "\e[1;31mRemoving coverage files...\e[0m\n"
	@rm -f $(COVERAGE)
	@printf "\e[1;31mRemoved coverage files\e[0m\n"

fclean: fclean_lib clean
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "\e[1;31mRemoved linked binaries\e[0m\n"

re:	fclean all

tests_run: CFLAGS += --coverage
tests_run: build_lib $(OBJ) $(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@printf "\e[1;33mLinking all object files...\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(LFLAGS) $(TEST_LFLAGS)
	@printf "\e[1;33mLinked all object files\e[0m\n"
	@printf "\e[1;32mLaunching tests...\e[0m]\n"
	@./$(TARGET_TEST)

re_tests: fclean tests_run

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests help valgrind
