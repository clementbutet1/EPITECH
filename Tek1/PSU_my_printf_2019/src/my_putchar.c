/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** my_putchar
*/

#include "../include/my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
