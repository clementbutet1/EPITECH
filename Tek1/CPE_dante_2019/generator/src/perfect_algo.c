/*
** EPITECH PROJECT, 2019
** generator
** File description:
** perfect_algo.c
*/

#include "my.h"
#include "generator.h"

void put_condi(params_t *pa, int i, int random)
{
    for (int j = 2; j < pa->max_lenght; j += 2) {
        random = rand() % 2;
        if (random == 0) {
            pa->lab_perfect[i][j] = '*';
            pa->lab_perfect[i - 1][j] = '*';
        } else {
            pa->lab_perfect[i][j] = '*';
            pa->lab_perfect[i][j - 1] = '*';
        }
    }
    return;
}

void create_perfect_lab(params_t *pa)
{
    int random = 0;

    for (int j = 0; j < pa->max_height; j++)
        for (int i = 0; i < pa->max_lenght; i++)
            pa->lab_perfect[j][i] = 'X';
    for (int i = 0; i < pa->max_lenght; i++)
        pa->lab_perfect[0][i] = '*';
    for (int j = 0; j < pa->max_height; j++)
        pa->lab_perfect[j][0] = '*';
    pa->lab_perfect[pa->max_height - 1][pa->max_lenght - 1] = '*';
    for (int i = 2; i < pa->max_height; i += 2)
        put_condi(pa, i, random);
    ((random == 0) ? (pa->lab_perfect[pa->max_height - 2]
    [pa->max_lenght - 1] = '*') : (pa->lab_perfect[pa->max_height - 1]
    [pa->max_lenght- 2] = '*'));
    print_map(pa->lab_perfect, pa);
    return;
}