##
## EPITECH PROJECT, 2020
## undefined
## File description:
## Makefile
##

NAME	=	109titration

SRC	=	109titration.py

all: $(NAME)

$(NAME):
		cp $(SRC) $(NAME)
		chmod 755 $(NAME)
clean:
		rm $(NAME)

fclean: clean

re: clean all

%.o: %.c
		@$(CC) $(CFLAGS) -c -o $@ $<            \
		&& echo "\e[32m[OK] \e[1m" $< "\e[0m"    \
		|| echo "\e[31m[KO] \e[1m" $< "\e[0m"% %