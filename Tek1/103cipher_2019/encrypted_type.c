/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** encrypted_type.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "include/103cipher.h"

void encrypted_1_by_1(base_t *base)
{
    int i = 0;

    while (i < base->lenght) {
        base->res[i].x = base->mess[i].x * base->key[0].x;
        i++;
    }
}

void encrypted_3_by_3(base_t *base)
{
    int i = 0;
    int j = 0;

    while (i < base->lenght) {
        base->res[j].x = base->mess[i].x * base->key[0].x + base->mess[i + 1].x
        * base->key[3].x + base->mess[i + 2].x * base->key[6].x;
        j++;
        base->res[j].x = base->mess[i].x * base->key[1].x + base->mess[i + 1].x
        * base->key[4].x + base->mess[i + 2].x * base->key[7].x;
        j++;
        base->res[j].x = base->mess[i].x * base->key[2].x + base->mess[i + 1].x
        * base->key[5].x + base->mess[i + 2].x * base->key[8].x;
        i = i + 3;
        j++;
    }
}

void encrypted_2_by_2(base_t *base)
{
    int i = 0;
    int j = 0;

    while (i < base->lenght) {
        base->res[j].x = base->mess[i].x * base->key[0].x + base->mess[i + 1].x
        * base->key[2].x;
        j++;
        base->res[j].x = base->mess[i].x * base->key[1].x + base->mess[i + 1].x
        * base->key[3].x;
        i = i + 2;
        j++;
    }
}

void encrypted_4_by_4(base_t *base)
{
    int i = 0;
    int j = 0;

    while (i < base->lenght) {
        base->res[j].x = base->mess[i].x * base->key[0].x + base->mess[i + 1].x
        *base->key[4].x + base->mess[i + 2].x * base->key[8].x +
        base->mess[i + 3].x *base->key[12].x;
        j++;
        base->res[j].x = base->mess[i].x * base->key[1].x + base->mess[i + 1].x
        * base->key[5].x + base->mess[i + 2].x * base->key[9].x +
        base->mess[i + 3].x *base->key[13].x;
        j++;
        base->res[j].x = base->mess[i].x * base->key[2].x + base->mess[i + 1].x
        * base->key[6].x + base->mess[i + 2].x * base->key[10].x +
        base->mess[i + 3].x *base->key[14].x;
        j++;
        base->res[j].x = base->mess[i].x * base->key[3].x + base->mess[i + 1].x
        * base->key[7].x + base->mess[i + 2].x * base->key[11].x +
        base->mess[i + 3].x *base->key[15].x;
        i = i + 4;
        j++;
    }
}