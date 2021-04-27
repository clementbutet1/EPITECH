/*
** EPITECH PROJECT, 2019
** van.c
** File description:
** van.c
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

int count_coloumn2(char *buffer, int count, int i, int cpt)
{
    int d = 0;

    while (buffer[i] != '\0' && d != count) {
        if (buffer[i] == '\n') {
            d++;
        }
        i++;
    }
    while (buffer[i] != '\n' && buffer[i] != '\0') {
        i++;
        cpt++;
    }
    return (cpt);
}

int count_column(char *buffer, int count)
{
    unsigned int i = 0;
    int cpt = 0;

    if (count == 0) {
        while (buffer[i] != '\n') {
            i++;
        }
        return (i);
    } else
        cpt = count_coloumn2(buffer, count, i, cpt);
    return (cpt);
}

int count_line(char *buffer)
{
    unsigned int i = 0;
    unsigned int cpty = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            cpty++;
        i++;
    }
    return (cpty);
}
