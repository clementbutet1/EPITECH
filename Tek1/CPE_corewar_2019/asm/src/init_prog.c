/*
** EPITECH PROJECT, 2019
** init_prog.c
** File description:
** init_prog.c
*/

#include "asm.h"

void init_prog(int ac, char **av, params_t *params)
{
    if (ac != 2)
        exit (84);
    if (check_same_word(av[1], "--help") == 11 ||
    check_same_word(av[1], "-h") == 11) {
        display_help();
        exit (0);
    }
    init_struct(params);
}