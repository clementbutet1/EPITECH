/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** decrypted_type.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "include/103cipher.h"

void decrypted(base_t *base)
{
    switch (base->matrix_type) {
    case 4:
        decrypted2_by_2(base);
        break;
    case 9:
        decrypted3_by_3(base);
        break;
    }
}

void decrypted2_by_2(base_t *base)
{
    int i = 0;
    int j = 0;

    while (i < base->lenght) {
        base->res[j].c = base->mess[i].x * base->key[0].x + base->mess[i + 1].x
        * base->key[2].x;
        j++;
        base->res[j].c = base->mess[i].x * base->key[1].x + base->mess[i + 1].x
        * base->key[3].x;
        i = i + 2;
        j++;
    }
}

void decrypted3_by_3(base_t *base)
{
    int i = 0;
    int j = 0;

    while (i < base->lenght) {
        base->res[j].c = base->mess[i].x * base->key[0].x + base->mess[i + 1].x
        * base->key[3].x + base->mess[i + 2].x * base->key[6].x;
        j++;
        base->res[j].c = base->mess[i].x * base->key[1].x + base->mess[i + 1].x
        * base->key[4].x + base->mess[i + 2].x * base->key[7].x;
        j++;
        base->res[j].c = base->mess[i].x * base->key[2].x + base->mess[i + 1].x
        * base->key[5].x + base->mess[i + 2].x * base->key[8].x;
        i = i + 3;
        j++;
    }
}