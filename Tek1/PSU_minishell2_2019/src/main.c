/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my.h"
#include"mysh.h"

int main(int ac, char **av, char **env)
{
    params_t params;

    if (ac != 1)
        exit (84);
    init_struct(&params);
    create_envi(env, &params);
    my_putstr("$> ");
    boucl_inf(env, &params);
    return (0);
}