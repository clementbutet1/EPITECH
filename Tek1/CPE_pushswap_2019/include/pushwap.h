/*
** EPITECH PROJECT, 2019
** pushwap.h
** File description:
** pushwap.h
*/

typedef struct list
{
    int ac;
    int flag;
    char **av;
    int nb;
    int *list_a;
    int *list_b;
    struct list *next;
    struct list *previous;
}list_t;
