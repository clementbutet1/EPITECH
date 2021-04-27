/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
    return (0);
}

void my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i = i + 1;
    }
    my_putchar('\n');
    exit (84);
    return;
}