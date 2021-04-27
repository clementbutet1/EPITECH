/*
** EPITECH PROJECT, 2019
** check_error_dir.c
** File description:
** check_error_dir.c
*/

#include "asm.h"

void check_error_get_direct(instu_core_t *new, int *nb_arg)
{
    if (new->tab.type[*nb_arg] < 2 || new->tab.type[*nb_arg] == 4 ||
        new->tab.type[*nb_arg] == 5)
        my_putstr_error("Error: ASM - bad arguments");
    return;
}

void check_error_indirect(instu_core_t *new, int *nb_arg)
{
    if (new->tab.type[*nb_arg] < 4)
        my_putstr_error("Error: ASM - bad arguments");
    return;
}

int *create_magic_tab_for_int(int nb, int size)
{
    int cpt = 0;
    char *magic_nb = my_revstr(my_converthexadecimalmi_tab_spe(nb,
    special_strlen(nb)));
    int *rslt = malloc(sizeof(int) * (size + 1));
    char *new_nb = NULL;

    for (int i = 0; i < size; i++)
        rslt[i] = 0;
    rslt[size] = -1;
    for (int i = 0; magic_nb[i] != '\0'; i++) {
        if (i % 2 == 0) {
            new_nb = malloc(sizeof(char) * 3);
            new_nb = separe_magic_nb(new_nb, magic_nb, i);
            rslt = base_hexadecima_to_int_tab(my_revstr(new_nb), cpt, rslt);
            cpt++;
            free(new_nb);
        }
    }
    free(magic_nb);
    rslt = put_in_good_tab(rslt, size);
    return (rslt);
}