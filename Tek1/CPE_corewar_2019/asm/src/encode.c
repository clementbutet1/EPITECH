/*
** EPITECH PROJECT, 2019
** encode.c
** File description:
** encode.c
*/

#include "asm.h"

int *encode(char *str, int size)
{
    int *nb = malloc(sizeof(int) * (size + 1));
    int i = 0;

    while (str[i] != '\0') {
        nb[i] = str[i];
        i++;
    }
    while (i < size) {
        nb[i] = 0;
        i++;
    }
    nb[size] = -1;
    return (nb);
}

void encode_name_coment(params_t *params, core_t *core)
{
    core->name = encode(params->name, PROG_NAME_LENGTH + 4);
    core->comment = encode(params->comment, COMMENT_LENGTH + 4);
}