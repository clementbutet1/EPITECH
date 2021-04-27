/*
** EPITECH PROJECT, 2019
** get_key.c
** File description:
** get_key.c
*/

#include "mysh.h"

int check_match_key(char c[4], char special_keys_code[][4], int i)
{
    for (int j = 0; j < 4; j++)
        if (c[j] != special_keys_code[i][j])
            return (11);
    return (84);
}

char get_arrow_key(void)
{
    char t[3] = {0, 0};
    char c[4] = {0, 0, 0};
    char special_keys_code[][4] = {{27, 91, 65}, {27, 91, 68}, {27, 91, 66},
    {27, 91, 67}, {27, 91, 72}, {27, 91, 70}, {0, 0, 0}};

    read(0, &c, 1);
    if (c[0] != '\e')
        return (c[0] != '\t') ? c[0] : ' ';
    read(0, &t, 2);
    c[1] = t[0];
    c[2] = t[1];
    for (int i = 0; special_keys_code[i][0]; i++) {
        if (check_match_key(c, special_keys_code, i) == 84)
            return ((i + 1) * -1);
    }
    return ('^');
}

int check_cursor(char arrow)
{
    char keys_tab[] = {-1, -2, -3, -4, 1, 5, -5, -6, 0};
    int rslt = 0;
    int i = 0;

    while (keys_tab[i]) {
        if (keys_tab[i] == arrow) {
            rslt = i + 1;
            return (rslt);
        } else
            rslt = 0;
        i++;
    }
    rslt = 0;
    return (rslt);
}