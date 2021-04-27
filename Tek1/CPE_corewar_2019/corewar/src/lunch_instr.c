/*
** EPITECH PROJECT, 2020
** lunch_instr.c
** File description:
** lunch_instr
*/

#include "corewar.h"

void lunch_instr2(corewar_t *co, int i)
{
    if (co->champion[i]->instru->tab_ins[0][0] == 9)
        zjmp(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 10)
        ldi(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 11)
        sti(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 12)
        my_fork(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 13)
        lld(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 14)
        lldi(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 15)
        my_lfork(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 16)
        aff(co, i);
}

void lunch_instr(corewar_t *co, int i)
{
    if (co->champion[i]->instru->tab_ins[0][0] == 1)
        live(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 2)
        ld(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 3)
        st(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 4)
        add(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 5)
        sub(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 6)
        and(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 7)
        or(co, i);
    if (co->champion[i]->instru->tab_ins[0][0] == 8)
        xor(co, i);
    lunch_instr2(co, i);
}