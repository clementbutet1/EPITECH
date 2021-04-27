/*
** EPITECH PROJECT, 2019
** other_funct.c
** File description:
** other_funct.c
*/

#include "../include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include "../include/mysh.h"

void check_error_excve(char *cmd, params_t *params, size_t size, int error)
{
    if (errno == 8) {
        my_putstr(cmd);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        exit (0);
    } else {
        strerror(error);
        my_putstr(cmd);
        my_putstr(": Command not found.\n");
        exit (0);
    }
}

int check_exit_cara_env(params_t *params, char *str, char *scd_el)
{
    int i = 0;

    if ((str[0] >= '0' && str[0] <= '9')) {
        my_putstr(params->cmd[0]);
        my_putstr(": Variable name must begin with a letter.\n");
        return (11);
    }
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' &&
        str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            my_putstr(params->cmd[0]);
            my_putstr(": Variable name must contain alphanumeric ");
            my_putstr("characters.\n");
            return (11);
        }
        i++;
    }
    return (0);
}

void write_one_element(params_t *params, char *fst_el)
{
    char **new_envi2 = params->envi;
    char *new_line = NULL;
    int ln = 0;
    int size_env = 0;

    for (; params->envi[size_env] != NULL; size_env++);
    new_envi2 = malloc(sizeof(char *) * size_env + 4);
    for (int i = 0; i != size_env; i++)
        new_envi2[i] = my_strdup(params->envi[i]);
    for (; ln != size_env + 1; ln++);
    ln--;
    new_line = my_strcat(fst_el, "=");
    new_envi2[ln] = new_line;
    new_envi2[ln + 1] = NULL;
    params->envi = NULL;
    params->envi = new_envi2;
    return;
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

int check_tab_and_space(char *str, int i, int c)
{
    if (str[i] == '\t')
        c = c + 1;
    if (str[i] == ' ')
        c = c + 1;
    return (c);
}