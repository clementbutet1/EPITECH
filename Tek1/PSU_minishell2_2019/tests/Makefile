##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

SRC     =		unit_test.c 		\
				unit_test2.c 		\
				unit_test3.c		\
				unit_test4.c		\
				unit_test5.c		\
				unit_test6.c		\
				unit_test7.c		\
				unit_test8.c		\
				unit_test9.c		\
				../src/init_struct.c 		\
				../src/exit_prog.c 	\
				../src/env.c 		\
				../src/mysh.c 		\
				../src/clean_str.c 	\
				../src/executable.c 	\
				../src/check_error.c	\
				../src/env_prog.c 		\
				../src/recup_old_pwd.c 	\
				../src/bulltin.c		\
				../src/get_path.c 		\
				../src/cmd_fork.c		\
				../src/cd_funct.c		\
				../src/get_env_elmt.c	\
				../src/redirection.c	\
				../src/setenv_without_env.c	\
				../src/setenv.c		\
				../src/unsetenv.c		\
				../src/check_directory.c 	\
				../src/execute_mysh.c		\
				../src/pipe.c			\
				../src/prepare_pipe.c	\
				../src/cmd_parse.c		\
				../src/new_pipe.c  	\
				../src/redi_pipe.c		\
				../src/open_redi.c 	\

NAME_TEST =	unit_tests

COV     =       $(SRC:.c=.gcno)

CDA     =       $(SRC:.c=.gcda)

OBJ	=	$(SRC:.c=.o) $(U_SRC:.c=.o)

CFLAGS	=	 -I ../include/ --coverage

LDFLAGS	=	 -lcriterion --coverage

tests_run: 	$(OBJ)
		make -C ../lib/my/
		gcc -o $(NAME_TEST) $(OBJ) $(LDFLAGS) -L../lib -lmy -lm
		./unit_tests

clean:
	rm -rf $(OBJ)
	rm -rf ../lib/libmy.a
	rm unit_tests
	rm -rf $(COV)
	rm -rf $(CDA) 
	rm test
	make clean -C ../lib/my

fclean:	clean
	make fclean -C ../lib/my
	rm -f $(NAME)

re:	fclean test_run
