/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** my_strncpy
*/

#include "my.h"
#include "stdlib.h"

char *my_strncpy(char const *src, int n)
{
    int a = 0;
    char *dest = malloc(sizeof(char) * (n + 1));

    if (n == 0)
        return (NULL);
    while (a < n) {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

char *my_strncpy_spe(char *dest, char const *src, int n)
{
    int a = 0;

    while (a <= n) {
        dest[a] = src[a];
        dest[a + 1] = '\0';
        a++;
    }
    return (dest);
}
