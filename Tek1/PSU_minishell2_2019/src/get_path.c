/*
** EPITECH PROJECT, 2019
** get_path.c
** File description:
** get_path.c
*/

#include "my.h"
#include"mysh.h"

char *get_the_path(char *env, params_t *params)
{
    int i = 0;
    int cpt = 0;
    int k = 0;
    int total = 0;
    char *rslt = NULL;

    for (; env[i] != '\0'; i++);
    for (; env[i] != '='; i--, cpt++);
    i++;
    rslt = malloc(sizeof(char) * cpt + 2);
    total = i + cpt;
    for (;i != total; i++) {
        rslt[k] = env[i];
        k++;
    }
    rslt[k] = '\0';
    return (rslt);
}