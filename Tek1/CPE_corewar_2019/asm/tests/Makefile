##
## EPITECH PROJECT, 2019
## CPE_corewar_2019
## File description:
## Makefile
##

SRC     =		unit_test.c 		\
				unit_test2.c		\
				unit_test3.c		\
				unit_test4.c		\
				unit_test5.c		\
				unit_test6.c		\
				unit_test7.c		\
				unit_test8.c		\
				unit_test9.c		\
				unit_test10.c		\
				../src/help.c 		\
				../src/op.c 		\
				../src/get_file_input.c	\
				../src/clean_file.c	\
				../src/check_name.c 	\
				../src/init_struct.c 	\
				../src/init_prog.c 	\
				../src/create_file.c	\
				../src/magic_int.c		\
				../src/recup_other_args.c		\
				../src/recup_instru.c	\
				../src/recup_params.c	\
				../src/add_int_tab.c	\
				../src/recup_params.c 		\
				../src/create_special_tab_int.c	\
				../src/error_label.c		\
				../src/instru.c			\
				../src/parameter.c			\
				../src/label.c				\
				../src/encode.c			\
				../src/write_core.c		\
				../src/binary_and_bytes.c	\
				../src/verif.c				\
				../src/append.c				\


NAME_TEST =	unit_tests

OBJ	=	$(SRC:.c=.o) $(U_SRC:.c=.o)

COV     =       $(SRC:.c=.gcno)

CDA     =       $(SRC:.c=.gcda)

CFLAGS	=	 -I ../include/ --coverage

LDFLAGS	=	 -lcriterion --coverage -pedantic

tests_run: 	$(OBJ)
		make -C ../lib/my/
		gcc -o $(NAME_TEST) $(OBJ) $(LDFLAGS) -L../lib -lmy -lm
		./unit_tests

clean:
	rm -rf $(OBJ)
	rm -rf $(COV)
	rm -rf $(CDA)
	rm -rf ../lib/libmy.a
	rm unit_tests
	make clean -C ../lib/my

fclean:	clean
	make fclean -C ../lib/my
	rm -f $(NAME)

re:	fclean test_run