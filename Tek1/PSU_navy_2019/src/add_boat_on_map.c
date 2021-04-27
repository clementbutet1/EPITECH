/*
** EPITECH PROJECT, 2019
** add_boat_on_map.c
** File description:
** add_boat_on_map.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

char **put_pos_first_point_boat(params_t *params, char *str, char size)
{
    int bg_values = (check_letter(params, str[2]));
    int ls_values = (check_letter(params, str[5]));
    int bg_line = ((str[3]) - (48) + 1);
    int ls_line = ((str[6]) - (48) + 1);
    char **rslt = params->map;
    rslt[bg_line][bg_values] = size;
    rslt[ls_line][ls_values] = size;

    if ((bg_line != ls_line))
        for (; bg_line != ls_line; bg_line++)
            rslt[bg_line][bg_values] = size;
    if ((bg_values != ls_values))
        for (; bg_values != ls_values; bg_values = bg_values + 2)
            rslt[bg_line][bg_values] = size;
    return (rslt);
}

int check_nb_boat(char **pos)
{
    int i = 0;

    for (; pos[i] != NULL; i++);
    if (i == 4)
        return (0);
    else
        return (84);
}

int check_error_pos(char **pos)
{
    if (pos[0] != NULL && pos[1] != NULL &&
        pos[2] != NULL && pos[3] != NULL && pos[4] == NULL)
        return (0);
    else
        return (84);
}

char **recup_coord_boat(params_t *params)
{
    if (check_error_pos(params->pos) == 84)
        return (NULL);
    if (check_entry_player_size_boat(params->pos) == 84)
        return (NULL);
    if (check_nb_boat(params->pos) == 84)
        return (NULL);
    if (check_pos_boat(params) == 84)
        return (NULL);
    return (put_boat(params, params->pos));
}

char **put_boat(params_t *params, char **pos)
{
    char **rslt = NULL;

    for (int i = 0; pos[i] != NULL; i++) {
        rslt = put_pos_first_point_boat(params, pos[i], pos[i][0]);
    }
    return (rslt);
}