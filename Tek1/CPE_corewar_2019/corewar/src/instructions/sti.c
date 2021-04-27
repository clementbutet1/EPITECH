/*
** EPITECH PROJECT, 2019
** sti.c
** File description:
** sti.c
*/

#include "corewar.h"

int get_val_sti(corewar_t *op, int i)
{
    if (op->champion[i]->instru->params[1] == 'r') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[1
            + op->champion[i]->instru->is_coding_byte][0]];
    }
    return 0;
}

int get_three_sti(corewar_t *op, int i)
{
    if (op->champion[i]->instru->params[0] == 'r') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[3
            + op->champion[i]->instru->is_coding_byte][0]];
    } else if (op->champion[i]->instru->params[0] == 'd') {
        return op->champion[i]->instru->tab_ins[3
            + op->champion[i]->instru->is_coding_byte][0];
    }
    return 0;
}

int get_two_sti(corewar_t *op, int i)
{
    if (op->champion[i]->instru->params[1] == 'r') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[2
            + op->champion[i]->instru->is_coding_byte][0]];
    } else if (op->champion[i]->instru->params[1] == 'i') {
        return op->champion[i]->instru->tab_ins[2
            + op->champion[i]->instru->is_coding_byte][0];
    } else if (op->champion[i]->instru->params[1] == 'd') {
        return op->champion[i]->instru->tab_ins[2
            + op->champion[i]->instru->is_coding_byte][0];
    }
    return 0;
}

void sti(corewar_t *op, int i)
{
    int three = get_three_sti(op, i);
    int two = get_two_sti(op, i);
    int val = get_val_sti(op, i);
    int stock = op->champion[i]->pc + (two % IDX_MOD) + (three % IDX_MOD);

    stock = stock % MEM_SIZE;
    if (stock < 0)
        stock = stock + MEM_SIZE;
    if (val == 0)
        op->champion[i]->carry = 1;
    else
        op->champion[i]->carry = 0;
    return;
}