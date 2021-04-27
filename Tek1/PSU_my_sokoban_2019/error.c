/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
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

int finderror2(char *buffer)
{
    int cpt1 = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'P')
            cpt1++;
    }
    if (cpt1 != 1)
        exit(84);
    else
        return (0);
}

int finderror(char *buffer, lose_t *lose)
{
    lose->nbx = 0;
    lose ->nbo = 0;

    finderror2(buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'X')
            lose->nbx++;
        if (buffer[i] == 'O')
            lose->nbo++;
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0'
            && buffer[i] != '#' && buffer[i] != 'X'
            && buffer[i] != 'O' && buffer[i] != 'P')
            exit(84);
    }
    if (lose->nbx != lose->nbo || lose->nbo == 0)
        exit(84);
    else
        return (0);
}

int handleerror(int fd, char *buffer)
{
    int i = 0;

    if (fd == -1) {
        my_putstr("Don't find the file");
        exit(84);
    }
    if (buffer == NULL) {
        my_putstr("Incorrect file");
        exit(84);
    }
}

void displayerror(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls, \n");
    my_putstr("          ‘P’ for the player, ‘X’ for boxes and ");
    my_putstr("‘O’ for storage locations.\n");
}

void checkerror(int ac, char **av)
{
    int i = 0;
    if (ac != 2) {
        displayerror();
        exit(84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        displayerror();
        exit(84);
    }
}