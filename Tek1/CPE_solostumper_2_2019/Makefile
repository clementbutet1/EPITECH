##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC     =	rostring.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3

NAME    =        ./rostring

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
