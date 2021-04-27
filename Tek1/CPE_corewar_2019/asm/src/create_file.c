/*
** EPITECH PROJECT, 2019
** create_file.c
** File description:
** create_file.c
*/

#include "asm.h"

void write_core(int *tab, int fd, int type)
{
    if (type == 1)
        for (int i = 0; tab[i] != -1; i++)
            write(fd, &tab[i], 1);
    if (type == 2)
        write(fd, tab, 1);
    return;
}

int create_file(char *name)
{
    int fd = 0;
    char *new_name = NULL;
    int i = 0;

    for (; name[i] != '\0'; i++);
    for (; name[i] != '.'; i--);
    name[i] = '\0';
    new_name = my_strcat(name, ".cor");
    if ((fd = open(new_name, O_CREAT | O_APPEND | O_TRUNC |
        O_RDWR, 0666)) == -1)
        my_putstr_error("Error : Can't create the file .cor");
    free(new_name);
    return (fd);
}