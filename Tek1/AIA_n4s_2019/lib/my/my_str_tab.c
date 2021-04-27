/*
** EPITECH PROJECT, 2019
** my_str_tab.c
** File description:
** my_str_tab.c
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

int my_count_word(char *str, char separator)
{
    int cpt = 1;

    for (int i = 0; str[i] != '\0' ; i++) {
        if (str[i] == '\0' || str[i] == separator)
            cpt++;
    }
    return (cpt);
}

int count_letter(char *word, char separator, int i)
{
    int cpt = 0;
    i = i + 2;

    while (word[i] != '\0' || word[i] != '\n') {
        if (word[i] == '\0' || word[i] == separator) {
            return (cpt + 1);
        }
        cpt++;
        i++;
    }
    return (cpt + 1);
}

char **my_str_tab(char *str, char separator)
{
    char **tab = NULL;
    int j = 0;
    int k = 0;
    int tmp = 0;
    int nb_word = my_count_word(str, separator);
    int size_word = 0;
    tab = malloc(sizeof(char *) * (nb_word + 2));
    int i = 0;

    for (; i != nb_word; i++, k++) {
        size_word = count_letter(str, separator, tmp);
        tab[i] = malloc(sizeof(char) * (size_word + 2));
        for (j = 0; j != size_word + 1; j++, k++)
            tab[i][j] = str[k];
        tmp += j;
        tmp++;
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}