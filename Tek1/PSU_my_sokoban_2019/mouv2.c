/*
** EPITECH PROJECT, 2019
** mouv2.c
** File description:
** mouv2.c
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

void moveright2(sizemap_t *size, lose_t *lose)
{
    if (size->map[size->savposp_x][size->savposp_y + 1] == 'X'
    && size->map[size->savposp_x][size->savposp_y + 2] != '#'
    && size->map[size->savposp_x][size->savposp_y + 2] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_y++;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        size->map[size->savposp_x][size->savposp_y + 1] = 'X';
        if (size->map[size->savposp_x][size->savposp_y - 1] == ' '
        && size->savmap[size->savposp_x][size->savposp_y - 1] == 'O') {
            size->map[size->savposp_x][size->savposp_y - 1] = 'O';
        }
    }
}

void moveleft2(sizemap_t *size, lose_t *lose)
{
    if (size->map[size->savposp_x][size->savposp_y - 1] == 'X'
    && size->map[size->savposp_x][size->savposp_y - 2] != '#'
    && size->map[size->savposp_x][size->savposp_y - 2] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_y--;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        size->map[size->savposp_x][size->savposp_y - 1] = 'X';
        if (size->map[size->savposp_x][size->savposp_y + 1] == ' '
        && size->savmap[size->savposp_x][size->savposp_y + 1] == 'O') {
            size->map[size->savposp_x][size->savposp_y + 1] = 'O';
        }
    }
}

void moveup2(sizemap_t *size, lose_t *lose)
{
    if (size->map[size->savposp_x - 1][size->savposp_y] == 'X'
    && size->map[size->savposp_x - 2][size->savposp_y] != '#'
    && size->map[size->savposp_x - 2][size->savposp_y] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_x = size->savposp_x - 1;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        size->map[size->savposp_x - 1][size->savposp_y] = 'X';
        if (size->map[size->savposp_x + 1][size->savposp_y] == ' '
        && size->savmap[size->savposp_x + 1][size->savposp_y] == 'O') {
            size->map[size->savposp_x + 1][size->savposp_y] = 'O';
        }
    }
}

void movedown2(sizemap_t *size, lose_t *lose)
{
    if (size->map[size->savposp_x + 1][size->savposp_y] == 'X'
    && size->map[size->savposp_x + 2][size->savposp_y] != '#'
    && size->map[size->savposp_x + 2][size->savposp_y] != 'X') {
        size->map[size->savposp_x][size->savposp_y] = ' ';
        size->savposp_x = size->savposp_x + 1;
        size->map[size->savposp_x][size->savposp_y] = 'P';
        size->map[size->savposp_x + 1][size->savposp_y] = 'X';
        if (size->map[size->savposp_x - 1][size->savposp_y] == ' '
        && size->savmap[size->savposp_x - 1][size->savposp_y] == 'O') {
            size->map[size->savposp_x - 1][size->savposp_y] = 'O';
        }
    }
}