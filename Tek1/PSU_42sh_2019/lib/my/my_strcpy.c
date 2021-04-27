/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** my_strcpy
*/

#include "my.h"

char* my_strcpy(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;

    for (; str[i] != '\0'; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    return tmp;
}