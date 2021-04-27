/*
** EPITECH PROJECT, 2019
** aff.c
** File description:
** aff.c
*/

#include "corewar.h"

void aff(corewar_t *op, int i)
{
    int value = 0;

    if (op->champion[i]->instru->params[0] == 'r')
        value =
        op->champion[i]->registre[op->champion[i]->instru->tab_ins[1 +
        op->champion[i]->instru->is_coding_byte][0]];
    my_putchar(value);
}