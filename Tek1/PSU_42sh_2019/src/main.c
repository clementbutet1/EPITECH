/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** mysh.c
*/

#include "mysh.h"

int main(int ac, char *av[], char *env[])
{
    sh_t sh;
    sh.path.env = env;
    sh.hist.history = NULL;
    time_t now = 0;

    signal(SIGINT, handler_siguint);
    init_sh(&sh, env, ac, av);
    return (boucl_inf(&sh, now));
    free_end(&sh);
    return (0);
}