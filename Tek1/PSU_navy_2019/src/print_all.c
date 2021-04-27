/*
** EPITECH PROJECT, 2019
** print_all.c
** File description:
** print_all.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

int check_error_nb_boat(params_t *params, boat_error_t *boat)
{
    if (boat->boat1 == 2 && boat->boat2 == 3 &&
        boat->boat3 == 4 && boat->boat4 == 5)
        return (0);
    else
        return (84);
}

void init_struct_error_boat(boat_error_t *boat)
{
    boat->boat1 = 0;
    boat->boat2 = 0;
    boat->boat3 = 0;
    boat->boat4 = 0;
}

int check_same_pos_for_boat(char **pos, params_t *params)
{
    boat_error_t boat;
    create_map(params);
    init_struct_error_boat(&boat);
    char **map_boat = put_boat(params, pos);
    int j = 2;

    for (int i = 0; map_boat[i] != NULL; i++) {
        for (j = 2; map_boat[i][j] != '\n'; j++) {
            (map_boat[i][j] == '2') ? boat.boat1 += 1 : boat.boat1;
            (map_boat[i][j] == '3') ? boat.boat2 += 1 : boat.boat2;
            (map_boat[i][j] == '4') ? boat.boat3 += 1 : boat.boat3;
            (map_boat[i][j] == '5') ? boat.boat4 += 1 : boat.boat4;
        }
    }
    return (check_error_nb_boat(params, &boat));
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        my_putstr(map[i]);
    return;
}