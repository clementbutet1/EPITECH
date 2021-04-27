/*
** EPITECH PROJECT, 2019
** condi.c
** File description:
** condi.c
*/

#include "corewar.h"

void condi_change_pc(corewar_t *core, int i, int j)
{
    if (core->champion[i]->instru->params[j] == 'r')
        core->champion[i]->pc++;
    if (core->champion[i]->instru->params[j] == 'i')
        core->champion[i]->pc += IND_SIZE;
    if (core->champion[i]->instru->params[j] == 'd')
        core->champion[i]->pc += core->champion[i]->instru->dir_size;
    return;
}

void condi_get_all_instru(corewar_t *core, int i)
{
    if (core->champion[i]->is_alive == 1) {
        get_instru(core->champion[i], core);
        lunch_instr(core, i);
        change_pc(core, i);
    }
}

int condi_get_instru(instru_t *instru, int a, int i)
{
    instru->cycle_to_wait = op_tab[i].nbr_cycles;
    instru->memonic = op_tab[i].mnemonique;
    instru->nb_params = op_tab[i].nbr_args;
    a += 1;
    return (a);
}

void condi_get_instru2(int a)
{
    if (a == MEM_SIZE)
        my_putstr_error("Error : undefined instruction in the core");
    return;
}