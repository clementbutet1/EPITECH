/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlenb(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int size1 = 0;
    int size2 = 0;
    size1 = my_strlenb(dest);
    size2 = my_strlenb(src);
    char *final = malloc(sizeof(char *) * size1 + size2 + 1);
    int j = 0;
    int k = 0;

    for (int i = 0; dest[i] != '\0'; i++) {
        final[k] = dest[i];
        k++;
    }
    while (src[j] != '\0') {
        final[k] = src[j];
        j++;
        k++;
    }
    final[k] = '\0';
    return (final);
}