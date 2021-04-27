/*
** EPITECH PROJECT, 2020
** check_champ.c
** File description:
** check_champ
*/

#include "corewar.h"

void fill_champ(champ_t *champion, corewar_t *core)
{
    int i = champion->load_adress;
    champion->pc = champion->load_adress;

    for (int a = 0; champion->core[a] != -1; i++, a++) {
        if (core->arena.arena[i] == 0)
            core->arena.arena[i] = champion->core[a];
        else
            my_putstr_error("Champions are too close\n");
    }
}