/*
** EPITECH PROJECT, 2019
** PSU_navyfab_2019
** File description:
** convert_binary.c
*/

#include <stdio.h>
#include <stdlib.h>

void my_swap2(char *d, char *f)
{
    char c;

    c = *d;
    *d = *f;
    *f = c;
    return;
}

char *my_revstr(char *str)
{
    int d = 0;
    int f = 0;

    while (str[f] != '\0')
        f++;
    f = f - 1;
    while (d <= f) {
        my_swap2(&(str[d]), &(str[f]));
        d = d + 1;
        f = f - 1;
    }
    return (str);
}

char *my_convert_bin(int nb)
{
    int tmp = nb;
    int tmp2;
    int i = 0;
    char *s = 0;

    s = malloc(sizeof(char) * 4);
    for (int x = 0; x < 4; x++)
        s[x] = '0';
    do {
        tmp2 = tmp % 2;
        tmp = tmp / 2;
        s[i] = tmp2 + 48;
        i++;
    } while (tmp >= 2);
    s[i] = tmp + 48;
    my_revstr(s);
    return (s);
}