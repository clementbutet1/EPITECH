/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019_orgenise
** File description:
** my_str_tab.c
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_count_word(char *str, char separator)
{
    int cpt = 1;

    for (int i = 0; str[i] != '\0' && str[cpt] != '\n'; i++) {
        if (str[i] == separator || str[i] == '\0')
            cpt++;
    }
    return (cpt);
}

char **my_str_tab(char *str, char s)
{
    int nb_word = my_count_word(str, s);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int cpt = 0;
    int n = 0;
    int j = 0;

    for (int j = 0; j < nb_word; j++) {
        for (;str[cpt] != s && str[cpt] != '\0' && str[cpt] != '\n'; cpt++);
        cpt++;
        tab[j] = malloc(sizeof(char) * cpt);
    }
    for (int i = 0; j != nb_word; j++, n++) {
        for (i = 0; str[n] != s && str[n] != '\0' && str[n] != '\n'; i++, n++)
            tab[j][i] = str[n];
        tab[j][i] = '\0';
    }
    tab[j] = NULL;
    return (tab);
}