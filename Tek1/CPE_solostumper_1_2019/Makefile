##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC     =	countwords.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3

NAME    =        ./countwords

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
