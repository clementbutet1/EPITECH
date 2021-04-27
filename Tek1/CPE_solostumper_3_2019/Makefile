##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC     =	fazzbizz.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3

NAME    =        ./fazzbizz

all:    $(NAME)

$(NAME):        $(OBJ)
	gcc -o  $(NAME) $(OBJ)

clean:
	rm *.o
	rm -f $(OBJ)

fclean:
	make clean
	rm -f $(NAME)

re:     fclean all
