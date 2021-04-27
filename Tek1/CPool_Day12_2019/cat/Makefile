##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	cat.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ../include

NAME    =       cat

all:    $(NAME)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ) -L ../lib/ -lmy

##$(OBJ):	$(SRC)
##	gcc -c $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
