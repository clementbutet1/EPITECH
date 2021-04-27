/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** add_int_tab.c
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *add_two_tab_int(int *tab, int *tab2)
{
    int size_taba = 0;
    int size_tabb = 0;
    int *rslt = 0;
    int i = 0;

    for (; tab[size_taba] != -1; size_taba++);
    for (; tab2[size_tabb] != -1; size_tabb++);
    rslt = malloc(sizeof(int) * (size_taba + size_tabb + 1));
    for (; tab[i] != -1; i++)
        rslt[i] = tab[i];
    for (int k = 0; tab2[k] != -1; i++, k++)
        rslt[i] = tab2[k];
    rslt[i] = -1;
    free(tab);
    free(tab2);
    return (rslt);
}