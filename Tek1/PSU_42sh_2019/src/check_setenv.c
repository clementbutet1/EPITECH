/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** check_setenv.c
*/

#include "mysh.h"

void modif_env3(char **exe, sh_t *sh)
{
    int i = 0;
    char **new_env;
    int d = does_env_exist(exe, sh);

    if (d != -1) {
        free(sh->path.env[d]);
        sh->path.env[d] = my_strcat(exe[1], exe[2]);
    }
    else {
        new_env = malloc(sizeof(char *) * (sh->taille_env + 1));
        for (i = 0; sh->path.env[i] != NULL; i++)
            new_env[i] = sh->path.env[i];
        new_env[i++] = my_strcat(exe[1], exe[2]);
        new_env[i] = NULL;
        free(sh->path.env);
        sh->path.env = new_env;
        sh->taille_env += 1;
    }
}

int modif_env2(char **exe, sh_t *sh)
{
    for (int a = 0; exe[1][a] != '\0'; a++) {
        if ((exe[1][a] >= '0' && exe[1][a] <= '9') || (exe[1][a] >=
            'a' && exe[1][a] <= 'z') || (exe[1][a] >= 'A' && exe[1][a]
            <= 'Z'))
            a = a;
        else if (execute_double_pipe(sh) == 1)
            return (1);
        else {
            my_putstr_error("setenv: Variable name must contain alphanumeric");
            my_putstr_error(" characters.\n");
            return (1);
        }
    }
    return (0);
}

int modif_env(char **exe, sh_t *sh)
{
    int i = 0;

    while (exe[i] != NULL)
        i++;
    if (i > 3) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("setenv: Too many arguments.\n");
        return (0);
    }
    else if (i == 1) {
        print_env(sh);
        return (0);
    }
    if (sh->parenth == 1)
        return (0);
    if (modif_env2(exe, sh) == 1)
        return (0);
    add_equal(exe, my_strlen(exe[1]));
    modif_env3(exe, sh);
    return (0);
}

int check_setenv(char **exe, sh_t *sh)
{
    char *setenv = "setenv";
    int a = 0;
    int i = 0;

    for (; i < 6 && exe[0][i] != '\0'; i++) {
        if (exe[0][i] == setenv[i])
            a++;
        else
            return (0);
    }
    if (exe[0][i] != ' ' && exe[0][i] != '\0')
        return (0);
    if (a == 6) {
        modif_env(exe, sh);
        return (1);
    }
    return (-1);
}