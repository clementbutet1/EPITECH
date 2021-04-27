/*
** EPITECH PROJECT, 2019
** opt_funct.c
** File description:
** opt_funct.c
*/

#include "../include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/mysh.h"

void print_cmd_not_found(params_t *params, char *cmd)
{
    if (params->path == NULL &&
    (check_same_word(params->cmd[0], "cd") != 11)) {
        my_putstr(cmd);
        my_putstr(": Command not found.\n");
        return;
    }
    return;
}

void check_error_segfault(int status)
{
    if (status == 139) {
        my_putstr("Segmentation fault (core dump)\n");
        return;
    }
    if (status == 11) {
        my_putstr("Segmentation fault\n");
        return;
    }
    if (status == 8) {
        my_putstr("Floating exception\n");
        return;
    }
    if (status == 136) {
        my_putstr("Floating exception (core dump)\n");
        return;
    }
    return;
}

int check_same_word(char *str, char *str1)
{
    int i = 0;
    int size = my_strlen(str);
    int cpt = 0;

    while (str[i] != '\0' || str1[i] != '\0') {
        if (str[i] == str1[i])
            cpt++;
        else if (str[i] != '\0' || str1[i] != '\0')
            return (0);
        i++;
    }
    if (cpt == size)
        return (11);
    else
        return (0);
}

int check_in_the_file(char *cmd, params_t *params, size_t size)
{
    DIR *fd = opendir("./");
    struct dirent *dirent;
    params->file = 0;

    if (params->path != NULL && params->cmd[0] == "cd")
        return (0);
    if (fd == NULL)
        return (11);
    while ((dirent = readdir(fd)) != 0) {
        if (access(cmd, X_OK) != -1) {
            params->file = 1;
            params->good_path = cmd;
            closedir(fd);
            execute_cmd(cmd, params, size);
            return (11);
        }
    }
    print_cmd_not_found(params, cmd);
    return (0);
}