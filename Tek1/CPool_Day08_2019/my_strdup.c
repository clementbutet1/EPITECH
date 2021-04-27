/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int a = 0;

    while (src[a] != '\0') {
        a++;
    }
    str = malloc(sizeof(char) * (a + 1));
    a = 0;
    while (src[a] != '\0') {
        str[a] = src[a];
        a++;
    }
    str[a] = '\0';
    return (str);
}


