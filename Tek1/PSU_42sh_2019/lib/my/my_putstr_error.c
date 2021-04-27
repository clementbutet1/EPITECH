/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_putstr_error.c
*/

#include "my.h"

int my_putstr_error(char const *str)
{
    int i = my_strlen(str);

    write(2, str, i);
    return (0);
}