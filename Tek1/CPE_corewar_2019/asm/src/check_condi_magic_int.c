/*
** EPITECH PROJECT, 2019
** check_condi_magic_int.c
** File description:
** check_condi_magic_int.c
*/

#include "asm.h"

int *check_condi_magic_dir(instu_core_t *new, char *str, int c, int *b)
{
    if (c < 0)
        b = create_magic_tab_negative(c, new->dir_size);
    else
        b = create_magic_tab(str, new->dir_size);
    return (b);
}

int *check_condi_magic_indi(char *str, int c, int *b)
{
    if (c < 0)
        b = create_magic_tab_negative(c, IND_SIZE);
    else
        b = create_magic_tab(str, IND_SIZE);
    return (b);
}

void init_struct_clean_file(params_t *pa)
{
    pa->label = malloc(sizeof(char *) * 1);
    pa->line = malloc(sizeof(int) * 1);
    pa->line[0] = -1;
    pa->label[0] = NULL;
    return;
}

int *add_incrementation_verif_get(instu_core_t *new, int *nb_arg, int *b)
{
    *nb_arg += 1;
    new->params = add_two_tab_int(new->params, b);
    return (nb_arg);
}