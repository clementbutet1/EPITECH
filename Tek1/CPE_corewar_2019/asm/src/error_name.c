/*
** EPITECH PROJECT, 2019
** error_name.c
** File description:
** error_name.c
*/

#include "asm.h"

char **check_tab(char **tab, char *str)
{
    int size = my_strlen(tab[1]);
    char **rslt = NULL;
    int cpt = 0;

    for (int i = 0; tab[1][i] != '\0'; i++)
        if ((tab[1][i] == '\n'))
            cpt++;
    if (cpt == 0) {
        rslt = malloc(sizeof(char *) * 3);
        rslt[0] = my_strdup(tab[0]);
        str = malloc(sizeof(char) * (size + 2));
        str = my_strncpy_spe(str, tab[1], size);
        str[size] = '\n';
        str[size + 1] = '\0';
        rslt[1] = str;
        rslt[2] = NULL;
        return (rslt);
    }
    return (tab);
}

void check_error_begin(char **tab)
{
    char *name = malloc(sizeof(char) * 7);
    char *comment = malloc(sizeof(char) * 10);

    name = my_strncpy_spe(name, tab[0], 5);
    comment = my_strncpy_spe(comment, tab[1], 8);
    if ((check_same_word(name, ".name ") != 11) ||
    (check_same_word(comment, ".comment ") != 11)) {
        free(name);
        free(comment);
        my_putstr_error("Error : No name or no comment or missing space");
    }
    free(name);
    free(comment);
    return;
}