##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	evalexpr.c	\
		my_put_nbr.c	\
		calculope.c	\
		my_line_analyse.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./calc

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
