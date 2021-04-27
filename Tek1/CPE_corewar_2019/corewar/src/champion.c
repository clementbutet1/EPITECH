/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** champion
*/

#include "corewar.h"

champ_t create_champion(char *name, corewar_t *core, int nb)
{
    int i = my_strlen(name);
    champ_t tmp;

    while (name[i] != '.')
        i--;
    name[i] = '\0';
    tmp.name = name;
    tmp.load_adress = core->[nb];
    tmp.nb_prog = core->[nb];
    tmp.pc = tmp.load_adress;
    return tmp;
}

int get_champ(char **av, corewar_t *core)
{
    int nb = 0;

    core->champion = malloc(sizeof(champ_t) * get_nb_prog(av));
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strendcmp(av[i], ".cor") == 0)
            core->champion[nb] = create_champion(av[i], core, nb);
    }
}