/*
** EPITECH PROJECT, 2019
** lld.c
** File description:
** lld.c
*/

#include "corewar.h"

void lld(corewar_t *co, int i)
{
    int tmp;

    if (co->champion[i]->instru->params[0] == 'i')
        tmp = co->arena.arena[co->champion[i]->pc +
        co->champion[i]->instru->tab_ins[1 +
        co->champion[i]->instru->is_coding_byte][0]];
    else if (co->champion[i]->instru->params[0] == 'd')
        tmp = co->champion[i]->instru->tab_ins[1 +
        co->champion[i]->instru->is_coding_byte][0];
    if (co->champion[i]->instru->params[1] == 'r')
        co->champion[i]->registre[co->champion[i]->instru->tab_ins[3 +
        co->champion[i]->instru->is_coding_byte][0]] = tmp;
    co->champion[i]->carry = (tmp) ? (0) : (1);
    return;
}