/*
** EPITECH PROJECT, 2019
** mouv.c
** File description:
** mouv.c
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

void moveright(sizemap_t *size, lose_t *lose)
{
    if (size->map[size->savposp_x][size->savposp_y + 1] != '#'
    && size->map[size->savposp_x][size->savposp_y + 1] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_y++;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        if (size->map[size->savposp_x][size->savposp_y - 1] == ' '
            && size->savmap[size->savposp_x][size->savposp_y - 1] == 'O')
            size->map[size->savposp_x][size->savposp_y - 1] = 'O';
            return;
    }
    moveright2(size, lose);
}

void moveleft(sizemap_t *size, lose_t *lose)
{

    if (size->map[size->savposp_x][size->savposp_y - 1] != '#'
    && size->map[size->savposp_x][size->savposp_y - 1] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_y--;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        if (size->map[size->savposp_x][size->savposp_y + 1] == ' '
            && size->savmap[size->savposp_x][size->savposp_y + 1] == 'O')
            size->map[size->savposp_x][size->savposp_y + 1] = 'O';
            return;
    }
    moveleft2(size, lose);
}

void moveup(sizemap_t *size, lose_t *lose)
{
    if (size->map[size->savposp_x - 1][size->savposp_y] != '#'
    && size->map[size->savposp_x - 1][size->savposp_y] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_x = size->savposp_x - 1;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        if (size->map[size->savposp_x + 1][size->savposp_y] == ' '
            && size->savmap[size->savposp_x + 1][size->savposp_y] == 'O')
            size->map[size->savposp_x + 1][size->savposp_y] = 'O';
            return;
    }
    moveup2(size, lose);
}

void movedown(sizemap_t *size, lose_t *lose)
{
    if (size->map[size->savposp_x + 1][size->savposp_y] != '#'
    && size->map[size->savposp_x + 1][size->savposp_y] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_x = size->savposp_x + 1;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        if (size->map[size->savposp_x - 1][size->savposp_y] == ' '
            && size->savmap[size->savposp_x - 1][size->savposp_y] == 'O')
            size->map[size->savposp_x - 1][size->savposp_y] = 'O';
            return;
    }
    movedown2(size, lose);
}
