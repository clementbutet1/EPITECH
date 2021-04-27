/*
** EPITECH PROJECT, 2019
** new_map.c
** File description:
** new_map.c
*/

#include "include/my_matchstick.h"
#include <stdlib.h>
#include <stdio.h>

void check_max_stick(params_t *params, ia_params_t *ia_params)
{
    if (ia_params->nb_stick > ia_params->max_stick_per_line)
        ia_params->max_stick_per_line = ia_params->nb_stick;
    else
        return;
}

void ia_print(params_t *params, ia_params_t *ia_params)
{
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(ia_params->entry_ia_m);
    my_putstr(" match(es) from line ");
    my_put_nbr(ia_params->entry_ia_l);
    my_putchar('\n');
}

void check_pipe_line(params_t *params)
{
    int cpt = 0;

    for (int z = 0; params->map[params->entry_player_l][z] != '\n'; z++) {
        if (params->map[params->entry_player_l][z] == '|')
            cpt++;
    }
    if (params->entry_player_m > cpt + 1) {
        my_putstr("Error: not enough matches on this line\n");
        recup_player_entry_l(params);
        recup_player_entry_m(params);
        print_removed(params);
    } else
            return;
}

void remove_pipe(params_t *params)
{
    int counter = 0;
    int sz_ln = my_strlen(params->map[1]);
    sz_ln = sz_ln - 1;

    check_pipe_line(params);
    for (; params->map[params->entry_player_l][sz_ln] != '\0'; sz_ln--) {
        if (params->map[params->entry_player_l][sz_ln] == '|' && counter !=
        params->entry_player_m) {
            params->map[params->entry_player_l][sz_ln] = 32;
            counter++;
        }
    }
    print_map(params);
    if (check_map_empty(params) == -1)
        return;
    else {
        my_putstr("You lost, too bad...\n");
        out_game2;
    }
}

void remove_pipe_for_ia(params_t *params, ia_params_t *ia_params)
{
    int counter = 0;
    int sz_ln = my_strlen(params->map[1]);
    sz_ln = sz_ln - 1;

    for (; params->map[ia_params->entry_ia_l][sz_ln] != '\0'; sz_ln--) {
        if (params->map[ia_params->entry_ia_l][sz_ln] == '|' && counter !=
        ia_params->entry_ia_m) {
            params->map[ia_params->entry_ia_l][sz_ln] = 32;
            counter++;
        }
    }
    print_map(params);
}
