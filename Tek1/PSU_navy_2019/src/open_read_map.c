/*
** EPITECH PROJECT, 2019
** open_read_map.c
** File description:
** open_read_map.c
*/

#include "my.h"
#include "../include/navy.h"
#include "stdlib.h"

char **open_read(char *filename, params_t *params)
{
    int fd = open(filename, O_RDONLY);
    char *buffer = NULL;
    char **rslt = NULL;
    int i = 0;
    int size = 0;

    if (fd == -1)
        return (NULL);
    rslt = malloc(sizeof(char *) * (5));
    for (;(buffer = get_next_line(fd)); i++) {
        if (buffer == NULL)
            return (NULL);
        size = my_strlen(buffer);
        buffer[size] = '\n';
        buffer[size + 1] = '\0';
        rslt[i] = buffer;
    }
    rslt[i] = NULL;
    close(fd);
    return (rslt);
}