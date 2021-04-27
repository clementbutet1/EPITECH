/*
** EPITECH PROJECT, 2019
** check_map.c
** File description:
** check_map.c
*/

#include "include/my_matchstick.h"
#include <stdlib.h>
#include <stdio.h>

void check_condi(params_t *params, int cpt)
{
    if (params->entry_player_m == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        recup_player_entry_l(params);
        recup_player_entry_m(params);
        print_removed(params);
    }
    if (params->entry_player_m >= cpt) {
        my_putstr("Error: not enough matches on this line\n");
        recup_player_entry_l(params);
        recup_player_entry_m(params);
        print_removed(params);
    } else {
        my_putstr("Player removed ");
        my_put_nbr(params->entry_player_m);
        my_putstr(" match(es) from line ");
        my_put_nbr(params->entry_player_l);
        my_putchar('\n');
    }
}

int check_map_empty(params_t *params)
{
    for (int i = 0; params->map[i] != NULL; i++)
        for (int z = 0; params->map[i][z] != '\n'; z++)
            if (params->map[i][z] == '|')
                return (-1);
    return (0);
}

void print_removed(params_t *params)
{
    int cpt = 0;

    for (int z = 0; params->map[params->entry_player_l][z] != '\n'; z++) {
        if (params->map[params->entry_player_l][z] == '|')
            cpt++;
    }
    cpt++;
    check_condi(params, cpt);
}