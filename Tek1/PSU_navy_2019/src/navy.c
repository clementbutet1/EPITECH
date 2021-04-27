/*
** EPITECH PROJECT, 2019
** navy.c
** File description:
** navy.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

int check_open(params_t *params, char **av, int ac)
{
    if (ac == 2) {
        params->pos = open_read(av[1], params);
        if (params->pos == NULL)
            return (84);
        if (check_error_on_line(params->pos, params) == 84)
            return (84);
        else
            return (0);
    }
    if (ac == 3) {
        params->pos = open_read(av[2], params);
        if (params->pos == NULL)
            return (84);
        if (check_error_on_line(params->pos, params) == 84)
            return (84);
        else
            return (0);
    }
    return (0);
}

void init_struct(params_t *params)
{
    params->map = NULL;
    params->cpt_win_play1 = 0;
    params->cpt_win_player2 = 0;
    params->cmd = NULL;
    params->game = 0;
    params->enemy_pid = 0;
    params->my_pid = 0;
    params->loose = 0;
}

int execute_all_funct_player1(params_t *params, char **av, char **mapvd)
{
    params->map_vide = mapvd;
    params->game = 0;

    my_putstr("my_positions:\n");
    params->pos_player1 = recup_coord_boat(params);
    if (params->pos_player1 == NULL)
        return (84);
    print_map(params->pos_player1);
    my_putstr("\nenemy's positions:\n");
    print_map(mapvd);
    boucle_inf_for_player1(params, av, mapvd);
    return (0);
}

int execute_all_funct_player2(params_t *params, char **av, char **mapvd)
{
    params->map_vide = mapvd;

    my_putstr("my_positions:\n");
    params->pos = open_read(av[2], params);
    check_error_on_line(params->pos, params);
    params->pos_player1 = recup_coord_boat(params);
    if (params->pos_player1 == NULL)
        return (84);
    print_map(params->pos_player1);
    my_putstr("\nenemy's positions:\n");
    print_map(mapvd);
    boucle_inf_for_player2(params, av, mapvd);
    return (0);
}

int main(int ac, char **av)
{
    params_t params;
    char **map_vide = NULL;

    init_struct(&params);
    if (ac > 3 || ac == 1)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        display_help();
        return (0);
    }
    if (check_open(&params, av, ac) == 84)
        return (84);
    create_map(&params);
    map_vide = copy_map(&params, map_vide);
    if (params.map == NULL)
        return (84);
    if (signal_player_one(ac, av, &params, map_vide) == 84)
        return (84);
    return (0);
}