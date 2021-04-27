/*
** EPITECH PROJECT, 2019
** my_params_to_list.c
** File description:
** my_params_to_list
*/

#include <stdlib.h>
#include "./include/mylist.h"
#include "./lib/my/my.h"

linked_list_t *add_to_list(void *data, linked_list_t **list)
{
    linked_list_t *element;

    element = malloc(sizeof(linked_list_t));
    element->data = data;
    element->next = *list;
    *list = element;
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list;
    int i = 0;

    list = NULL;
    while (i < ac) {
        add_to_list(av[i], &list);
        i++;
    }
    return (list);
}
