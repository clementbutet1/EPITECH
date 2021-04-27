/*
** EPITECH PROJECT, 2019
** prepare_map.c
** File description:
** prepare_map.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include "include/bsq.h"

void printmap(sizemap_t *size)
{
    int k = 0;

    for (int i = 0; i < size->bsq; i++) {
        for (int y = 0; y < size->bsq; y++)
            size->map[size->line + i][size->col + y] = 'x';
    }
    while (k < size->max_lenght) {
        write(1, size->map[k], size->max_lenght);
        my_putchar('\n');
        k++;
    }
}

void allocmap2(sizemap_t *size)
{
    int i = 0;
    int c = 0;
    int k = 0;

    while (size->str[k] != '\n') {
        k++;
    }
    k++;
    while (i < size->max_height) {
        size->map[i] = malloc(sizeof(int *) * size->max_height);
        c = 0;
        while (c < size->max_lenght) {
            size->map[i][c] = size->str[k];
            c++;
            k++;
        }
        i++;
        k++;
    }
}

int preparealloc(sizemap_t *size)
{
    int i = 0;
    int c = 0;
    size->max_height = count_column(size->str);
    size->max_lenght = count_line(size->str);
    size->map = malloc(sizeof(int *) * size->max_lenght);
    allocmap2(size);
}

int fs_open_file(char const *filename, sizemap_t *size)
{
    struct stat g;
    stat(filename, &g);
    int fd;
    fd = open(filename, O_RDONLY);
    char *buffer = malloc(g.st_size + 1);
    error(fd, buffer);
    read(fd, buffer, g.st_size);
    buffer[g.st_size] = '\0';
    size->str = buffer;
    preparealloc(size);
    close(fd);
}