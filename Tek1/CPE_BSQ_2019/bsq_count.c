/*
** EPITECH PROJECT, 2019
** bsq_count.c
** File description:
** bsq_count.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include "include/bsq.h"

int count_column(char *buffer)
{
    unsigned int cptx = 0;
    unsigned int i = 0;

    while (buffer[i] != '\n') {
        i++;
    }
    i++;
    while (buffer[i] != '\n') {
        i++;
        cptx++;
    }
    return (cptx);
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
    cpty--;
    return (cpty);
}