##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =		src/main.c 	\
				src/init_struct.c 		\
				src/exit_prog.c 	\
				src/env.c 		\
				src/mysh.c 		\
				src/clean_str.c 	\
				src/executable.c 	\
				src/check_error.c	\
				src/env_prog.c 		\
				src/recup_old_pwd.c 	\
				src/bulltin.c		\
				src/get_path.c 		\
				src/cmd_fork.c		\
				src/cd_funct.c		\
				src/get_env_elmt.c	\
				src/redirection.c	\
				src/setenv_without_env.c	\
				src/setenv.c		\
				src/unsetenv.c		\
				src/check_directory.c 	\
				src/execute_mysh.c		\
				src/pipe.c			\
				src/prepare_pipe.c	\
				src/cmd_parse.c		\
				src/new_pipe.c  	\
				src/redi_pipe.c		\
				src/open_redi.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./mysh

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lm

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -f lib/libmy.a

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
