/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** env.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "include/mysh.h"

void print_env(params_t *params)
{
    if (params->envi == NULL)
        return;
    if (params->cmd[1] != NULL) {
        my_putstr(params->cmd[0]);
        my_putstr(": ");
        my_putstr(params->cmd[1]);
        my_putstr(": No such file or directory\n");
        return;
    }
    for (int i = 0; params->envi[i] != NULL; i++) {
        my_putstr(params->envi[i]);
        my_putchar('\n');
    }
}

char *get_the_path(char *env, params_t *params)
{
    int i = 0;
    int cpt = 0;
    int k = 0;
    int total = 0;
    char *rslt = NULL;

    for (; env[i] != '\0'; i++);
    for (; env[i] != '='; i--, cpt++);
    i++;
    rslt = malloc(sizeof(char) * cpt + 2);
    total = i + cpt;
    for (;i != total; i++) {
        rslt[k] = env[i];
        k++;
    }
    rslt[k] = '\0';
    return (rslt);
}
