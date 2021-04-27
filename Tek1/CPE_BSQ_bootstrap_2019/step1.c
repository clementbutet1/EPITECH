/*
** EPITECH PROJECT, 2019
** step1.c
** File description:
** step1.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
}

int fs_open_file(char const *filepath)
{
    int fd;
    char buffer[20000];
    int size;

    if (fd == 1)
        return (0);

    if (fd == -1) {
        my_putstr("FAILURE\n");
        return (1);
    }
    fd = open(filepath, O_RDONLY);
    while (size = read(fd, buffer, 20000) > 0 ) {
        my_putstr("SUCCESS\n");
    }
    close(fd);
    return (0);
}
