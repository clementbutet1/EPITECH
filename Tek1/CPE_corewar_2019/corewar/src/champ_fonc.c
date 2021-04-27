/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** champ_fonc
*/

#include "corewar.h"

void champ_name(champ_t *champion)
{
    char *name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
    int indice = PROG_NAME_LENGTH + 4;
    int a = 0;

    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        name[i] = '\0';
    for (int i = 4; i < indice; i++) {
        if (champion->header[i] != 0)
            name[a++] = champion->header[i];
    }
    champion->name = name;
}

void champ_size(champ_t *champion)
{
    int indice = PROG_NAME_LENGTH + 8;
    int *prog_size = malloc(sizeof(int) * 5);
    int nb = 0;

    for (int i = 0; i < 4; i++, indice++) {
        prog_size[i] = champion->header[indice];
    }
    prog_size[4] = -1;
    nb = change_magic_tab(prog_size);
    champion->size = nb;
}

void champ_magic_nbr(champ_t *champion)
{
    int *buf = malloc(sizeof(int) * 5);
    int a = 0;

    for (int i = 0; i < 5; i++)
        buf[i] = -1;
    for (int i = 0; i < 4; i++) {
        if (champion->header[i] != 0)
            buf[a++] = champion->header[i];
    }
    check_magic_nb(buf);
}

void champ_comment(champ_t *champion)
{
    char *comment = malloc(sizeof(char) * COMMENT_LENGTH + 1);
    int indice = PROG_NAME_LENGTH + 12 + COMMENT_LENGTH;
    int a = 0;

    for (int i = 0; i < COMMENT_LENGTH; i++)
        comment[i] = '\0';
    for (int i = PROG_NAME_LENGTH + 8; i < indice; i++) {
        if (champion->header[i] != 0)
            comment[a++] = champion->header[i];
    }
    champion->comment = comment;
}