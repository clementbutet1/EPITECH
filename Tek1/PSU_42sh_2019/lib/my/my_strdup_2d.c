/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_strdup_2d.c
*/

#include "my.h"

char **my_strdup_2d(char **tb)
{
    char **new;
    int i = 0;

    for (i; tb[i] != NULL; i++);
    new = malloc(sizeof(char *) * (i + 1));
    for (i = 0; tb[i] != NULL; i++)
        new[i] = my_strdup(tb[i]);
    new[i] = NULL;
    return (new);
}