/*
** EPITECH PROJECT, 2019
** unsetenv.c
** File description:
** unsetenv.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "include/mysh.h"

int check_unsetenv(params_t *params)
{
    if (params->envi == NULL)
        return (11);
    if (params->cmd[2] != NULL)
        return (11);
    if (params->cmd[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (11);
    }
    return (0);
}

int check_same_begin(char *elem_env, char *entry)
{
    int i = 0;
    int size = my_strlen(entry);
    int cpt = 0;

    while (elem_env[i] != '=') {
        if (elem_env[i] == entry[i])
            cpt++;
        else if (elem_env[i] != '\0' || entry[i] != '\0')
            return (0);
        i++;
    }
    if (cpt == size)
        return (11);
    else
        return (0);
}

int unsetenv_funct(params_t *params)
{
    char *element = params->cmd[1];
    char **new_envi = NULL;
    int j = 0;
    int size = 0;

    if (check_unsetenv(params) == 11)
        return (11);
    for (; params->envi[size] != NULL; size++);
    new_envi = malloc(sizeof(char *) * size + 2);
    for (int i = 0; params->envi[i] != NULL; i++, j++) {
        if (check_same_begin(params->envi[i], element) == 11) {
            params->envi[i] = 0;
            i++;
        }
        new_envi[j] = params->envi[i];
    }
    params->envi = NULL;
    params->envi = new_envi;
    return (0);
}

int check_if_path(params_t *params)
{
    for (int i = 0; params->envi[i] != NULL; i++) {
        if (params->envi[i][0] == 'P' && params->envi[i][1] == 'A'
        && params->envi[i][2] == 'T' && params->envi[i][3] == 'H') {
            return (0);
        }
    }
    return (11);
}