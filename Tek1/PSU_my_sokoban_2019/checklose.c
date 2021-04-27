/*
** EPITECH PROJECT, 2019
** checklose.c
** File description:
** checklose.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "include/sokoban.h"
#include <ncurses.h>

int checklose3(sizemap_t *size, lose_t *lose)
{
    if (lose->cptl == lose->nbx) {
        clear();
        printmap(size);
        refresh();
        endwin();
        exit(1);
    } else
        return (lose->cptl);
}

int checklose2(sizemap_t *size, lose_t *lose)
{
    if (size->map[lose->lx][lose->ly] == 'X'
        && size->map[lose->lx - 1][lose->ly] == '#'
        && size->map[lose->lx][lose->ly - 1] == '#')
        lose->cptl++;
    if (size->map[lose->lx][lose->ly] == 'X'
        && size->map[lose->lx + 1][lose->ly] == '#'
        && size->map[lose->lx][lose->ly - 1] == '#')
        lose->cptl++;
    return (lose->cptl);
}

int checklose1(sizemap_t *size, lose_t *lose)
{
    if (size->map[lose->lx][lose->ly] == 'X'
        && size->map[lose->lx - 1][lose->ly] == '#'
        && size->savmap[lose->lx][lose->ly + 1] == '#')
        lose->cptl++;
    if (size->map[lose->lx][lose->ly] == 'X'
        && size->map[lose->lx + 1][lose->ly] == '#'
        && size->map[lose->lx][lose->ly + 1] == '#')
        lose->cptl++;
    lose->cptl = checklose2(size, lose);
    checklose3(size, lose);
    return (lose->cptl);
}

void checklose(sizemap_t *size, lose_t *lose)
{
    int count = 0;
    lose->lx = 0;
    lose->ly = 0;
    lose->cptl = 0;
    size->max_lenght = 0;
    lose->cptl = 0;

    while (lose->lx < size->max_height) {
        size->max_lenght = count_column(size->str, count);
        count += 1;
        for (lose->ly = 0; lose->ly < size->max_lenght;) {
            lose->cptl = checklose1(size, lose);
            lose->ly++;
        }
        lose->ly = 0;
        lose->lx++;
    }
}

