/*
** EPITECH PROJECT, 2019
** resolve.c
** File description:
** resolve.c
*/

#include "my.h"
#include "solver.h"

int check2(params_t *params, int k, int i)
{
    if (i == 2) {
        if (k % (params->max_lenght + 1) != 0)
            return (params->buffer[k - 1] == '*');
        return (0);
    }
    if (i == 3) {
        if (k >= params->max_lenght)
            return (params->buffer[k - params->max_lenght - 1] == '*');
        return (0);
    }
    return (0);
}

int check(params_t *params, int k, int i)
{
    int ret = 0;

    if (i == 0) {
        if ((k + 2) % (params->max_lenght + 1) != 0)
            return (params->buffer[k + 1] == '*');
        return (0);
    }
    if (i == 1) {
        if (k < (params->max_lenght + 1) * (params->max_height - 1))
            return (params->buffer[k + params->max_lenght + 1] == '*');
        return (0);
    }
    ret = check2(params, k, i);
    return (ret);
}

int algo(params_t *pa, int k)
{
    pa->buffer[k] = 'o';
    if (k == pa->size - 1)
        return (1);
    for (int i = 0; i < 4; i++) {
        if (i == 0)
            pa->pos = k + 1;
        if (i == 1)
            pa->pos = k + pa->max_lenght + 1;
        if (i == 2)
            pa-> pos = k - 1;
        if (i == 3)
            pa->pos = k - pa->max_lenght - 1;
        if ((check(pa, k, i) == 1) && algo(pa, pa->pos) == 1)
            return (1);
    }
    pa->buffer[k] = '*';
    return (0);
}