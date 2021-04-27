/*
** EPITECH PROJECT, 2019
** getnextline.c
** File description:
** getnextline.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int condition(int rd, char *buffer, char *save, char *crt)
{
    if (buffer == NULL || rd == -1)
        return (1);
    else if (save[0] == '\0') {
        *crt = save[0];
        save++;
        rd--;
        return (1);
    }
    return (0);
}

void copycrt(int fd, char *crt)
{
    static char *save = NULL;
    static int rd = 0;
    char *buffer = malloc(sizeof(char *) * (READ_SIZE + 1));

    while (rd == 0) {
        rd = read(fd, buffer, READ_SIZE);
        buffer[rd] = 0;
        save = buffer;
        if (condition(rd, save, buffer, crt) == 1)
            return;
    }
    *crt = save[0];
    save++;
    rd--;
}

char *read_and_copy(int fd, char *rsltf)
{
    char crt = 0;
    int i = 0;

    copycrt(fd, &crt);
    if (crt == '\0')
        return (NULL);
    while (crt != '\0' && crt != '\n') {
        rsltf[i] = crt;
        copycrt(fd, &crt);
        i++;
    }
    rsltf[i] = '\0';
    return (rsltf);
}

char *get_next_line(int fd)
{
    char *rsltf = malloc(sizeof(char *) * (READ_SIZE + 1));
    int i = 0;

    if (fd == -1)
        exit_error;
    if (fd < 0 || fd > 256) {
        return (NULL);
    }
    else if (READ_SIZE <= 0 || rsltf == NULL)
        return (NULL);
    rsltf = read_and_copy(fd, rsltf);
    return (rsltf);
}