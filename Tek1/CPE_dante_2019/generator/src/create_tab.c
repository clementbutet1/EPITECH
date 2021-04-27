/*
** EPITECH PROJECT, 2019
** create_tab.c
** File description:
** create_tab.c
*/

#include "my.h"
#include "generator.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
}

void print_map(char **tab, params_t *pa)
{
    int i = 0;

    for (; i < pa->max_height - 1; i++) {
        write(1, tab[i], pa->max_lenght);
        my_putchar('\n');
    }
    tab[i][pa->max_lenght] = '\0';
    write(1, tab[i], pa->max_lenght);
}

char **create_tab(char **tab, params_t *params)
{
    tab = malloc(sizeof(char *) * (params->max_height + 1));
    int i = 0;
    int j = 0;

    for (; i != params->max_height; i++) {
        tab[i] = malloc(sizeof(char) * (params->max_lenght + 2));
        for (j = 0; j != params->max_lenght; j++)
            tab[i][j] = '*';
        tab[i][j] = '\n';
        tab[i][j + 1] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}