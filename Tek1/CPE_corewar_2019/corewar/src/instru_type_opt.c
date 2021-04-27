/*
** EPITECH PROJECT, 2019
** instru_type_opt.c
** File description:
** instru_type_opt.c
*/

#include "corewar.h"

int what_type(char c, int dir_size)
{
    if (c == 'r')
        return (1);
    if (c == 'i')
        return (2);
    if (c == 'd')
        return (dir_size);
    my_putstr_error("Error : bad parameter");
    return (0);
}