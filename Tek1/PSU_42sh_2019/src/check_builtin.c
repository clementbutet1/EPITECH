/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** check_builtin
*/

#include "mysh.h"

int check_all_builtin(char **exe, sh_t *sh)
{
    if (check_which(exe, sh, "which", 0) == 1)
        return (1);
    if (check_unset(exe, sh, "unset") == 1)
        return (1);
    if (check_history(exe, sh, "history", 0) == 1)
        return (1);
    if (check_foreach(exe, sh) == 1)
        return 1;
    if (check_set(exe, sh, "set") == 1)
        return (1);
    return 0;
}

int check_all_function(char **exe, sh_t *sh)
{
    if (check_unalias(exe, sh) == 1)
        return (1);
    if (check_alias(exe, sh) == 1)
        return (1);
    if (check_env(exe, sh) == 1)
        return (1);
    if (check_setenv(exe, sh) == 1)
        return (1);
    if (check_unsetenv(exe, sh) == 1)
        return (1);
    if (check_echo(exe) == 1)
        return (1);
    if (check_repeat(exe, sh) == 1)
        return (1);
    if (check_where(exe, sh, "where", 0) == 1)
        return (1);
    if (check_all_builtin(exe, sh) == 1)
        return 1;
    return (0);
}