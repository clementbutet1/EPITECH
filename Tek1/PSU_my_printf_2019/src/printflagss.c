/*
** EPITECH PROJECT, 2019
** printflagss.c
** File description:
** printflagss.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

void printflagss2(unsigned char *str, int i)
{
    if (str[i] <= 31 || str[i] >= 127) {
        my_putchar(str[i]);
    }
    if (str[i] >= 0 && str[i] <= 7) {
        my_putchar('\\');
        my_putchar('0');
        my_putchar('0');
        my_convertoctal(str[i]);
    }
    if (str[i] < 32 && str[i] > 7 && str[i] < 64) {
        my_putchar('0');
        my_convertoctal(str[i]);
    } else
        my_putchar(str[i]);
}

void printflagss(unsigned char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        printflagss2(str, i);
        i++;
    }
}
