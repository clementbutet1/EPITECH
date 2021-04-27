##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	error.c	\
		103cipher.c	\
		encrypted.c	\
		decrypted.c	\
		encrypted_type.c	\
		decrypted_type.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -I./include

NAME    =        ./103cipher

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
