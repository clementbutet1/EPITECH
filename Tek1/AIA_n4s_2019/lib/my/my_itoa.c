/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_itoa.c
*/

#include <stdlib.h>

int my_strlen_int(int nb)
{
    int size = 0;

    for (; nb > 0; size++)
        nb /= 10;
    return (size);
}

char *my_itoa(int nb)
{
    int size = my_strlen_int(nb);
    char *str = NULL;

    str = malloc(sizeof(*str) * (size + 1));
    size--;
    for (; size != -1; size--) {
        str[size] = nb % 10 + '0';
        nb /= 10;
    }
    str[size] = '\0';
    return (str);
}