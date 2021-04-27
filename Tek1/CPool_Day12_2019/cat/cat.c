/*
** EPITECH PROJECT, 2019
** cat.c
** File description:
** cat
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int filecat(int fd)
{
    char buf[20000];
    int size = read(fd, buf, 20000);

    while (size > 0) {
        write(1, buf, size);
        size = read(fd, buf, 20000);
    }
    return (0);
}

int main(int ac, char **av)
{
    int fd;
    char buffer[20000];
    int size;

    if (ac == 1)
        return (filecat(1));

    if (fd == -1) {
        my_putstr("Error with opn/n");
        return (1);
    }
    for (int i = 0; i < ac - 1; i++) {
        int fd = open(av[i + 1], O_RDONLY|O_CREAT, S_IRWXU);
        filecat(fd);
    }
    close(fd);
    return (0);
}
