/*
** EPITECH PROJECT, 2019
** check_wich.c
** File description:
** check_wich.c
*/

#include "mysh.h"

char *check_access(int len, char *rslt, sh_t *sh, char *cmd)
{
    for (int i = 0; sh->path.path[i]; i = i + 1) {
        rslt = malloc(sizeof(char *) *
        (len + my_strlen(sh->path.path[i]) + 2));
        rslt = sh->path.path[i];
        rslt = my_strcat(rslt, "/");
        rslt = my_strcat(rslt, cmd);
        if (access(rslt, R_OK) == 0)
            return (rslt);
    }
    free(rslt);
    return (NULL);
}

int check_bulletin_which(char *cmd)
{
    char *bulltin[] = {"cd", "setenv", "unsetenv", "exit", "repeat", "echo",
    "where", "which", "env", "foreach", "alias", NULL};

    for (int i = 0; bulltin[i] != NULL; i++)
        if (my_strcmp(bulltin[i], cmd) == 0) {
            my_putstr(cmd);
            my_putstr(": shell built-in command.\n");
            return (1);
        }
    return (0);
}

void execute_which(char **exe, sh_t *sh)
{
    char *new_path = NULL;

    for (int j = 1, size = 0; exe[j] != NULL; j++) {
        size = my_strlen(exe[j]);
        new_path = check_access(size, new_path, sh, exe[j]);
        if (check_bulletin_which(exe[j]) == 1)
            continue;
        if (new_path != NULL) {
            puts(new_path);
            continue;
        }
        else {
            my_putstr(exe[j]);
            my_putstr(": Command not found.\n");
        }
    }
    free(new_path);
}

int check_which(char **exe, sh_t *sh, char *name_cmd, int i)
{
    if (my_strcmp(name_cmd, exe[0]) != 0)
        return (0);
    for (; exe[i] != NULL; i++);
    if (i < 2) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("which: Too few arguments.\n");
        return (1);
    }
    execute_which(exe, sh);
    return (1);
}