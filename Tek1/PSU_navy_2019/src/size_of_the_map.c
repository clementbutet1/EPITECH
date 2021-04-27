/*
** EPITECH PROJECT, 2019
** size_of_the_map.c
** File description:
** size_of_the_map.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

int end_game(params_t *params, int player)
{
    if (params->cpt_win_player2 == 14 && player == 2) {
        my_putstr("\nI won\n");
        exit_win;
    }
    if (params->cpt_win_play1 == 14 && player == 1) {
        my_putstr("\nI won\n");
        exit_win;
    }
    if (params->loose != 0) {
        my_putstr("\nEnemy won\n");
        exit_loose;
    }
    return (0);
}

int check_victory(params_t *params, int player)
{
    if (params->cpt_win_play1 == 14) {
        params->loose = 2;
        params->cpt_win_player2 = 0;
    }
    if (params->cpt_win_player2 == 14) {
        params->loose = 1;
        params->cpt_win_play1 = 0;
    }
    end_game(params, player);
    return (0);
}

char **copy_map(params_t *params, char **map)
{
    int size = 0;
    int i = 0;

    for (; params->map[size] != NULL; size++);
    map = malloc(sizeof(char *) * (size + 1));
    for (; params->map[i] != NULL; i++)
        map[i] = my_strdup(params->map[i]);
    map[i] = NULL;
    return (map);
}