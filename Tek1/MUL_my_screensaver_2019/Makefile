##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	my_screensaver.c	\
		firstsceensaver.c	\
		secondscreensaver.c	\
		thirdscreensaver.c	\
		buffer.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./my_screensaver

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lcsfml-graphics
	rm -f *.o

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
