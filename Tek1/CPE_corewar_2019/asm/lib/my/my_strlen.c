/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen
*/

#include "stdlib.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int my_strlen_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (0);
    while (tab[i] != NULL)
        i++;
    return (i);
}
