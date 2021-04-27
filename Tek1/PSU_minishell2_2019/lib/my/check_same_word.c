/*
** EPITECH PROJECT, 2019
** check_same_word.c
** File description:
** check_same_word.c
*/

#include "my.h"

int check_same_word(char *str, char *str1)
{
    int i = 0;
    int size = my_strlen(str);
    int cpt = 0;

    while (str[i] != '\0' || str1[i] != '\0') {
        if (str[i] == str1[i])
            cpt++;
        else if (str[i] != '\0' || str1[i] != '\0')
            return (0);
        i++;
    }
    if (cpt == size)
        return (11);
    else
        return (0);
}