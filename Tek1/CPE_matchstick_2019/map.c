/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** map.c
*/

#include "include/my_matchstick.h"
#include <stdlib.h>

void print_map(params_t *params)
{
    for (int i = 0; params->map[i] != NULL; i++)
        my_putstr(params->map[i]);
}

void check_map(params_t *params, int i, int z)
{
    for (z = 1; z <= params->size_large; z++)
        params->map[i][z] = 32;
    params->map[i][z] = '*';
    params->map[i][z + 1] = '\n';
    z = 0;
}

void create_map(params_t *params)
{
    int i = 0;
    int z = 0;

    params->map = malloc(sizeof(char *) * (params->size_height + 5));
    params->map[i] = params->line;
    for (i = 1; i <= params->size_height; i++) {
        params->map[i] = malloc(sizeof(char) * (params->size_large + 5));
        params->map[i][z] = '*';
        check_map(params, i, z);
    }
    params->map[i] = params->line;
    params->map[i+1] = NULL;
}

void check_size_map(params_t *params)
{
    params->size_large = 1;
    int i = 0;
    int zs = 1;
    int zp = 0;

    for (int z = 1; z != params->size_height; z++)
        params->size_large += 2;
    params->line = malloc(sizeof(char *) * (params->size_large + 1));
    while (i != params->size_large + 2) {
        params->line[i] = '*';
        i++;
    }
    params->line[i] = '\n';
    create_map(params);
    zp = params->size_large + 1;
    for (int i = params->size_height; i != 0; i--, zs++, zp--)
        for (int z = zs; z != zp; z++)
            params->map[i][z] = '|';
    print_map(params);
}