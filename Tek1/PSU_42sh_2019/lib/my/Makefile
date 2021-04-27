##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

AR	=	ar rc

RM	=	rm -f

NAME 	=	libmy.a

CP	=	cp $(NAME) ../

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CP)

clean:
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) $(OBJ)

fclean:	clean