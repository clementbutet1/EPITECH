/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** decrypted.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "include/103cipher.h"

void decrypted_key(char *key, base_t *base)
{
    switch (base->matrix_type) {
    case 4:
        decryptedkey2_by_2(key, base);
        break;
    case 9:
        decrypted_key3_by_3(key, base);
        break;
    }
}

void decryptedkey22_by_2(base_t *base)
{
    int a = (base->mess[0].x * base->mess[3].x) - (base->mess[1].x *
    base->mess[2].x);

    base->key[0].x = base->mess[3].x / a;
    base->key[1].x = -base->mess[1].x / a;
    base->key[2].x = -base->mess[2].x / a;
    base->key[3].x = base->mess[0].x / a;
}

void decryptedkey2_by_2(char *key, base_t *base)
{
    int i = 0;
    int j = 0;

    while (key[i] && i < base->matrix_type) {
        base->mess[i].x = key[i];
        i++;
    }
    while (i < base->matrix_type) {
        base->mess[i].x = 0;
        i++;
    }
    decryptedkey22_by_2(base);
    while (j < 9) {
        if (base->key[j].x == -0.0000000)
            base->key[j].x = 0.0;
        j++;
    }
}

float det3_by_3(base_t *base)
{
    int key = (base->mess[0].x * base->mess[4].x * base->mess[8].x) +
    (base->mess[1].x * base->mess[5].x * base->mess[6].x) +
    (base->mess[2].x * base->mess[3].x * base->mess[7].x) -
    (base->mess[2].x * base->mess[4].x *  base->mess[6].x) -
    (base->mess[5].x * base->mess[7].x *  base->mess[0].x) -
    (base->mess[8].x * base->mess[1].x *  base->mess[3].x);
    return (key);
}

void decryptedkey23_by_3(char *key, base_t *base)
{
    int a = det3_by_3(base);
    base->key[0].x = ((base->mess[4].x * base->mess[8].x) -
    (base->mess[5].x * base->mess[7].x)) / a;
    base->key[1].x = ((base->mess[2].x * base->mess[7].x) -
    (base->mess[1].x * base->mess[8].x)) / a;
    base->key[2].x = ((base->mess[1].x * base->mess[5].x) -
    (base->mess[2].x * base->mess[4].x)) / a;
    base->key[3].x = ((base->mess[5].x * base->mess[6].x) -
    (base->mess[3].x * base->mess[8].x)) / a;
    base->key[4].x = ((base->mess[0].x * base->mess[8].x) -
    (base->mess[2].x * base->mess[6].x)) / a;
    base->key[5].x = ((base->mess[2].x * base->mess[3].x) -
    (base->mess[0].x * base->mess[5].x)) / a;
    base->key[6].x = ((base->mess[3].x * base->mess[7].x) -
    (base->mess[4].x * base->mess[6].x)) / a;
    base->key[7].x = ((base->mess[1].x * base->mess[6].x) -
    (base->mess[0].x * base->mess[7].x)) / a;
    base->key[8].x = ((base->mess[0].x * base->mess[4].x) -
    (base->mess[1].x * base->mess[3].x)) / a;
}

void decrypted_key3_by_3(char *key, base_t *base)
{
    int i = 0;
    int j = 0;

    while (key[i] && i < base->matrix_type) {
        base->mess[i].x = key[i];
        i++;
    }
    while (i < base->matrix_type) {
        base->mess[i].x = 0;
        i++;
    }
    decryptedkey23_by_3(key, base);
    while (j < 9) {
        if (base->key[j].x == -0.0000000)
            base->key[j].x = 0.0;
        j++;
    }
}

void decrypted_message(char *mess, base_t *base)
{
    int i = 0;
    int j = 0;

    while (mess[i] != '\0') {
        base->mess[j].x = 0;
        while (mess[i] <= '9' && mess[i] >= '0') {
            base->mess[j].x = base->mess[j].x * 10 + (mess[i] - '0');
            i++;
        }
        if (mess[i] == ' ') {
            i++;
            j++;
        }
    }
    i++;
    j++;
    while (mess[i] <= '9' && mess[i] >= '0') {
        base->mess[j].x = base->mess[j].x * 10 + (mess[i] - '0');
        i++;
    }
    base->lenght = j;
}

void print_decrypted_matrix(base_t *base)
{
    int o = sqrt(base->matrix_type);

    printf("Key matrix:\n");
    for (int i = 0; i < base->matrix_type; i++) {
        if (base->key[i].x == 0.0)
            printf("%.1f", base->key[i].x);
        else
            printf("%.3f", base->key[i].x);
        if (i == 0 || (i + 1) % o != 0)
            printf("\t");
        else
            printf("\n");
    }
    printf("\n");
}