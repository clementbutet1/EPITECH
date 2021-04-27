##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	matchstick.c 	\
			map.c	\
			init_game.c	\
			new_map.c 	\
			error.c		\
			check_map.c	\
			ia.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./matchstick

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lm
	rm *.o

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -f lib/libmy.a

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
