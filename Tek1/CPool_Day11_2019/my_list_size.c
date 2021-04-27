/*
** EPITECH PROJECT, 2019
** my_list_size.c
** File description:
** my_list_size
*/

#include <stdlib.h>
#include "mylist.h"
#include "./lib/my/my.h"


int my_list_size(linked_list_t const *begin)
{
    int cpt = 0;

    while (begin != 0) {
        begin = begin->next;
        cpt++;
    }
    return cpt;
}
