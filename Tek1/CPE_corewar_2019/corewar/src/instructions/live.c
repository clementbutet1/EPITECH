/*
** EPITECH PROJECT, 2019
** live.c
** File description:
** live.c
*/

#include "corewar.h"

void live(corewar_t *op, int i)
{
    if (op->champion[i]->instru->params[0] == 'd') {
        my_putstr("The player ");
        my_put_nbr(op->champion[i]->nb_prog);
        my_putchar('(');
        my_putstr(op->champion[i]->name);
        my_putstr(") is alive.\n");
        op->living_cor++;
        op->last_core = op->champion[i]->name;
    }
}