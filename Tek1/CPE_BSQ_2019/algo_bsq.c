/*
** EPITECH PROJECT, 2019
** algo_bsq.c
** File description:
** algo_bsq.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include "include/bsq.h"

void initvalues(sizemap_t *size)
{
    size->bsq = 0;
    size->col = 0;
    size->line = 0;
    size->size = 1;
    size->pos_x = 0;
}

int bsq3(sizemap_t *size)
{
    char *line;

    for (int i = 0; i < size->size; i++) {
        if (size->pos_x + i >= size->max_height)
            return (0);
        for (int k = 0; k < size->size; k++) {
            line = size->map[size->pos_x + i];
            if (line[size->pos_y + k] != '.')
                return (0);
        }
    }
    return (1);
}

void bsq2(sizemap_t *size)
{
    while (bsq3(size) == 1)
        size->size++;
    size->size--;
    if (size->size > size->bsq) {
        size->bsq = size->size;
        size->col = size->pos_y;
        size->line = size->pos_x;
    }
}

void bsq(sizemap_t *size)
{
    initvalues(size);

    while (size->pos_x < size->max_height) {
        for (size->pos_y = 0; size->pos_y < size->max_lenght; size->pos_y++) {
            bsq2(size);
        }
        size->pos_x++;
    }
}
