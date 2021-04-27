##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =		src/navy.c        \
				src/error.c		\
				src/open_read_map.c	\
				src/size_of_the_map.c	\
				src/create_serv.c 	\
				src/signal.c 	\
				src/add_boat_on_map.c 	\
				src/switche_for_values.c 	\
				src/error2.c		\
				src/print_all.c 	\
				src/remove_boat.c	\
				src/send_signal.c 	\
				src/signal_transfer.c 	\
				src/convert_bin_int.c 	\
				src/convert_binary.c	\
				src/player_turn.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =   ./navy

all:    $(NAME)

$(NAME):        $(OBJ)
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
