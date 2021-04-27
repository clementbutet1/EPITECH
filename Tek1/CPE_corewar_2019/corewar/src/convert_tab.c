/*
** EPITECH PROJECT, 2019
** convert_tab.c
** File description:
** convert_tab.c
*/

#include "corewar.h"

char *my_converthexadecimalmi_tab_spe(unsigned int nb, int size)
{
    int rslt;
    char *res = malloc(sizeof(char) * (size + 1));
    int i = 0;
    char *c = "0123456789ABCDEF";

    while (nb > 0) {
        rslt = nb % 16;
        nb = nb / 16;
        res[i] = c[rslt];
        i++;
    }
    res[i] = '\0';
    res = my_revstr(res);
    return (res);
}

int base_hexadecimal_to_int(char *str)
{
    int pow = 1;
    int result = 0;
    int val = 0;
    char c;
    int i = 0;
    int rslt = 0;

    for (; str[i] != '\0'; i++);
    i--;
    for (; i >= 0; i--) {
        c = str[i];
        ((c >= '0' && c <= '9') ? (val = c - 48) : (val = c - 55));
        rslt = result += val * pow;
        pow *= 16;
    }
    return (rslt);
}