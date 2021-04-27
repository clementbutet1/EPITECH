/*
** EPITECH PROJECT, 2020
** battle_params.c
** File description:
** battle_params
*/

#include "corewar.h"

int check_alive(corewar_t *core)
{
    int alive = 0;

    for (int i = 0; i < core->nb_cor; i++) {
        if (core->champion[i]->is_alive == 1)
            alive++;
    }
    if (core->arena.cycle_die == 0)
        return 1;
    if (alive > 0)
        return 0;
    else
        return 1;
}

char *my_conver_base2(int nb, int size)
{
    int rslt;
    char *res = malloc(sizeof(char) * (size + 1));
    int i = 0;
    char *c = "01";

    for (int a = 0; a < size; a++)
        res[a] = '0';
    res[size] = '\0';
    while (nb > 0 && i < size) {
        rslt = nb % 2;
        nb = nb / 2;
        res[i] = c[rslt];
        i++;
    }
    res = my_revstr(res);
    return (res);
}

int *copy_int_star(int *memory, int *new, int *indice, int size)
{
    for (int i = 0; i < size; i++, *indice += 1) {
        (*indice > MEM_SIZE) ? *indice = *indice % MEM_SIZE : 0;
        new[i] = memory[*indice];
        new[i + 1] = -1;
    }
    return (new);
}