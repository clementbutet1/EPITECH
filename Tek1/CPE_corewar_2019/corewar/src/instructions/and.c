/*
** EPITECH PROJECT, 2019
** and.c
** File description:
** and.c
*/

#include "corewar.h"

int get_one_and(corewar_t *op, int i)
{
    if (op->champion[i]->instru->params[0] == 'r') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[1
            + op->champion[i]->instru->is_coding_byte][0]];
    } else if (op->champion[i]->instru->params[0] == 'i') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[1
            + op->champion[i]->instru->is_coding_byte][0]];
    } else if (op->champion[i]->instru->params[0] == 'd') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[1
            + op->champion[i]->instru->is_coding_byte][0]];
    }
    return 0;
}

int get_two_and(corewar_t *op, int i)
{
    if (op->champion[i]->instru->params[1] == 'r') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[2
            + op->champion[i]->instru->is_coding_byte][0]];
    } else if (op->champion[i]->instru->params[1] == 'i') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[2
            + op->champion[i]->instru->is_coding_byte][0]];
    } else if (op->champion[i]->instru->params[1] == 'd') {
        return op->champion[i]->registre[op->champion[i]->instru->tab_ins[2
            + op->champion[i]->instru->is_coding_byte][0]];
    }
    return 0;
}

void and(corewar_t *op, int i)
{
    int one = 0;
    int two = 0;

    one = get_one_and(op, i);
    two = get_two_and(op, i);
    if (op->champion[i]->instru->params[2] == 'r')
        op->champion[i]->registre[op->champion[i]->instru->tab_ins[3
        + op->champion[i]->instru->is_coding_byte][0]] = one & two;
    ((one & two) == 0) ? (op->champion[i]->carry = 1) :
    (op->champion[i]->carry = 0);
}