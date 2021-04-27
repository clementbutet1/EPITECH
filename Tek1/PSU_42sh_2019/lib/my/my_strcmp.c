/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** comp two string
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}

int my_strcmp_alias(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\t') && (s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}