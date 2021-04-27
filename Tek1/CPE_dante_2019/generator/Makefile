##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC     =	src/generator.c		\
			src/create_tab.c 	\
			src/opt_funct.c		\
			src/imperfect_algo.c		\
			src/perfect_algo.c		\

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -g3 -I./include

NAME    =   ./generator

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
