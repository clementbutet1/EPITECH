/*
** EPITECH PROJECT, 2019
** solver.c
** File description:
** solver.c
*/

#include "my.h"
#include "solver.h"

void free_tab(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void init_struct(params_t *params)
{
    params->max_height = 0;
    params->max_lenght = 0;
    params->map = NULL;
    params->buffer = NULL;
}

int main(int ac, char **av)
{
    params_t params;

    if (ac != 2)
        return (84);
    init_struct(&params);
    fs_open_file(av[1], &params);
    check_error(&params);
    if (params.buffer[0] == 'X' || params.buffer[params.size - 1] == 'X') {
        my_putstr("no solution found");
        free(params.buffer);
        free_tab(params.map);
        return (0);
    } else {
        (algo(&params, 0) == 1) ? write(1, params.buffer, params.size) :
        my_putstr("no solution found");
        free(params.buffer);
        free_tab(params.map);
        return (0);
    }
}