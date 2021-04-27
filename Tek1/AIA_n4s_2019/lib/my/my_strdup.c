/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy1(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\n') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

char *my_strdup(char *src)
{
    int a = my_strlen(src);
    char *dest = malloc(sizeof(char) * my_strlen(src) + 4);

    my_strcpy1(dest, src);
    return (dest);
}