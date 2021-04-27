/*
** EPITECH PROJECT, 2019
** check_number_values.c
** File description:
** check_number_values.c
*/

#include "corewar.h"

void check_error_values(corewar_t *core, int i, int j)
{
    if (core->champion[i]->nb_prog == core->champion[j]->nb_prog)
        my_putstr_error("Error : Champion must have different prog number.");
}

void check_values(corewar_t *core)
{
    for (int i = 0; i < core->nb_cor; i++) {
        for (int j = i + 1; j < core->nb_cor; j++)
            check_error_values(core, i, j);
    }
    return;
}