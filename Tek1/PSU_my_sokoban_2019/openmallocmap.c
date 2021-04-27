/*
** EPITECH PROJECT, 2019
** openmallocmap.c
** File description:
** openmallocmap.c
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

void newmap2(sizemap_t *size, int i, int j)
{
    if (size->savmap[i][j] == 'P')
        size->savmap[i][j] = ' ';
    if (size->savmap[i][j] == 'X')
        size->savmap[i][j] = ' ';
}

void allocnewmap(sizemap_t *size)
{
    int i = 0;
    int c = 0;
    int k = 0;
    int count = 0;

    size->savmap = malloc(sizeof(char *) * (size->max_height + 2));
    for (; i < size->max_height + 1; i++) {
        size->max_lenght = count_column(size->str, count);
        size->savmap[i] = malloc(sizeof(char) * (size->max_lenght + 2));
        count += 1;
        for (c = 0; c < size->max_lenght + 1; c++) {
            size->savmap[i][c] = size->str[k];
            newmap2(size, i, c);
            savepos(size, i, c, k);
            k++;
        }
        size->savmap[i][c] = '\0';
    }
    size->map[i] = NULL;
}

void allocmap(sizemap_t *size)
{
    int i = 0;
    int c = 0;
    int k = 0;
    int count = 0;

    size->map = malloc(sizeof(char *) * (size->max_height + 2));
    for (; i < size->max_height + 1; i++) {
        size->max_lenght = count_column(size->str, count);
        size->map[i] = malloc(sizeof(char) * (size->max_lenght + 2));
        count += 1;
        for (c = 0; c < size->max_lenght + 1; c++) {
            size->map[i][c] = size->str[k];
            k++;
        }
        size->map[i][c] = '\0';
    }
    size->map[i] = NULL;
}

void open_read_file(char const *filename, sizemap_t *size, lose_t *lose)
{
    clear();
    struct stat g;
    stat(filename, &g);
    int fd;
    char *buffer = malloc(sizeof(char) * (g.st_size + 1));

    fd = open(filename, O_RDONLY);
    handleerror(fd, buffer);
    read(fd, buffer, g.st_size);
    buffer[g.st_size] = '\0';
    finderror(buffer, lose);
    size->max_height = count_line(buffer);
    size->str = buffer;
    erase();
    allocmap(size);
    close(fd);
    refresh();
}
