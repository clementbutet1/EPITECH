/*
** EPITECH PROJECT, 2019
** lldi.c
** File description:
** lldi.c
*/

#include "corewar.h"

int get_two_lldi(corewar_t *op, int i)
{
    int tmp;

    if (op->champion[i]->instru->params[1] == 'r')
        tmp = op->champion[i]->registre[op->champion[i]->instru->tab_ins[2 +
        op->champion[i]->instru->is_coding_byte][0]];
    else if (op->champion[i]->instru->params[1] == 'd')
        tmp = op->champion[i]->instru->tab_ins[2 +
        op->champion[i]->instru->is_coding_byte][0];
    return tmp;
}

int get_one_lldi(corewar_t *op, int i)
{
    int tmp;

    if (op->champion[i]->instru->params[0] == 'r')
        tmp = op->arena.arena[op->champion[i]->pc +
        op->champion[i]->instru->tab_ins[1 +
        op->champion[i]->instru->is_coding_byte][0]];
    else if (op->champion[i]->instru->params[0] == 'd')
        tmp = op->arena.arena[op->champion[i]->pc +
        op->champion[i]->instru->tab_ins[1 +
        op->champion[i]->instru->is_coding_byte][0]];
    else if (op->champion[i]->instru->params[0] == 'i')
        tmp = op->arena.arena[op->champion[i]->pc +
        op->champion[i]->instru->tab_ins[1 +
        op->champion[i]->instru->is_coding_byte][0]];
    return tmp;
}

void lldi(corewar_t *op, int i)
{
    int one = get_one_lldi(op, i);
    int two = get_two_lldi(op, i);
    int read = one + two;

    read = op->arena.arena[op->champion[i]->pc - 6 + (read)];
    if (op->champion[i]->instru->params[2] == 'r') {
        op->champion[i]->registre[op->champion[i]->instru->tab_ins[3 +
        op->champion[i]->instru->is_coding_byte][0]] = read;
        if (read == 0)
            op->champion[i]->carry = 1;
        else
            op->champion[i]->carry = 0;
    }
}