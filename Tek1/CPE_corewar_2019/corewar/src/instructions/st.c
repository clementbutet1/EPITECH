/*
** EPITECH PROJECT, 2019
** st.c
** File description:
** st.c
*/

#include "corewar.h"

void st(corewar_t *op, int i)
{
    int val = 0;

    if (op->champion[i]->instru->params[0] == 'r')
        val = op->champion[i]->registre[op->champion[i]->instru->tab_ins[1
        + op->champion[i]->instru->is_coding_byte][0]];
    if (op->champion[i]->instru->params[1] == 'r')
        op->champion[i]->registre[op->champion[i]->instru->tab_ins[2
        + op->champion[i]->instru->is_coding_byte][0]] = val;
    else if (op->champion[i]->instru->params[0] == 'i')
        op->arena.arena[op->champion[i]->pc +
        (op->champion[i]->instru->tab_ins[1
        + op->champion[i]->instru->is_coding_byte][0] % IDX_MOD)] = val;
}