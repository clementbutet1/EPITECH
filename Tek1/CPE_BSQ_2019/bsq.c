/*
** EPITECH PROJECT, 2019
** bsq.c
** File description:
** bsq.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include "include/bsq.h"

void execute(char const *filename, sizemap_t *size)
{
    fs_open_file(filename, size);
    bsq(size);
    printmap(size);
}

int main(int ac, char **av)
{
    sizemap_t size;

    if (ac != 2) {
        my_putstr("./bsq (map)");
        return (84);
    }
    execute(av[1], &size);
    return (0);
}
