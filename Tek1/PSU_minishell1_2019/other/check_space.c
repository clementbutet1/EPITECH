/*
** EPITECH PROJECT, 2019
** check_space.c
** File description:
** check_space.c
*/

#include "../include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include "../include/mysh.h"

int check_file_executable(params_t *params, char *cmd, size_t size)
{
    struct stat sta;

    if ((stat(cmd, &sta) >= 0) && (sta.st_mode > 0) &&
    (S_IEXEC & sta.st_mode)) {
        params->exe = 0;
        return (0);
    } else {
        params->exe = 1;
        my_putstr(cmd);
        my_putstr(": Permission denied.\n");
        return (11);
    }
    return (0);
}

int check_directory_executable(params_t *params, char *cmd)
{
    struct stat sta;

    if (stat(cmd, &sta) == 0 && S_ISDIR(sta.st_mode)) {
        my_putstr(cmd);
        my_putstr(": Permission denied.\n");
        return (11);
    }
    return (0);
}

int check_space_or_tab(char *str, char *rslt, int i)
{
    for (; str[i] == ' ' || str[i] == '\t'; i++)
        return (i);
}

char *check_end_space(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    while (check_cara(str[i]) != 1)
        i--;
    i++;
    str[i] = '\0';
    return (str);
}

int check_begin_space(char *str, int i)
{
    for (; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= '0' && str[i] <= '9' || str[i] == '/' ||
        str[i] == '.' || str[i] == '~' || str[i] == '-' ||
        str[i] == '_')) {
            return (i);
        }
    }
}