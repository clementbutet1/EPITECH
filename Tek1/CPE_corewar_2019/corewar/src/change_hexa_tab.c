/*
** EPITECH PROJECT, 2019
** change_hexa_tab.c
** File description:
** change_hexa_tab.c
*/

#include "corewar.h"

int special_strlen(int nb)
{
    int i = 0;

    for (; nb > 0; i++)
        nb = nb / 10;
    return (i);
}

char *put_tab_buffer_spe(char **tab)
{
    int size = 0;
    char *buffer = NULL;

    for (int i = 0; tab[i] != NULL; i++, size++)
        for (int j = 0; tab[i][j] != '\0'; j++)
            size++;
    size++;
    buffer = malloc(sizeof(char) * (size));
    size = 0;
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++, size++)
            buffer[size] = tab[i][j];
    }
    buffer[size] = '\0';
    return (buffer);
}

int change_tab_to_hexa(int *tab, int cpt)
{
    char **rslt = malloc(sizeof(char *) * (cpt + 1));
    int i = 0;
    char *buffer = NULL;
    int res = 0;

    for (; tab[i] != -1; i++) {
        rslt[i] = (my_converthexadecimalmi_tab_spe(tab[i],
        special_strlen(tab[i])));
    }
    rslt[i] = NULL;
    buffer = put_tab_buffer_spe(rslt);
    res = base_hexadecimal_to_int(buffer);
    return (res);
}

int change_magic_tab(int *tab)
{
    int *rslt = 0;
    int cpt = 0;
    int j = 0;
    int res = 0;

    for (int i = 0; tab[i] != -1; i++)
        if (tab[i] != 0)
            cpt++;
    rslt = malloc(sizeof(int) * (cpt + 1));
    for (int i = 0; tab[i] != -1; i++) {
        if (tab[i] != 0) {
            rslt[j] = tab[i];
            j++;
        }
    }
    rslt[j] = -1;
    res = change_tab_to_hexa(rslt, cpt);
    return (res);
}