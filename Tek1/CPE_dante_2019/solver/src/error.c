/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "my.h"
#include "solver.h"

int error(int fd, char *buffer)
{
    int i = 0;

    if (fd == -1)
        return (84);
    if (buffer == NULL)
        return (84);
}

int check_nb_cara(char *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    return (i);
}

void check_error(params_t *params)
{
    int size = 0;

    for (int i = 0; params->map[i] != NULL; i++) {
        size = check_nb_cara(params->map[i]);
        for (int j = 0; params->map[i][j] != '\0'; j++) {
            if (!(params->map[i][j] == 'X' || params->map[i][j] == '*' ||
                params->map[i][j] == '\n' || params->map[i][j] == '\0'))
                exit (84);
            if (size != params->max_lenght)
                exit (84);
        }
    }
}