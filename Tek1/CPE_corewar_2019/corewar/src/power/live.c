/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** live
*/

#include "corewar.h"

void live(char *name_cor, int nb_cor, corewar_t *core)
{
    if (is_type(core->instruction[0], 1) == 3) {
        my_putstr("The player ");
        my_put_nbr(nb_cor);
        my_putchar('(');
        my_putstr(name_cor);
        my_putchar(')');
        my_putstr(" is alive\n");
        core->last_core = name_cor;
        core->living_cor += 1;
        return;
    }
    else
        return;
}