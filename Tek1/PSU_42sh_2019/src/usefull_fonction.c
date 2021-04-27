/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** usefull_fonction.c
*/

#include "mysh.h"

int is_a_directory(char **exe)
{
    struct stat st;

    stat(exe[0], &st);
    if (st.st_mode & S_IFDIR)
        return (-1);
    return (0);
}

int verif_type2(char **exe, sh_t *sh)
{
    if (access(exe[0], F_OK | X_OK) == -1 ||
    is_a_directory(exe) == -1) {
        if (execute_double_pipe(sh) != 1) {
            my_putstr_error(exe[0]);
            my_putstr_error(": Permission denied.\n");
        }
        return (-1);
    }
    return (0);
}

int verif_type(char **exe, sh_t *sh)
{
    int d = 0;

    if (exe[0][0] == '\0')
        return (-1);
    if (access(exe[0], F_OK) == -1) {
        for (; sh->path.path[d] != NULL && access(my_strcat_slash
        (sh->path.path[d], exe[0]), F_OK) == -1; d++);
        if (sh->path.path[d] == NULL) {
            if (execute_double_pipe(sh) != 1) {
                my_putstr_error(exe[0]);
                my_putstr_error(": Command not found.\n");
            }
            return (-1);
        }
        else
            exe[0] = my_strcat_slash(sh->path.path[d], exe[0]);
    }
    if (verif_type2(exe, sh) == -1)
        return (-1);
    return (0);
}

int verif_exit(char **exe, sh_t *sh)
{
    int i = 0;

    while (exe[i])
        i++;
    if (i > 2 || exe[1][0] <= '0' || exe[1][0] >= '9') {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("exit: Expression Syntax.\n");
        return (3);
    }
    for (i = 0; exe[1][i] != '\0'; i++) {
        if (exe[1][i] < '0' || exe[1][i] > '9') {
            if (execute_double_pipe(sh) != 1)
                my_putstr_error("exit: Badly formed number.\n");
            return (3);
        }
    }
    (isatty(STDIN_FILENO)) ? my_putstr("exit\n") : 0;
    sh->exit = my_getnbr(exe[1]) % 256;
    return (1);
}

int check_exit(char **exe, sh_t *sh)
{
    char *xit = "exit";
    int a = 0;
    int i = 0;

    for (; i < 4 && exe[0][i] != '\0'; i++) {
        if (exe[0][i] == xit[i])
            a++;
        else
            return (0);
    }
    for (; exe[0][i] != '\0' && exe[0][i] != '\n'; i++) {
        if (exe[0][i] != ' ')
            return (0);
    }
    if (a == 4 && exe[1] == NULL) {
        (isatty(STDIN_FILENO)) ? my_putstr("exit\n") : 0;
        exit (0);
    }
    if (a == 4)
        return (verif_exit(exe, sh));
    return (-1);
}