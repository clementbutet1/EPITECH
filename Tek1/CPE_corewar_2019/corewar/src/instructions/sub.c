/*
** EPITECH PROJECT, 2019
** sub.c
** File description:
** sub.c
*/

#include "corewar.h"

void sub(corewar_t *op, int i)
{
    int res = 0;

    if (op->champion[i]->instru->params[0] == 'r' &&
    op->champion[i]->instru->params[1] == 'r' &&
    op->champion[i]->instru->params[2] == 'r') {
        res = op->champion[i]->registre[op->champion[i]->instru->tab_ins[1
        + op->champion[i]->instru->is_coding_byte][0]] -
        op->champion[i]->registre[op->champion[i]->instru->tab_ins[2
        + op->champion[i]->instru->is_coding_byte][0]];
        op->champion[i]->registre[op->champion[i]->instru->tab_ins[3
        + op->champion[i]->instru->is_coding_byte][0]] = res;
    }
    op->champion[i]->carry =
    (op->champion[i]->registre[op->champion[i]->instru->tab_ins[1
    + op->champion[i]->instru->is_coding_byte][0]] -
    op->champion[i]->registre[op->champion[i]->instru->tab_ins[2
    + op->champion[i]->instru->is_coding_byte][0]]) ? (0) : (1);
}