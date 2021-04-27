/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** recup_other_args.c
*/

#include "asm.h"

int check_option_two_byte(char *str)
{
    int status = 0;

    if (check_same_word(str, "zjmp") == 11)
        status = 1;
    if (check_same_word(str, "fork") == 11)
        status = 2;
    if (check_same_word(str, "live") == 11)
        status = 3;
    if (check_same_word(str, "lfork") == 11)
        status = 4;
    return (status);
}

int check_instru(char *str)
{
    int status = 0;

    if (str[0] == 'r')
        status = 1;
    if (str[0] == DIRECT_CHAR)
        status = 3;
    return (status);
}