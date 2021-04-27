/*
** EPITECH PROJECT, 2019
** my_sokoban.c
** File description:
** my_sokoban.c
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

void printmap(sizemap_t *size)
{
    for (int j = 0; size->map[j] != NULL; j++)
        printw(size->map[j]);
}

void my_sokoban(char **av, int ac, sizemap_t *size, lose_t *lose)
{
    size->savposp_x = 0;
    size->savposp_y = 0;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    open_read_file(av[1], size, lose);
    allocnewmap(size);
    while (1) {
        clear();
        printmap(size);
        mov(size, lose, ac, av);
        refresh();
        checkwin(size, lose);
        checklose(size, lose);
    }
    endwin();
}

void main(int ac, char **av)
{
    sizemap_t size;
    lose_t lose;

    checkerror(ac, av);
    my_sokoban(av, ac, &size, &lose);
}