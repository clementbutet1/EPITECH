/*
** EPITECH PROJECT, 2019
** print_tab.c
** File description:
** print_tab.c
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}