/*
** EPITECH PROJECT, 2019
** clean_str.c
** File description:
** clean_str.c
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *sup_first_space(char *str)
{
    int a = 0;
    int i = 0;

    for (int d = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == '#')
            d = 2;
        if (d == 0 && str[i] != ' ' && str[i] != '\t')
            d = 1;
        if (d == 1) {
            if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' ' &&
                str[i + 1] != '\t' && str[i + 1] != '\0' && str[i + 1] != '\n')
                str[a++] = ' ';
            if (str[i] != ' ' && str[i] != '\t')
                str[a++] = str[i];
        }
    }
    if (str[i] == '\n')
        str[a++] = '\n';
    str[a] = '\0';
    return (str);
}

char *clean_str(char *str)
{
    int size = my_strlen(str);
    int k = 0;
    int j = 0;
    char *new_str;

    str = sup_first_space(str);
    new_str = my_strdup(str);
    free(str);
    return (new_str);
}