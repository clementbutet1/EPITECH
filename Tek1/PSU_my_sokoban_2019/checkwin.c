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

int checkwin2(sizemap_t *size, lose_t *lose)
{
    if (lose->cpt == lose->nbo) {
        clear();
        printmap(size);
        refresh();
        endwin();
        exit(0);
    } else
        return (lose->cpt);
}

int checkwin1(sizemap_t *size, lose_t *lose)
{
    if (size->map[lose->x][lose->y] == 'X'
        && size->savmap[lose->x][lose->y] == 'O')
        lose->cpt++;
    checkwin2(size, lose);
    return (lose->cpt);
}

void checkwin(sizemap_t *size, lose_t *lose)
{
    int count = 0;
    lose->x = 0;
    lose->y = 0;
    lose->cpt = 0;
    size->max_lenght = 0;

    while (lose->x < size->max_height) {
        size->max_lenght = count_column(size->str, count);
        count += 1;
        for (lose->y = 0; lose->y < size->max_lenght;) {
            lose->cpt = checkwin1(size, lose);
            lose->y++;
        }
        lose->y = 0;
        lose->x++;
    }
}