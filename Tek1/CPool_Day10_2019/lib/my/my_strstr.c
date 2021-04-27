/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** my_strstr
*/

#include <stdlib.h>

char *my_strstr(char *str, char const *to_find)
{
    int a = 0;
    int b = 0;

    for (;str[a] != '\0'; a++) {
        for (;str[a + b] = to_find[b]; b++) {
            if (b + 1 == '\0')
                return (str + a);
        }
    }
    return (NULL);
}
