##
## EPITECH PROJECT, 2019
## CPE_corewar_2019
## File description:
## Makefile
##

SRC     =		src/help.c 					\
				src/arena_init.c 			\
				src/get_arg.c 				\
				src/check_champ.c 			\
				src/my_strdcmp.c 			\
				src/values_of_champs.c		\
				src/instructions/op.c		\
				src/battle_in_arena.c 		\
				src/recup.c 				\
				src/get.c 					\
				src/battle_params.c			\
				src/check_options.c			\
				src/condi.c					\
				src/instru_type_opt.c		\
				src/create_tab_ins.c		\
				src/change_hexa_tab.c		\
				src/convert_tab.c			\
				src/champ_fonc.c			\
				src/check_number_values.c	\
				src/check_magic_nb.c		\
				src/lunch_instr.c			\
				src/instructions/live.c		\
				src/instructions/ld.c 		\
				src/instructions/st.c		\
				src/instructions/add.c 		\
				src/instructions/sub.c		\
				src/instructions/and.c		\
				src/instructions/or.c		\
				src/instructions/xor.c		\
				src/instructions/zjmp.c		\
				src/instructions/ldi.c 		\
				src/instructions/sti.c 		\
				src/instructions/fork.c 	\
				src/instructions/lld.c 		\
				src/instructions/lldi.c 	\
				src/instructions/lfork.c 	\
				src/instructions/aff.c		\

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

TARGET	=	corewar

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
