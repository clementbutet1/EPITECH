/*
** EPITECH PROJECT, 2020
** parenth.c
** File description:
** parenth
*/

#include "mysh.h"

int in_parenth(char *str, int p)
{
    int u = 0;
    int s = 0;

    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] == '(')
            u++;
        if (str[n] == ')')
            s++;
        if (p == u && s == 0)
            continue;
        if (str[n] != '(' && str[n] != ')' && str[n] != ' ' &&
            str[n] != '\t' && str[n] != '\n') {
            my_putstr("Badly placed ()'s.\n");
            return (1);
        }

    }
    return (0);
}

int check_arg_par(char *str, int *p, int *q)
{
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] == '(')
            *p += 1;
        if (str[n] == ')')
            *q += 1;
    }
    if (*p > *q) {
        my_putstr("Too many ('s.\n");
        return (1);
    }
    if (*p < *q) {
        my_putstr("Too many )'s.\n");
        return (1);
    }
    if (in_parenth(str, *p) == 1)
        return (1);
    return (0);
}

char *my_parenth(char *str, sh_t *sh)
{
    int p = 0;
    int q = 0;
    int i = 0;
    char *news;
    sh->parenth = 0;

    if (check_arg_par(str, &p, &q) == 1)
        sh->parenth = 2;
    if (p > 0 && sh->parenth != 2)
        sh->parenth = 1;
    news = malloc(sizeof(char) * my_strlen(sh->buffer) - q - p + 1);
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] == '(' || str[n] == ')')
            continue;
        news[i] = str[n];
        i++;
    }
    news[i] = '\0';
    return (news);
}