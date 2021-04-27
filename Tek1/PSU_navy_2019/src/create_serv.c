/*
** EPITECH PROJECT, 2019
** create_serv.c
** File description:
** create_serv.c
*/

#include "my.h"
#include "../include/navy.h"

void put_space_and_point(params_t *params, int k, int i, int j)
{
    if (params->map[i][j] == '.' && params->map[i][j + 1] == '.')
        params->map[i][j + 1] = ' ';
}

void complet_map(params_t *params, int k)
{
    params->map[k] = NULL;

    for (int i = 0; params->map[i] != NULL; i++)
        for (int j = 2; params->map[i][j] != '\n'; j++)
            put_space_and_point(params, k, i, j);
}

void create_map(params_t *params)
{
    int i = 2;
    int j = 0;
    int k = 1;
    params->map = malloc(sizeof(char *) * (12));
    params->map[0] = " |A B C D E F G H\n";
    params->map[1] = "-+---------------\n";

    for (; i != 10; i++) {
        params->map[i] = malloc(sizeof(char) * (19));
        params->map[i][0] = k + 48;
        k++;
        for (j = 2; j != 17; j = j + 1) {
            params->map[i][1] = '|';
            params->map[i][j] = '.';
        }
        params->map[i][j] = '\n';
        params->map[i][j + 1] = '\0';
    }
    complet_map(params, i);
}