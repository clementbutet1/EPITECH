/*
** EPITECH PROJECT, 2019
** my_rev_list.c
** File description:
** my_rev_list
*/

#include <stdlib.h>
#include "./include/mylist.h"
#include "./lib/my/my.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *element;
    linked_list_t *cpt;
    linked_list_t *nextlist;

    cpt = NULL;
    element = *begin;
    while (element->next) {
        nextlist = element->next;
        element->next = cpt;
        cpt = element;
        element = nextlist;
    }
    element->next = cpt;
    *begin = element;

}

