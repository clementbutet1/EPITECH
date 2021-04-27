/*
** EPITECH PROJECT, 2019
** prepmouv.c
** File description:
** prepmouv.c
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

void savepos(sizemap_t *size, int i, int j, int k)
{
    if (size->str[k] == 'P') {
        size->savposp_x = i;
        size->savposp_y = j;
    }
}

char **mov(sizemap_t *size, lose_t *lose, int ac, char **av)
{
    int ch = getch();

    if (ch == KEY_UP)
        moveup(size, lose);
    if (ch == KEY_DOWN)
        movedown(size, lose);
    if (ch == KEY_LEFT)
        moveleft(size, lose);
    if (ch == KEY_RIGHT)
        moveright(size, lose);
    if (ch == ' ')
        main(ac, av);
    if (ch == 'q') {
        endwin();
        exit(0);
    }
    return (size->map);
}
