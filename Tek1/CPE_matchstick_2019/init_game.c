/*
** EPITECH PROJECT, 2019
** init_game.c
** File description:
** init_game.c
*/

#include "include/my_matchstick.h"
#include <stdlib.h>
#include <stdio.h>

int exit_prog(char *init, size_t size)
{
    if (getline(&init, &size, stdin) == -1)
        return (84);
    return (0);
}

int recup_player_entry_l(params_t *params)
{
    char *init_num_player = NULL;
    size_t size = 2;
    params->entry_player_l = 0;

    my_putstr("Line: ");
    if (getline(&init_num_player, &size, stdin) != -1) {
        (check_nb(init_num_player) == 84) ?
    recup_player_entry_l(params) :
    (params->entry_player_l = my_getnbr(init_num_player));
    } else
        out_game;
    if (check_positiv(params->entry_player_l) == 84)
        recup_player_entry_l(params);
    else
        if (check_size_l(params) == 84)
            recup_player_entry_l(params);
        return (11);
}

int recup_player_entry_m(params_t *params)
{
    char *init_num_player = NULL;
    size_t size = 2;
    params->entry_player_m = 0;

    my_putstr("Matches: ");
    if (getline(&init_num_player, &size, stdin) != -1) {
        (check_nb(init_num_player) == 84) ?
    recup_player_entry_l(params), recup_player_entry_m(params) :
    (params->entry_player_m = my_getnbr(init_num_player));
    } else
        out_game;
    if (check_positiv(params->entry_player_m) == 84) {
        recup_player_entry_l(params);
        recup_player_entry_m(params);
    } else
        if (check_size_m(params) == 84) {
            recup_player_entry_l(params);
            recup_player_entry_m(params);
        }
        return ( 11);
}
