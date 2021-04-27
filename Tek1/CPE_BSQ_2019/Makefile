##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	bsq.c 	\
		bsq_count.c	\
		error.c		\
		prepare_map.c	\
		algo_bsq.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./bsq

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy
	rm *.o

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -f lib/libmy.a

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all
