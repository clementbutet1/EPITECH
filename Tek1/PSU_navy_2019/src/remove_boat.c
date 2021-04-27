/*
** EPITECH PROJECT, 2019
** remove_boat.c
** File description:
** remove_boat.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

char **ck_attack1(char **map_pos, int scd_val, int frst_val, params_t *params)
{
    char **map = params->map;
    params->game = 0;

    if (map_pos[scd_val][frst_val] == '.' || map[scd_val][frst_val] == 'o') {
        map[scd_val][frst_val] = 'o';
        params->game = 0;
        return (map);
    }
    if (map[scd_val][frst_val] == 'x') {
        params->game = 3;
        return (map);
    } else {
        map[scd_val][frst_val] = 'x';
        params->game = 2;
        return (map);
    }
}

char **ck_attack2(char **map_pos, int scd_val, int frst_val, params_t *params)
{
    char **map = params->map;
    params->game = 0;

    if (map_pos[scd_val][frst_val] == '.' || map[scd_val][frst_val] == 'o') {
        map[scd_val][frst_val] = 'o';
        params->game = 0;
        return (map);
    }
    if (map[scd_val][frst_val] == 'x') {
        params->game = 3;
        return (map);
    } else {
        map[scd_val][frst_val] = 'x';
        params->game = 2;
        return (map);
    }
}

char **put_attack(char **map_pos, int scd_val, int frst_val, params_t *params)
{
    if (params->game == 3){
        params->map_vide[scd_val][frst_val] = 'x';
        params->game = 3;
        return (params->map_vide);
    }
    if (params->game == 2){
        params->map_vide[scd_val][frst_val] = 'x';
        params->game = 2;
        return (params->map_vide);
    }
    else {
        params->map_vide[scd_val][frst_val] = 'o';
        params->game = 0;
        return (params->map_vide);
    }
    return (params->map_vide);
}

char *cmd_enter_by_player(params_t *params)
{
    char *cmd = NULL;

    my_putstr("\nattack: ");
    free(cmd);
    cmd = NULL;
    cmd = get_next_line(0);
    if (check_cmd(cmd) == 84) {
        free(cmd);
        cmd_enter_by_player(params);
    }
    return (cmd);
}

values_t check_enter_other_play(params_t *params, char **map_pos)
{
    char **map = params->map;
    values_t values;
    char *cmd = NULL;
    values.frst_val = 0;
    values.scd_val = 0;

    cmd = cmd_enter_by_player(params);
    values.frst_val = (check_letter(params, cmd[0]));
    values.frst_val -= 2;
    values.scd_val = ((cmd[1] - 48));
    return (values);
}