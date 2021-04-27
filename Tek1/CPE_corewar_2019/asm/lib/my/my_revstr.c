/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** my_revstr
*/

#include "my.h"
#include <stdio.h>
#include <string.h>

char *my_revstr(char *str)
{
    char a;
    int c = 0;
    int i = my_strlen(str) - 1;

    while (c < i) {
        a = str[c];
        str[c] = str[i];
        str[i] = a;
        c++;
        i--;
    }
    return (str);
}
