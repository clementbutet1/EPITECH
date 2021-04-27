##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC  	=	/src/main.c

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -g3 -I./include

NAME    =   ./ai

all:    $(NAME)
$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lm

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -rf obj
	rm -f lib/libmy.a

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all