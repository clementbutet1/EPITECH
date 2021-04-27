/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** flags.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "include/103cipher.h"

void encrypted_flag(char *key, base_t *base, char *mess)
{
    int i = determine(key);

    if (i == 1)
        one_one();
    if (i == 2)
        two_two();
    if (i == 3)
        three_three();
    if (i == 4)
        four_four();
}

void decrypted_flag(char *key, base_t *base, char *mess)
{
    int i = determine(key);

    if (i == 1)
        one_one();
    if (i == 2)
        two_two();
    if (i == 3)
        three_three();
    if (i == 4)
        four_four();
}