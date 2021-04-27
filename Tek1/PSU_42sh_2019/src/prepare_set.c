/*
** EPITECH PROJECT, 2019
** prepare_set.c
** File description:
** prepare_set.c
*/

#include "mysh.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    while (a <= n) {
        dest[a] = src[a];
        dest[a + 1] = '\0';
        a++;
    }
    return (dest);
}

char *my_strcpy_spe(char const *src, int n)
{
    char *rslt = NULL;
    int a = my_strlen(src);
    int i = 0;
    int size_rslt = my_strlen(src) - n;

    rslt = malloc(sizeof(char) * (size_rslt + 2));
    for (; n != a; i++) {
        rslt[i] = src[n];
        n++;
    }
    rslt[i] = '\0';
    return (rslt);
}

char **set_line(int size_line, char *str, int size_egal)
{
    char *tmp = NULL;
    char *new_line = NULL;
    char **tb = NULL;

    tb = malloc(sizeof(char *) * 2);
    new_line = malloc(sizeof(char) * (size_line + 1));
    new_line = my_strncpy(new_line, str, size_egal);
    new_line = strcat(new_line, "\t");
    size_egal = size_egal + 2;
    tmp = malloc(sizeof(char) * (my_strlen(str)));
    tmp = my_strcpy_spe(str, size_egal);
    tb[0] = strdup(new_line);
    tb[1] = strdup(tmp);
    return (tb);
}

char **change_to_set(char **tb)
{
    int size_tab = 0;
    int size_egal = 0;
    char **t = NULL;
    char **new_tb = NULL;
    int i = 0;

    for (; tb[size_tab] != NULL; size_tab++);
    new_tb = malloc(sizeof(char *) * (size_tab + 1));
    for (int size_line = 0; tb[i] != NULL; i++) {
        for (size_egal = 0; tb[i][size_egal] != '='; size_egal++);
        size_egal--;
        size_line = my_strlen(tb[i]);
        t = set_line(size_line, tb[i], size_egal);
        size_tab = my_strlen(t[0]) + my_strlen(t[1]) + 1;
        new_tb[i] = malloc(sizeof(char) * size_tab);
        new_tb[i] = my_strcat(t[0], t[1]);
    }
    new_tb[i] = NULL;
    return (new_tb);
}