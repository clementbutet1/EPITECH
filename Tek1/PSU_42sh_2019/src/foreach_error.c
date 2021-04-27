/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** foreach_error
*/

#include "mysh.h"

int check_par(char **str)
{
    int o = 0;
    int c = 0;

    for (int i = 0; str[i] != NULL; i++) {
        for (int j = 0; str[i][j] != '\0'; j++) {
            if (str[i][j] == '(')
                o++;
            else if (str[i][j] == ')')
                c++;
        }
    }
    if (o > c) {
        my_putstr("Too many ('s.\n");
        return (-1);
    } else if (o < c) {
        my_putstr("Too many )'s.\n");
        return (-1);
    } else
        return 0;
}

int err_handling_foreach(char **str)
{
    int i = 0;

    for (i = 0; str[i] != NULL; i++);
    if (i >= 3) {
        if (str[2][0] != '(') {
            if (i == 3)
                my_putstr("foreach: Too few arguments.\n");
            else
                my_putstr("foreach: Words not parenthesized.\n");
            return (-1);
        }
        if (check_par(str) < 0)
            return -1;
    }
    else {
        my_putstr("foreach: Too few arguments.\n");
        return -1;
    }
    return 0;

}

int check_foreach(char **str, sh_t *sh)
{
    if (my_strcmp(str[0], "foreach") == 0) {
        if (err_handling_foreach(str) == 0)
            foreach(sh, str);
        return 1;
    }
    else
        return 0;
}