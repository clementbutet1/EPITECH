##
## EPITECH PROJECT, 2019
## PSU_my_ls_2019
## File description:
## Makefile
##

SRC	=	src/cd_tiret.c				\
		src/check_buffer.c			\
		src/check_buffer2.c			\
		src/check_env.c 			\
		src/check_setenv.c  		\
		src/check_unsetenv.c 		\
		src/check_echo.c			\
		src/clean_str.c 			\
		src/create_exe.c 			\
		src/create_path.c 			\
		src/create_alias_tab.c		\
		src/execute_funct.c  		\
		src/handler_signal.c  		\
		src/init_sh.c 				\
		src/my_cd.c 				\
		src/mystrcat.c 				\
		src/redirection_funct.c 	\
		src/rempl_env.c 			\
		src/tools.c 				\
		src/usefull_file2.c			\
		src/usefull_fonction.c		\
		src/check_repeat.c			\
		src/check_global.c			\
		src/check_where.c			\
		src/check_wich.c			\
		src/check_alias.c			\
		src/boucl_inf.c				\
		src/history.c				\
		src/check_history.c			\
		src/check_redir.c			\
		src/sub_alias_file.c		\
		src/check_unalias.c			\
		src/check_double_pipe.c		\
		src/wait_pid.c				\
		src/parenth.c				\
		src/check_double_and.c		\
		src/foreach.c				\
		src/check_builtin.c			\
		src/foreach_error.c			\
		src/verif_aliastab.c		\
		src/prepare_set.c			\
		src/check_set.c				\
		src/check_unset.c			\


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
				tests/unit_test16.c		\
				tests/unit_test17.c		\
				tests/unit_test18.c		\
				tests/unit_test19.c		\
				tests/unit_test20.c		\
				tests/unit_test21.c		\
				tests/unit_test22.c		\
				tests/unit_test23.c		\
				tests/unit_test24.c		\
				tests/unit_test25.c		\
				tests/unit_test26.c		\
				tests/unit_test27.c		\
				tests/unit_test28.c		\
				tests/unit_test29.c		\
				tests/unit_test30.c		\
				tests/unit_test31.c		\
				tests/unit_test32.c		\
				tests/test_project.c	\
				tests/other_test/test_wait_pid.c		\

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -g3

LFLAGS	=	-L./lib -lmy -lncurses

TEST_LFLAGS	=	-lcriterion

COVERAGE	=	$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)	\
				$(MAIN_SRC:.c=.gcda)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\

TARGET	=	42sh

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