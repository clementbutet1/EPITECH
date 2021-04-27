##
## EPITECH PROJECT, 2018
## Project mysh
## File description:
## Unit Testing.
##

SRC     =		../mysh.c 	\
				../other/exit_prog.c 	\
				../other/my_str_tab.c 	\
				../other/clean_str.c		\
				../funct_cmd.c 	\
				../other/check_space.c 	\
				../other/opt_funct.c 	\
				../funct_cd.c 		\
				../bulltin.c		\
				../env.c	\
				../get_env_elmt.c 	\
				../other/other_funct.c 	\
				../unsetenv.c		\
				../setenv.c	\

U_SRC	=	unit_test.c		\

NAME_TEST = unit_test

OBJ	=	$(SRC:.c=.o) $(U_SRC:.c=.o)

CFLAGS	=	 -I ../include/

LDFLAGS	=	-lcriterion -lgcov

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) -L../lib -lmy -lm

tests_run: 	$(OBJ)
		make -C ../lib/my/
		gcc -o $(NAME_TEST) unit_test.c ../unsetenv.c ../setenv.c ../get_env_elmt.c ../funct_cmd.c ../funct_cd.c ../env.c ../bulltin.c ../other/other_funct.c ../other/opt_funct.c ../other/my_str_tab.c ../other/exit_prog.c ../other/clean_str.c ../other/check_space.c $(LDFLAGS) -L../lib -lmy -lm
		./unit_test
		rm *.o

clean:
	rm ./unit_test
	rm -f $(OBJ)
	rm -f ../lib/libmy.a
	make clean -C ../lib/my

fclean:	clean
	make fclean -C ../lib/my
	rm -f $(NAME)

re:	fclean all
