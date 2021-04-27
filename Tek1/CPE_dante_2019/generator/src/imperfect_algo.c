/*
** EPITECH PROJECT, 2019
** imperfect_lab.c
** File description:
** imperfect_lab.c
*/

#include "my.h"
#include "generator.h"

void create_impefect_lab3(params_t *pa, int random)
{
    ((random == 0) ? (pa->lab_impefect[pa->max_height - 2]
    [pa->max_lenght - 1] = '*') : (pa->lab_impefect[pa->max_height - 1]
    [pa->max_lenght - 2] = '*'));
    for (int j = 0; j < pa->max_height; j++) {
        for (int i = 0; i < pa->max_lenght; i++) {
            random = rand() % (pa->max_lenght * 10);
            if (random == 0)
                pa->lab_impefect[j][i] = '*';
            pa->lab_impefect[1][2] = '*';
            pa->lab_impefect[2][2] = '*';
            pa->lab_impefect[2][1] = '*';
        }
    }
    print_map(pa->lab_impefect, pa);
    return;
}

void create_imperfect_lab2(params_t *pa, int i, int random)
{
    for (int j = 2; j < pa->max_lenght; j += 2) {
        random = rand() % 2;
        if (random == 0) {
            pa->lab_impefect[i][j] = '*';
            pa->lab_impefect[i - 1][j] = '*';
            }
        else {
            pa->lab_impefect[i][j] = '*';
            pa->lab_impefect[i][j - 1] = '*';
        }
    }
    return;
}

void create_imperfect_lab(params_t *pa)
{
    int random = 0;
    int k = 0;

    for (int j = 0; j < pa->max_height; j++)
        for (int i = 0; i < pa->max_lenght; i++)
            pa->lab_impefect[j][i] = 'X';
    for (int i = 0; i < pa->max_lenght; i++)
        pa->lab_impefect[0][i] = '*';
    for (int j = 0; j < pa->max_height; j++)
        pa->lab_impefect[j][0] = '*';
    pa->lab_impefect[pa->max_height - 1][pa->max_lenght - 1] = '*';
    for (int i = 2; i < pa->max_height; i += 2)
        create_imperfect_lab2(pa, i, random);
    create_impefect_lab3(pa, random);
    return;
}