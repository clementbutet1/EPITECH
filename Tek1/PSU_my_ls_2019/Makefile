##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	my_ls.c	\
			my_simple_ls.c 	\
			my_ls_l.c 	\
			my_right.c 	\
			my_ls_rm.c 	\
			my_ls_lrm.c 	\
			my_ls_t.c 	\
			options.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./my_ls

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
