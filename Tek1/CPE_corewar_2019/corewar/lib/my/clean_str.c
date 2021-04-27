/*
** EPITECH PROJECT, 2019
** clean_str.c
** File description:
** clean_str.c
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int check_cara(char c)
{
    if ((c >= 33 && c <= 126)) {
        return (1);
    }
    return (0);
}

char *check_end_space(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    while (check_cara(str[i]) != 1)
        i--;
    i++;
    str[i] = '\0';
    return (str);
}

int check_begin_space(char *str, int i)
{
    for (; str[i] != '\0'; i++) {
        if ((str[i] >= 33 && str[i] <= 126)) {
            return (i);
        }
    }
    return (0);
}

char *check_final(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == '\0')
            str[i] = '\0';
    }
    return (str);
}

char *clean_str(char *str)
{
    int size = my_strlen(str);
    char *rslt = malloc(sizeof(char *) * size + 2);
    int k = 0;
    int i = check_begin_space(str, k);
    str = check_end_space(str);
    int j = 0;

    for (; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' || str[i] == '\t') {
            rslt[j] = ' ';
            i = check_begin_space(str, i);
            j++;
        }
        rslt[j] = str[i];
    }
    rslt[j] = '\0';
    rslt = check_final(rslt);
    return (rslt);
}