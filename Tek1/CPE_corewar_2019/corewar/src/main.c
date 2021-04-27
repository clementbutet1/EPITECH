/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "corewar.h"

int main(int ac, char **av)
{
    corewar_t core;

    if (ac < 2)
        return 84;
    core.nb_cor = get_nb_prog(av);
    get_arg(ac, av, &core);
    init_arena(&core);
    battle_in_arena(&core);
    return (0);
}