/*
** EPITECH PROJECT, 2019
** check_where.c
** File description:
** check_where.c
*/

#include "mysh.h"

void check_bulletin_where(char **cmd)
{
    char *bulltin[] = {"cd", "setenv", "unsetenv", "exit", "repeat", "echo",
    "where", "which", "env", "foreach", "alias", NULL};

    for (int j = 1; cmd[j] != NULL; j++)
        for (int i = 0; bulltin[i] != NULL; i++)
            if (my_strcmp(bulltin[i], cmd[j]) == 0) {
                my_putstr(cmd[j]);
                my_putstr(" is a shell built-in\n");
                break;
            }
    return;
}

void print_path(char *path)
{
    if (path != NULL && !access(path, F_OK)) {
        my_putstr(path);
        my_putchar('\n');
    }
    free(path);
    return;
}

int check_where(char **exe, sh_t *sh, char *name_cmd, int i)
{
    char *new_path = NULL;

    if (my_strcmp(name_cmd, exe[0]) != 0)
        return (0);
    for (; exe[i] != NULL; i++);
    if (i < 2) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("where: Too few arguments.\n");
        return (1);
    }
    check_bulletin_where(exe);
    for (int j = 1; exe[j] != NULL; j++)
        for (int i = 0, size = 0; sh->path.path[i] != NULL; i++) {
            size = my_strlen(sh->path.path[i]) + 1 + my_strlen(exe[j]);
            if (!(new_path = realloc(sh->path.path[i], sizeof(char) *
            (size + 1))))
                continue;
            new_path = my_strcat(my_strcat(new_path, "/"), exe[j]);
            print_path(new_path);
        }
    return (1);
}