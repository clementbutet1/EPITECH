##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

ASM			=	asm/

COREWAR		= 	corewar/

all:
		make -C $(ASM)
		make -C $(COREWAR)

tests_run:
			make -C $(ASM) tests_run
			make -C $(COREWAR) tests_run

clean:
		make -C $(ASM) clean
		make -C $(COREWAR) clean

fclean:		clean
		make -C $(ASM) fclean
		make -C $(COREWAR) fclean

re:		fclean all