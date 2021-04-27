/*
** EPITECH PROJECT, 2019
** executable.c
** File description:
** executable.c
*/

#include "my.h"
#include"mysh.h"

char *check_executable(char *cmd, params_t *params)
{
    char *rslt = NULL;
    int sz = my_strlen(params->cmd[0]);

    if ((cmd[0] == '.' && cmd[1] == '/')) {
        rslt = malloc(sizeof(char *) * (sz + 2));
        rslt = params->cmd[0];
        if (check_file_executable(params, rslt) == 11)
            return (NULL);
        return (rslt);
    }
    rslt = NULL;
    return (rslt);
}

char *check_access(int len, char *rslt, params_t *params)
{
    for (int i = 0; params->path_tab[i]; i = i + 1) {
        rslt = malloc(sizeof(char *) *
        (len + my_strlen(params->path_tab[i]) + 2));
        rslt = params->path_tab[i];
        rslt = my_strcat(rslt, "/");
        rslt = my_strcat(rslt, params->cmd[0]);
        if (access(rslt, R_OK) == 0)
            return (rslt);
    }
    free(rslt);
    return (NULL);
}

int check_in_the_file(char *cmd, params_t *params, char **all_cmd)
{
    DIR *fd = opendir("./");
    struct dirent *dirent;
    params->file = 0;

    if (params->path != NULL && all_cmd[0] == "cd")
        return (0);
    if (fd == NULL)
        return (11);
    while ((dirent = readdir(fd)) != 0) {
        if (access(cmd, X_OK) != -1) {
            params->file = 1;
            params->good_path = cmd;
            closedir(fd);
            execute_cmd(cmd, params, all_cmd);
            return (11);
        }
    }
    return (0);
}

int check_file_executable(params_t *params, char *cmd)
{
    struct stat sta;

    if (access(params->cmd[0], X_OK) == 0 && opendir(params->cmd[0]) == NULL
    && params->cmd[0][0] == '.' && params->cmd[0][1] == '/') {
        if (stat(cmd, &sta) == 0 && (sta.st_mode & S_IRWXU)) {
            params->exe = 0;
            return (0);
        } else {
            my_putstr(cmd);
            my_putstr(": Permission denied.\n");
            return (11);
        }
    }
    return (0);
}