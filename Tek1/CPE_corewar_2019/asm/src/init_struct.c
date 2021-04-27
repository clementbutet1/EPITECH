/*
** EPITECH PROJECT, 2019
** init_struct.c
** File description:
** init_struct.c
*/

#include "asm.h"

int special_strlen(int nb)
{
    int i = 0;

    for (; nb > 0; i++)
        nb = nb / 10;
    return (i);
}

void init_struct(params_t *params)
{
    params->comment = NULL;
    params->name = NULL;
    params->magic_nb = 0;
}

void free_list(instu_core_t **instru)
{
    instu_core_t *tmp = *instru;
    instu_core_t *tmp2;

    while (tmp != NULL) {
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2->params);
        free(tmp2);
    }
}

void free_struct(params_t *params, core_t *core, instu_core_t **instru)
{
    free(core->comment);
    free(core->name);
    free(params->comment);
    free(params->name);
    free(params->magic_nb);
    free(params->line);
    free_tab(params->label);
    free_list(instru);
}