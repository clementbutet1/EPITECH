/*
** EPITECH PROJECT, 2019
** check_options.c
** File description:
** check_options.c
*/

#include "corewar.h"

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

int check_dir_size(char *str)
{
    char *two_byte[] = {"lfork", "lldi", "fork", "sti", "ldi", "zjmp"};
    int a = DIR_SIZE;

    for (int i = 0; i < 6; i++) {
        if (my_strcmp(two_byte[i], str) == 0)
            a = 2;
    }
    return (a);
}

int check_type(char *str, char *cmp, int *len)
{
    if (my_strncmp(str, cmp, 2) == 0) {
        *len = 1 + *len;
        return (1);
    }
    return (0);
}

void option_two_byte(instru_t *instru)
{
    instru->tab_ins = malloc(sizeof(int *) * 4);
    instru->params[0] = 'd';
}