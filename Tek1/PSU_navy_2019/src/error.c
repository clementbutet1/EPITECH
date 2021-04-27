/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "my.h"
#include "../include/navy.h"

void display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player.\n");
    my_putstr("     navy_positions: file representing the positions of");
    my_putstr(" the ships.\n");
    return;
}

void init_struct_error(error_t *error)
{
    error->a = 0;
    error->b = 0;
    error->c = 0;
    error->d = 0;
}

int good_line(char *line)
{
    if (my_strlen(line) != 8 || line[1] != ':' || line[4] != ':')
        return (84);
    if (line[0] > '5' || line[0] < '2')
        return (84);
    if (line[3] > '8' || line[3] < '1' || line[6] > '8' || line[6] < '1')
        return (84);
    if (line[2] > 'H' || line[2] < 'A' || line[5] > 'H' || line[5] < 'A')
        return (84);
    if ((line[2] != line[5]) && (line[3] != line[6]))
        return (84);
    if ((line[2] == line[5]) && (((line[6] - line[3]) + 1) != (line[0] - 48)))
        return (84);
    if ((line[3] == line[6]) && (((line[5] - line[2]) + 1) != (line[0] - 48)))
        return (84);
    return (0);
}

int check_error_on_line(char **pos, params_t *params)
{
    for (int i = 0, j = 2; pos[i] != NULL; i++, j++) {
        if (check_entry_player_size_boat(pos) == 84)
            return (84);
        if (good_line(pos[i]) == 84)
            return (84);
        if (pos[i][2] > pos[i][5])
            return (84);
        if (pos[i][3] > pos[i][6])
            return (84);
        if ((pos[i][0] - 48) != j)
            return (84);
        if (pos[0][0] + pos[1][0] + pos[2][0] + pos[3][0] != 206)
            return (84);
        if (check_same_pos_for_boat(pos, params) == 84)
            return (84);
    }
    return (0);
}

int check_entry_player_size_boat(char **pos)
{
    int cpt = 0;
    int i = 0;

    for (; pos[i] != NULL; i++) {
        if (check_enter(pos[i]) == 84)
            return (84);
        (pos[i][0] == '2') ? cpt += 2 : 0;
        (pos[i][0] == '3') ? cpt += 3 : 0;
        (pos[i][0] == '4') ? cpt += 4 : 0;
        (pos[i][0] == '5') ? cpt += 5 : 0;
    }
    if (cpt == 14 && i == 4)
        return (0);
    else
        return (84);
}