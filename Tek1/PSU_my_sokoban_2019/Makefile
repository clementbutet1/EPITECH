##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	my_sokoban.c	\
			count.c 		\
			openmallocmap.c	\
			prepmouv.c 			\
			mouv.c 		\
			mouv2.c 	\
			checkwin.c		\
			error.c		\
			checklose.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./my_sokoban

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lm -lncurses
	rm *.o

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
