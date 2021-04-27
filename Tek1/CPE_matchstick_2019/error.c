/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "include/my_matchstick.h"
#include <stdlib.h>
#include <stdio.h>

int check_positiv(int nb)
{
    if (nb >= 0 && nb <= 99) {
        return (0);
    } else {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (84);
    }
}

int check_nb(char *str)
{
    int size = my_strlen(str);
    int cpt = 0;
    if (str == NULL || str[0] == '\n') {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (84);
    }
    for (int i = 0; i != size; i++) {
        if (((str[i] < '0' || str[i] > '9'))
        && (str[i] != '\n' && str[i] != '\0')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    return (0);
}

int check_size_l(params_t *params)
{
    if (params->entry_player_l == 0 ||
    params->entry_player_l > params->size_height) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    } else
        return (0);
}

int check_size_m(params_t *params)
{
    if (params->entry_player_m > params->nb_max_stick) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(params->nb_max_stick);
        my_putstr(" matches per turn\n");
        return (84);
    } else
        return (0);
}
