##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC     =	src/solver.c 	\
			src/create_tab.c 	\
			src/error.c 	\
			src/resolve.c 	\

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -g3 -I./include

NAME    =   ./solver

all:    $(NAME)
$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lm
	mkdir obj
	mv src/*.o obj/

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -rf obj
	rm -f lib/libmy.a

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
