##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	mysh.c 	\
			other/exit_prog.c 	\
			other/my_str_tab.c 	\
			other/clean_str.c		\
			funct_cmd.c 	\
			other/check_space.c 	\
			other/opt_funct.c 	\
			funct_cd.c 		\
			bulltin.c		\
			env.c	\
			get_env_elmt.c 	\
			other/other_funct.c 	\
			unsetenv.c		\
			setenv.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./mysh

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lm
	rm *.o

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -f lib/libmy.a

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
