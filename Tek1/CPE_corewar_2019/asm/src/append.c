/*
** EPITECH PROJECT, 2019
** append.c
** File description:
** append.c
*/

#include "asm.h"

void append_l(instu_core_t **D, instu_core_t *new)
{
    instu_core_t *tmp = *D;

    new->next = NULL;
    if (tmp == NULL)
        *D = new;
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}