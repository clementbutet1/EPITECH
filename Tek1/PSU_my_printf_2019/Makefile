##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	./src/converthexadecimalma.c	\
		./src/convertoctal.c	\
		./src/my_printf.c		\
		./src/printf2.c		\
		./src/converthexadecimalmi.c	\
		./src/my_convertbinaire.c		\
		./src/my_putchar.c	\
		./src/my_put_nbr.c	\
		./src/my_putstr.c		\
		./src/printflagsu.c		\
		./src/printflagsp.c		\
		./src/printflagss.c		\

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: 	re clean fclean all
