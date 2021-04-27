/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_putstr_long.c
*/

#include "my.h"
#include <unistd.h>

int my_putstr_long(char const *str, int rows)
{
    write(1, str, rows);
}
