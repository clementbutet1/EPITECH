/*
** EPITECH PROJECT, 2019
** check_directory.c
** File description:
** check_directory.c
*/

#include "my.h"
#include"mysh.h"

int check_dir(char *cmd)
{
    struct stat sb;

    if (stat(cmd, &sb) == -1)
        return (0);
    if (cmd[0] == '/')
        if (S_ISDIR(sb.st_mode) == 1) {
            my_putstr(cmd);
            my_putstr(": Permission denied.\n");
            return (0);
        }
    return (1);
}

int check_directory_executable(params_t *params, char *cmd, char **all_cmd)
{
    struct stat sta;

    if (stat(cmd, &sta) == 0 && ((S_ISDIR(sta.st_mode) ||
    sta.st_mode & S_IRWXU))) {
        if ((stat(cmd, &sta)) == 0 && (!(sta.st_mode &S_IXUSR))) {
            my_putstr(cmd);
            my_putstr(": Permission denied.\n");
            return (11);
        }
    }
    if (all_cmd[0][0] == '.')
        return (0);
    if (check_dir(cmd) == 0)
        return (11);
    return (0);
}