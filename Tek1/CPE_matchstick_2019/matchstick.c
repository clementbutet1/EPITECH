/*
** EPITECH PROJECT, 2019
** matchstick.c
** File description:
** matchstick.c
*/

#include "include/my_matchstick.h"
#include <stdlib.h>
#include <stdio.h>

void init_struct(params_t *params)
{
    params->size_height = 0;
    params->size_large = 0;
    params->nb_max_stick = 0;
    params->map = NULL;
    params->line = NULL;
}

int check_error(params_t *params)
{
    if (params->nb_max_stick < 0 || params->size_height < 2
    || params->size_height > 99)
        return (84);
    else
        return (0);
}

int check_error_letter(char *str, char *str2)
{
    for (int i = 0; str[i] != '\0' && str2[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57 && str2[i] < 48 || str2[i] > 57)
            return (84);
    }
    return (0);
}

void play_game(params_t *params)
{
    while (1) {
        my_putstr("\nYour turn:\n");
        recup_player_entry_l(params);
        recup_player_entry_m(params);
        print_removed(params);
        remove_pipe(params);
        ia_turn_init_strcut(params);
        if (check_map_empty(params) == 0)
            return;
    }
}

int main(int ac, char **av)
{
    params_t params;

    init_struct(&params);
    if (ac != 3)
        return (84);
    params.size_height = my_getnbr(av[1]);
    params.nb_max_stick = my_getnbr(av[2]);
    if (check_error(&params) == 84)
        return (84);
    if (check_error_letter(av[1], av[2]) == 84)
    return (84);
    check_size_map(&params);
    play_game(&params);
    return (0);
}
