/*
** EPITECH PROJECT, 2019
** setenv.c
** File description:
** setenv.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "include/mysh.h"

void free_and_replace(params_t *params, char *fst_el, char *scd_el, int ln)
{
    int i = 0;
    int save = 0;
    int size = 0;
    char *new_path = NULL;

    for (; fst_el[i] == params->envi[ln][i]; i++);
    i++;
    save = i;
    for (; params->envi[ln][i] != '\0'; i++)
        params->envi[ln][i] = 0;
    new_path = my_strcat(params->envi[ln], scd_el);
    params->envi[ln] = NULL;
    params->envi[ln] = new_path;
}

int check_same_env(params_t *params, char *fst_el, char *scd_el)
{
    int j = 0;

    if (params->envi == NULL)
        return (11);
    for (int i = 0; params->envi[i] != NULL; i++, j++) {
        if (check_same_begin(params->envi[i], fst_el) == 11) {
            free_and_replace(params, fst_el, scd_el, i);
            return (0);
        }
    }
    return (11);
}

int check_exit_setenv(params_t *params)
{
    if (params->cmd[1] == NULL && params->cmd[2] == NULL) {
        print_env(params);
        return (11);
    }
    if (params->cmd[3] != NULL || (params->cmd[1] != NULL &&
        params->cmd[2] == NULL))
        return (11);
    return (0);
}

void different_env(params_t *params, char *fst_el, char *scd_el)
{
    char **new_envi2 = params->envi;
    char *new_line = NULL;
    char *final_line = NULL;
    int ln = 0;
    int size_env = 0;

    for (; params->envi[size_env] != NULL; size_env++);
    new_envi2 = malloc(sizeof(char *) * size_env + 4);
    for (int i = 0; i != size_env; i++)
        new_envi2[i] = my_strdup(params->envi[i]);
    for (; ln != size_env + 1; ln++);
    ln--;
    new_line = my_strcat(fst_el, "=");
    final_line = my_strcat(new_line, scd_el);
    new_envi2[ln] = final_line;
    new_envi2[ln + 1] = NULL;
    params->envi = NULL;
    params->envi = new_envi2;
    return;
}

void setenv_funct(params_t *params)
{
    char *first_elem = params->cmd[1];
    char *scd_elem = params->cmd[2];

    if (params->envi == NULL)
        return;
    if (params->cmd[1] != NULL && params->cmd[2] == NULL)
        write_one_element(params, first_elem);
    if (check_exit_setenv(params) == 11)
        return;
    if (check_exit_cara_env(params, first_elem, scd_elem) == 11)
        return;
    if (check_same_env(params, first_elem, scd_elem) == 0)
        return;
    different_env(params, first_elem, scd_elem);
    return;
}
