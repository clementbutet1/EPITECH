##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

CFLAGS += -Ilib

SRC		=	./rush3.c

SRC_LIB		=	lib/rush3_bis.c		\
			lib/my_putnbr.c		\
			lib/my_putstr.c		\
			lib/my_putchar.c

OBJ		=	$(SRC:.c=.o)

OBJ_LIB		=	$(SRC_LIB:.c=.o)

NAME		=	rush3

NAME_LIB	=	lib/libmy.a

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_LIB)
	ar rc $(NAME_LIB) $(OBJ_LIB)
	gcc -o $(NAME) rush3.c -L lib/ -lmy -I include

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_LIB)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_LIB)

re:	fclean all
