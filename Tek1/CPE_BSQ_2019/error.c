/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>

int error(int fd, char *buffer)
{
    int i = 0;

    if (fd == -1) {
        return (84);
    }
    if (buffer == NULL) {
        return (84);
    }
}
