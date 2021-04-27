/*
** EPITECH PROJECT, 2019
** ldi.c
** File description:
** ldi.c
*/

#include "corewar.h"

int get_two_ldi(corewar_t *op, int i)
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

int get_one_ldi(corewar_t *op, int i)
{
    int tmp;

    if (op->champion[i]->instru->params[0] == 'r')
        tmp = op->arena.arena[op->champion[i]->pc +
        (op->champion[i]->instru->tab_ins[1 +
        op->champion[i]->instru->is_coding_byte][0] % IDX_MOD)];
    else if (op->champion[i]->instru->params[0] == 'd')
        tmp = op->arena.arena[op->champion[i]->pc +
        (op->champion[i]->instru->tab_ins[1 +
        op->champion[i]->instru->is_coding_byte][0] % IDX_MOD)];
    else if (op->champion[i]->instru->params[0] == 'i')
        tmp = op->arena.arena[op->champion[i]->pc +
        (op->champion[i]->instru->tab_ins[1 +
        op->champion[i]->instru->is_coding_byte][0] % IDX_MOD)];
    return tmp;
}

void ldi(corewar_t *op, int i)
{
    int one = get_one_ldi(op, i);
    int two = get_two_ldi(op, i);
    int read = one + two;

    read = op->arena.arena[op->champion[i]->pc - 6 + (read % IDX_MOD)];
    if (op->champion[i]->instru->params[2] == 'r') {
        op->champion[i]->registre[op->champion[i]->instru->tab_ins[3 +
        op->champion[i]->instru->is_coding_byte][0]] = read;
        if (read == 0)
            op->champion[i]->carry = 1;
        else
            op->champion[i]->carry = 0;
    }
}