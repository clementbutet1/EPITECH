/*
** EPITECH PROJECT, 2020
** vm_init.c
** File description:
** vm_init
*/

#include "corewar.h"

int swap_octets(int k)
{
    int tmp;

    tmp = k & 0xff;
    k = (k & 0xff00) / 0xff;
    k = k + (tmp * 0x100);
    return k;
}

int swap_to_endian(int buf)
{
    int tmp;

    tmp = buf & 0xffff;
    buf = (buf & 0xffff0000) / 0xffff;
    tmp = swap_octets(tmp) * 0x10000;
    buf = swap_octets(buf) + tmp;
    return buf;
}

void fill_arena(int *arena, int size, int nbr)
{
    int i = 0;

    for (; i < size; i++)
        arena[i] = nbr;
    arena[i] = -1;
}

int init_arena(corewar_t *core)
{
    core->arena.cycle_die = CYCLE_TO_DIE;
    core->arena.nbr_lives = NBR_LIVE;
    core->arena.arena = malloc(sizeof(int) * (MEM_SIZE + 1));
    fill_arena(core->arena.arena, MEM_SIZE, 0);
    for (int n = 0; n != core->nb_cor; n++)
        get_instru_cor(core->champion[n], core);
    return 0;
}