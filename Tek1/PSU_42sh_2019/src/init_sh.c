/*
** EPITECH PROJECT, 2019
** init_sh.c
** File description:
** init_sh.c
*/

#include "mysh.h"

char **copy_tab(char **tb)
{
    int size_tab = 0;
    char **new_tab = NULL;
    int i = 0;

    for (; tb[size_tab] != NULL; size_tab++);
    new_tab = malloc(sizeof(char *) * (size_tab + 1));
    for (; tb[i] != NULL; i++) {
        new_tab[i] = my_strdup(tb[i]);
    }
    new_tab[i] = NULL;
    return (new_tab);
}

void function_help(int ac, char **av)
{
    if (av[0] == NULL)
        exit (84);
    if (ac != 1)
        exit (84);
    return;
}

void init_sh2(sh_t *sh, char **env)
{
    sh->spipe.fd_in = dup(STDIN_FILENO);
    sh->spipe.fd_out = dup(STDOUT_FILENO);
    sh->spipe.is_double_pipe = 0;
    if (env != NULL) {
        sh->set = copy_tab(env);
        sh->set = change_to_set(sh->set);
    } else
        sh->set = NULL;
    sh->spipe.double_and = NULL;
    sh->spipe.double_pipe = NULL;
}

void init_sh(sh_t *sh, char **env, int ac, char **av)
{
    int i = 0;

    create_alias_tab(sh);
    function_help(ac, av);
    sh->taille_env = -1;
    sh->repertoire = NULL;
    sh->path.home = NULL;
    sh->path.pwd = NULL;
    sh->path.env = malloc(sizeof(char *) * 1);
    sh->path.env[0] = NULL;
    if (env != NULL)
        sh->path.env = my_strdup_2d(env);
    find_path(sh);
    while (sh->path.env[i] != NULL)
        i++;
    sh->taille_env = i + 1;
    find_main_directory(sh, 0);
    check_cd_tiret2(sh);
    sh->exit = 0;
    init_sh2(sh, env);
}