/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** get.c
*/

#include "corewar.h"

int get_nb_prog(char **av)
{
    int nb_prog = 0;

    for (int i = 0; av[i] != NULL; i++) {
        if (my_strendcmp(av[i], ".cor") == 1)
            nb_prog++;
    }
    return (nb_prog);
}

int get_dump(char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-dump") == 0)
            return (my_getnbr(av[i + 1]));
    }
    return (-1);
}

void get_all_champ(champ_t *champion)
{
    champ_magic_nbr(champion);
    champ_name(champion);
    champ_size(champion);
    champ_comment(champion);
}

int get_arg(int ac, char **av, corewar_t *C)
{
    check_argument(av);
    C->champion = malloc(sizeof(champ_t *) * C->nb_cor);
    C->dump = get_dump(av);
    for (int i = 0; i != ac; i++)
        if (my_strendcmp(av[i], ".cor") == 1)
            recove_champ(av, C, i);
    check_values(C);
    return (0);
}