##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	ope.c		\
		my_put_nbr.c	\
		cacul.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

NAME    =        do-op

all:    $(NAME)

$(NAME):        $(OBJ)
	cd lib/my && make && cd ../../
	gcc -o $(NAME) $(OBJ) -L./lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
