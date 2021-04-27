/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** copy_tab.c
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char **copy_tab(char **tab)
{
    int size_tab = 0;
    char **new_tab = NULL;
    int i = 0;

    for (; tab[size_tab] != NULL; size_tab++);
    new_tab = malloc(sizeof(char *) * (size_tab + 1));
    for (; tab[i] != NULL; i++) {
        new_tab[i] = my_strdup(tab[i]);
    }
    new_tab[i] = NULL;
    return (new_tab);
}