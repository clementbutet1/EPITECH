/*
** EPITECH PROJECT, 2019
** opt_funct.c
** File description:
** opt_funct.c
*/

#include "my.h"
#include "generator.h"

void check_error(char **av)
{
    for (int i = 0; av[1][i] != '\0' && av[2][i] != '\0'; i++)
        if ((av[1][i] < '0' || av[1][i] > '9') ||
            (av[2][i] < '0' || av[2][i] > '9'))
            exit (84);
}

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
        return (0);
    else
        return (84);
}
