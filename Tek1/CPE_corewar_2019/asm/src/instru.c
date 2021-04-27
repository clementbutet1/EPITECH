/*
** EPITECH PROJECT, 2019
** instru.c
** File description:
** instru.c
*/

#include "asm.h"

int get_all_instru2(instu_core_t **instru, char *str, params_t *params, int ln)
{
    instu_core_t *new = malloc(sizeof(instu_core_t));
    int all_prog_size = 0;

    new->params = malloc(sizeof(int) * 1);
    new->params[0] = -1;
    new->label = params->label;
    new->prog_size = 0;
    all_prog_size += recup_instru(new, str, ln);
    append_l(instru, new);
    return (all_prog_size);
}

int get_all_instru(instu_core_t **instru, char **file, params_t *params)
{
    int i = 2;
    int all_prog_size = 0;

    for (; file[i] != NULL; i++) {
        all_prog_size += get_all_instru2(instru, file[i], params, i);
    }
    return (all_prog_size);
}