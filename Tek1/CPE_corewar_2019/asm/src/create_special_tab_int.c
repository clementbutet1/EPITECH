/*
** EPITECH PROJECT, 2019
** asm
** File description:
** create_special_tab_int.c
*/

#include "asm.h"

char *my_converthexadecimalmi_tab(int magic_nb, char *rslt, int i)
{
    int new_nb[16] = {0};
    char *list = "0123456789ABCDEF";
    int res = magic_nb;

    for (; res != 0; i++)
        res = (res - (new_nb[i] = res % 16)) / 16;
    rslt = malloc(sizeof(char) * (i + 1));
    if (i % 2 != 0) {
        rslt[0] = '0';
        for (int k = 1; k <= i; i++)
            rslt[k] = list[new_nb[(i - 1) - k]];
        rslt[i] = '\0';
        return (rslt);
    }
    for (int j = 1; j <= i; j++)
        rslt[j - 1] = list[new_nb[i - j]];
    rslt[i] = '\0';
    return (rslt);
}

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

int *base_hexadecima_to_int_tab(char *str, int k, int *rslt)
{
    int pow = 1;
    int result = 0;
    int val = 0;
    char c;
    int i = 0;

    for (; str[i] != '\0'; i++);
    i--;
    for (; i >= 0; i--) {
        c = str[i];
        ((c >= '0' && c <= '9') ? (val = c - 48) : (val = c - 55));
        rslt[k] = result += val * pow;
        pow *= 16;
    }
    return (rslt);
}

int *put_in_good_tab(int *tab, int size)
{
    int nb = 0;
    size--;

    for (int i = 0; i < size; i++, size--) {
        nb = tab[i];
        tab[i] = tab[size];
        tab[size] = nb;
    }
    return (tab);
}

int *create_magic_tab(char *nb, int size)
{
    int cpt = 0;
    char *magic_nb = my_revstr(my_converthexadecimalmi_tab_spe(my_getnbr(nb),
    special_strlen(my_getnbr(nb))));
    int *rslt = malloc(sizeof(int) * (size + 1));
    char *new_nb = NULL;

    for (int i = 0; i < size; i++)
        rslt[i] = 0;
    rslt[size] = -1;
    for (int i = 0; magic_nb[i] != '\0'; i++) {
        new_nb = malloc(sizeof(char) * 3);
        if (i % 2 == 0) {
            new_nb = separe_magic_nb(new_nb, magic_nb, i);
            rslt = base_hexadecima_to_int_tab(my_revstr(new_nb), cpt, rslt);
            cpt++;
        }
        free(new_nb);
    }
    free(magic_nb);
    rslt = put_in_good_tab(rslt, size);
    return (rslt);
}