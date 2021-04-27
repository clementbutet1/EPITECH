/*
** EPITECH PROJECT, 2019
** error2.c
** File description:
** error2.c
*/

#include "my.h"
#include "../include/navy.h"

int check_pos_boat(params_t *params)
{
    return (0);
}

int check_enter(char *cmd)
{
    if (cmd == NULL)
        return (84);
    if (cmd[2] < 'A' || cmd[2] > 'H' || cmd[3] < '1' || cmd[3] > '8' ||
        cmd[5] < 'A' || cmd[5] > 'H' || cmd[6] < '1' || cmd[6] > '8' ||
        cmd[0] < '0' || cmd[0] > '5')
        return (84);
    return (0);
}

int check_cmd(char *cmd)
{
    int size = my_strlen(cmd);

    if (cmd == NULL || size != 2) {
        my_putstr("wrong position");
        return (84);
    }
    if (cmd[0] < 'A' || cmd[0] > 'H' || cmd[1] < '1' || cmd[1] > '8') {
        my_putstr("wrong position");
        return (84);
    }
    return (0);
}

