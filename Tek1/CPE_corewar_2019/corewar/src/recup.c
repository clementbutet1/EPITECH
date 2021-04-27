/*
** EPITECH PROJECT, 2019
** recup.c
** File description:
** recup.c
*/

#include "corewar.h"

void recup_header(champ_t *champion, int fd)
{
    int size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + 1;
    char buff[size];
    int *header = malloc(sizeof(int) * size);

    buff[0] = 't';
    read(fd, buff, size - 1);
    if (buff[0] == 't')
        my_putstr_error("Error : Invalid .cor file");
    for (int i = 0; i < size - 1; i++)
        if ((int)buff[i] < 0)
            header[i] = 256 + (int)buff[i];
        else
            header[i] = (int)buff[i];
    header[size - 1] = -1;
    champion->header = header;
}

void recup_core(champ_t *champion, int fd)
{
    char *buff = malloc(sizeof(char) * champion->size + 1);
    int *byte_core = malloc(sizeof(int) * (champion->size + 1));
    int read_size = 0;

    read_size = read(fd, buff, champion->size);
    if (read_size != champion->size)
        my_putstr_error("Error : Invalid prog_size");
    for (int i = 0; i < champion->size; i++)
        byte_core[i] = (int)buff[i];
    byte_core[champion->size] = -1;
    free(buff);
    champion->core = byte_core;
}