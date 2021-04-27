/*
** EPITECH PROJECT, 2019
** ia.c
** File description:
** ia.c
*/

#include "include/my_matchstick.h"
#include <stdlib.h>
#include <stdio.h>

void check_nb_stick(params_t *params, ia_params_t *ia_params)
{
    ia_params->entry_ia_l = 1;

    (ia_params->entry_ia_m == 0) ? ia_params->entry_ia_m = 1 : 0;
    for (int k = 1; k < params->size_height + 1; k++) {
        if ((ia_params->tab[k]) == 0)
            k++;
        if (ia_params->tab[k] != 0 &&
        ia_params->tab[k] >= ia_params->entry_ia_m) {
            ia_params->entry_ia_l = k;
        }
    }
    ia_print(params, ia_params);
    remove_pipe_for_ia(params, ia_params);
    if (check_map_empty(params) == -1)
        return;
    else {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        out_game1;
    }
}

void xor_tab(params_t *params, ia_params_t *ia_params)
{
    int xor = 0;

    for (int k = 1; k != params->size_height + 1; k++) {
        xor = xor ^ ia_params->tab[k];
    }
    if (xor > 1)
        xor--;
    if (xor > ia_params->max_stick_per_line)
        xor = 1;
    if (xor == 0)
        ia_params->entry_ia_m = 1;
    if (xor > params->nb_max_stick)
        ia_params->entry_ia_m = 1;
    else
        ia_params->entry_ia_m = xor;
    check_nb_stick(params, ia_params);
}

void ia_algo(params_t *params, ia_params_t *ia_params)
{
    for (int k = 1; k != params->size_height + 1; k++) {
        ia_params->tab[k] = 0;
    }
    for (int k = 1; k != params->size_height + 1; k++) {
        ia_params->nb_stick = 0;
        for (int z = 0; params->map[k][z] != '\n'; z++) {
            if (params->map[k][z] == '|') {
                ia_params->nb_stick++;
                check_max_stick(params, ia_params);
                ia_params->nb_total_stick++;
            }
            ia_params->tab[k] = ia_params->nb_stick;
        }
    }
    xor_tab(params, ia_params);
}

void ia_turn_init_strcut(params_t *params)
{
    ia_params_t ia_params;
    ia_params.nb_total_stick = 0;
    ia_params.entry_ia_m = 0;
    ia_params.entry_ia_l = 0;
    ia_params.nb_stick = 0;
    ia_params.tab = 0;
    ia_params.tab = malloc(sizeof(int *) * params->size_height + 1);
    ia_algo(params, &ia_params);
}
