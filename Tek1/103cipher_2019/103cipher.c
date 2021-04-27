/*
** EPITECH PROJECT, 2019
** 103cipher.c
** File description:
** 103cipher.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "include/103cipher.h"

void print_decrypted(base_t *base)
{
    printf("Decrypted message:\n");
    for (int i = 0; base->res[i].c <= 126 && base->res[i].c >= 31; i++)
        printf("%c", (int)round(base->res[i].c));
    printf("\n");
}

void print_encrypted(base_t *base)
{
    printf("Encrypted message:\n");
    for (int i = 0; i < base->lenght; i++) {
        printf("%.f", base->res[i].x);
        if (i != base->lenght - 1)
            printf(" ");
    }
    printf("\n");
}

void determine(char *key, base_t *base)
{
    int i = strlen(key);

    if (i == 1)
        base->matrix_type = 1;
    if (i > 1 && i <= 4)
        base->matrix_type = 4;
    if (i > 4 && i <= 9)
        base->matrix_type = 9;
    if (i > 9 && i <= 16)
        base->matrix_type = 16;
}

void which_flag(char *key, base_t *base, int flag, char *mess)
{
    if (flag == 0) {
        encrypted_key(key, base);
        encrypted_mess(mess, base);
        print_encrypted_matrix(base);
        encrypted(base);
        print_encrypted(base);
    }
    if (flag == 1) {
        decrypted_key(key, base);
        print_decrypted_matrix(base);
        decrypted_message(mess, base);
        decrypted(base);
        print_decrypted(base);
    }
}

int main(int ac, char **av)
{
    base_t base;
    int flag;
    char *key;
    char *mess;

    finderror(ac, av);
    flag = atoi(av[3]);
    key = av[2];
    mess = av[1];
    base.key = malloc(sizeof(key_c) * (strlen(key) + 3));
    base.mess = malloc(sizeof(mess_t) * (strlen(mess) + 3));
    base.res = malloc(sizeof(res_t) * (strlen(mess) + 3));
    determine(key, &base);
    which_flag(key, &base, flag, mess);
    return (0);
}
