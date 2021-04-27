/*
** EPITECH PROJECT, 2019
** put_tab_buffer.c
** File description:
** put_tab_buffer.c
*/

#include <stdio.h>
#include <stdlib.h>

char *put_tab_buffer(char **tab)
{
    int size = 0;
    char *buffer = NULL;

    for (int i = 0; tab[i] != NULL; i++, size++)
        for (int j = 0; tab[i][j] != '\0'; j++)
            size++;
    size++;
    buffer = malloc(sizeof(char) * (size));
    size = 0;
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++, size++)
            buffer[size] = tab[i][j];
        buffer[size] = ' ';
        size++;
    }
    buffer[size] = '\0';
    return (buffer);
}