/*
** EPITECH PROJECT, 2020
** my_strdcmp.c
** File description:
** my_strdcmp
*/

#include "my.h"

int my_strendcmp(char *str, char *end)
{
    int i = my_strlen(str) - 1;
    int j = my_strlen(end) - 1;

    for (; str[i] == (end[j]); i--, j--)
        if (j == 0)
            return 1;
    return 0;
}