##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##  Makefile
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_isneg.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcat.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strncpy.c	\
		my_swap.c	\
		my_put_nbr.c	\
		my_getnbr.c	\
		my_str_isnum.c	\
		my_strcmp.c 	\
		my_strdup.c		\
		my_str_tab.c	\
		get_next_line.c		\
		my_itoa.c 		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../libmy.a
	cp my.h ../../include/my.h
	rm *.o
clean:
	rm -f $(OBJ)
	rm -f ../libmy.a

fclean: clean
	rm -f $(NAME)

re:	fclean all

