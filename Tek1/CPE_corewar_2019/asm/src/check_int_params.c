/*
** EPITECH PROJECT, 2019
** check_int_params.c
** File description:
** check_int_params.c
*/

#include "asm.h"

int change_int_params2(instu_core_t *tmp, instu_core_t **instru, int i,
int line)
{
    instu_core_t *tmp2;
    int nb = 0;
    int size = 0;
    int *b = 0;

    tmp2 = *instru;
    for (; tmp2->line < line; tmp2 = tmp2->next);
    while (tmp2->line < tmp->line) {
        nb += tmp2->prog_size;
        tmp2 = tmp2->next;
    }
    for (int d = i; tmp->params[d] == -2; d++, size++);
    b = create_magic_tab_negative(nb * -1, size);
    for (int d = 0; tmp->params[i] == -2; i++, d++)
        tmp->params[i] = b[d];
    free(b);
    return (i);
}

int change_int_params(instu_core_t *tmp, instu_core_t **instru, int i,
int line)
{
    instu_core_t *tmp2;
    int nb = 0;
    int size = 0;
    int *b;

    if (tmp->line < line) {
        tmp2 = tmp;
        while (tmp2->line < line) {
            nb += tmp2->prog_size;
            tmp2 = tmp2->next;
        }
        for (int d = i; tmp->params[d] == -2; d++, size++);
        b = create_magic_tab_for_int(nb, size);
        for (int a = 0; tmp->params[i] == -2; i++, a++)
            tmp->params[i] = b[a];
    }
    if (tmp->line >= line)
        i = change_int_params2(tmp, instru, i, line);
    return (i - 1);
}