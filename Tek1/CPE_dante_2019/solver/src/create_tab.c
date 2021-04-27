/*
** EPITECH PROJECT, 2019
** create_tab.c
** File description:
** create_tab.c
*/

#include "my.h"
#include "solver.h"

void print_map(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        my_putstr(tab[i]);
}

int count_column(char *buffer)
{
    int cpt = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        cpt++;
    return (cpt);
}

int count_line(char *buffer)
{
    int cpt = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            cpt++;
    return (cpt + 1);
}

void create_tab(params_t *params, char *buffer)
{
    int i = 0;
    int c = 0;
    int k = 0;
    params->map = malloc(sizeof(char *) * (params->max_height + 2));

    for (; i < params->max_height; i++) {
        params->map[i] = malloc(sizeof(char) * (params->max_lenght + 2));
        for (c = 0; c <= params->max_lenght; c++, k++) {
            params->map[i][c] = buffer[k];
        }
        params->map[i][c] = '\0';
    }
    params->map[i] = NULL;
}

void fs_open_file(char const *filename, params_t *params)
{
    int i = 0;
    int c = 0;
    struct stat g;
    int fd = open(filename, O_RDONLY);

    stat(filename, &g);
    params->buffer = malloc(g.st_size + 1);
    error(fd, params->buffer);
    read(fd, params->buffer, g.st_size);
    params->size = g.st_size;
    params->buffer[g.st_size] = '\0';
    params->max_lenght = count_column(params->buffer);
    params->max_height = count_line(params->buffer);
    create_tab(params, params->buffer);
    close(fd);
}