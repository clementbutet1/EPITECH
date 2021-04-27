##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##  Makefile
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcat.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_swap.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../libmy.a
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all 

