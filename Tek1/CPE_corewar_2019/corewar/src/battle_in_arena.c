/*
** EPITECH PROJECT, 2020
** battle_in_arena.c
** File description:
** battle_in_arena
*/

#include "corewar.h"

instru_t *get_instru(champ_t *champion, corewar_t *core)
{
    instru_t *instru = malloc(sizeof(instru_t));

    for (int a = 0; a == 0; champion->pc += 1) {
        for (int i = 0; op_tab[i].code != 0; i++) {
            (champion->pc < 0) ? champion->pc += MEM_SIZE : 0;
            champion->pc = champion->pc % MEM_SIZE;
            (a = (op_tab[i].code == core->arena.arena[champion->pc]) ?
            (condi_get_instru(instru, a, i)) : a);
            condi_get_instru2(a);
        }
    }
    champion->pc--;
    champion->instru = get_tab_ins(champion, core, instru);
    return (instru);
}

void change_pc(corewar_t *core, int i)
{
    if (core->champion[i]->instru->is_coding_byte == 1)
        core->champion[i]->pc++;
    if (core->champion[i]->instru->tab_ins[0][0] == 1 ||
        core->champion[i]->instru->tab_ins[0][0] == 9 ||
        core->champion[i]->instru->tab_ins[0][0] == 12 ||
        core->champion[i]->instru->tab_ins[0][0] == 15)
        core->champion[i]->pc += core->champion[i]->instru->dir_size;
    else {
        for (int j = 0; core->champion[i]->instru->params[j] > '\0'; j++) {
            condi_change_pc(core, i, j);
        }
    }
}

void get_all_instru(corewar_t *core)
{
    for (int i = 0; i != core->nb_cor; i++) {
        if (core->champion[i]->instru->cycle_to_wait == 0 &&
        core->champion[i]->instru->cycle_to_wait == 0) {
            condi_get_all_instru(core, i);
        }
        core->champion[i]->instru->cycle_to_wait--;
    }
    core->arena.cycle_die -= 1;
}

void battle_in_arena(corewar_t *core)
{
    int win = 1;

    for (int i = 0; i < core->nb_cor; i++) {
        core->champion[i]->instru = malloc(sizeof(instru_t));
        core->champion[i]->instru->cycle_to_wait = 0;
    }
    while (win) {
        get_all_instru(core);
        if (check_alive(core) == 1) {
            my_putstr("The player ");
            my_putstr(core->last_core);
            my_putstr(" won.\n");
            break;
        }
    }
}