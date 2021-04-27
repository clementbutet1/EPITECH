/*
** EPITECH PROJECT, 2019
** zjmp.c
** File description:
** zjmp.c
*/

#include "corewar.h"

void zjmp(corewar_t *co, int i)
{
    if (co->champion[i]->pc + (co->val[0] % IDX_MOD))
        co->champion[i]->pc += MEM_SIZE;
    co->champion[i]->pc += co->val[0] % IDX_MOD;
    co->champion[i]->pc = co->champion[i]->pc % MEM_SIZE;
    co->champion[i]->carry = 0;
}