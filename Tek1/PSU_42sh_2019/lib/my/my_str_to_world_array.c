/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_str_to_world_array.c
*/

#include "my.h"

char **create_executable33(char *buffer, char sepa, char **tab)
{
    int c = 0;
    int d = 0;
    int a = 0;

    for (int i = 0; buffer[i] != '\0'; i++, c++) {
        if (buffer[i] == sepa) {
            tab[d++][c] = '\0';
            tab[d] = &buffer[i + 1];
            c = -1;
        }
    }
    tab[d++][c] = '\0';
    tab[d] = NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i] = my_strdup(tab[i]);
    }
    return (tab);
}

int create_executable22(char *buffer, char sepa)
{
    int d = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == sepa)
            d++;
    }
    return (d);
}

char **my_str_to_word_array(char *buffer, char sepa)
{
    int d = 0;
    char **tab;
    char **s;

    d = create_executable22(buffer, sepa);
    tab = malloc(sizeof(char *) * (d + 2));
    for (int s = 0; s < d + 2; s++)
        tab[s] = NULL;
    tab[0] = &buffer[0];
    tab = create_executable33(buffer, sepa, tab);
    if (tab[d][0] == '\0') {
        s = malloc(sizeof(char *) * (d + 1));
        for (int i = 0; i < d; i++)
            s[i] = tab[i];
        s[d] = NULL;
        free(tab[d + 1]);
        free(tab);
        return (s);
    }
    return (tab);
}