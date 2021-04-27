/*
** EPITECH PROJECT, 2019
** magic_int.c
** File description:
** magic_int.c
*/

#include "asm.h"

char *my_converthexadecimalmi(int magic_nb, char *rslt, int i)
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

void base_hexadecima_to_int(char *str, int k, params_t *pa)
{
    char c;
    int i = 0;

    for (; str[i] != '\0'; i++);
    i--;
    for (int p = 1, rslt = 0, j = 0; i >= 0; i--) {
        c = str[i];
        if (c >= '0' && c <= '9')
            j = c - 48;
        else
            j = c - 55;
        pa->magic_nb[k] = rslt += j * p;
        p *= 16;
    }
    return;
}

char *separe_magic_nb(char *rslt, char *nb, int i)
{
    int j = 0;

    for (; j != 2; j++) {
        rslt[j] = nb[i];
        i++;
    }
    rslt[j] = '\0';
    return (rslt);
}

void get_magic_int(params_t *pa)
{
    int i = 0;
    char *magic_nb = NULL;
    char *new_nb = NULL;
    int cpt = 0;

    magic_nb = my_converthexadecimalmi(COREWAR_EXEC_MAGIC, magic_nb, i);
    pa->magic_nb = malloc(sizeof(int) * (my_strlen(magic_nb) / 2 + 1));
    for (; magic_nb[i] != '\0'; i++) {
        new_nb = malloc(sizeof(char) * 3);
        if (i % 2 == 0) {
            new_nb = separe_magic_nb(new_nb, magic_nb, i);
            base_hexadecima_to_int(new_nb, cpt, pa);
            cpt++;
        }
        free(new_nb);
    }
    free(magic_nb);
    pa->magic_nb[cpt] = -1;
}