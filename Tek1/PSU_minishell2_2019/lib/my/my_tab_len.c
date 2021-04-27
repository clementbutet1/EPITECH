/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019_orgenise
** File description:
** my_tab_len.c
*/

#include "my.h"
#include <stdio.h>

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}