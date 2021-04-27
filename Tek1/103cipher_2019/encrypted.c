/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** encrypted.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "include/103cipher.h"

void encrypted_key(char *key, base_t *base)
{
    int i = 0;

    while (key[i] && i < base->matrix_type) {
        base->key[i].x = key[i];
        i++;
    }
    while (i < base->matrix_type) {
        base->key[i].x = 0;
        i++;
    }
}

void encrypted_mess(char *mess, base_t *base)
{
    int i = 0;
    int o = sqrt(base->matrix_type);

    while (mess[i]) {
        base->mess[i].x = mess[i];
        i++;
    }
    base->mess[i].x = mess[i];
    while (i % o != 0) {
        base->mess[i].x = 0;
        i++;
    }
    base->lenght = i;
}

void encrypted(base_t *base)
{
    switch (base->matrix_type) {
    case 1:
        encrypted_1_by_1(base);
        break;
    case 4:
        encrypted_2_by_2(base);
        break;
    case 9:
        encrypted_3_by_3(base);
        break;
    case 16:
        encrypted_4_by_4(base);
        break;
    }
}

void print_encrypted_matrix(base_t *base)
{
    int o = sqrt(base->matrix_type);

    printf("Key matrix:\n");
    for (int i = 0; i < base->matrix_type; i++) {
        printf("%.f", base->key[i].x);
        if (base->matrix_type == 1)
            printf("\n");
        else if (i == 0 || (i + 1) % o != 0)
            printf("\t");
        else
            printf("\n");
    }
    printf("\n");
}
