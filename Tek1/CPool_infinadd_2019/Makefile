##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	infinadd.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

NAME    =        ./infin_add

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -g3 -L./lib -lmy

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
