/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** print
*/

#include <unistd.h>

int my_putchar(char x)
{
    write(1, &x, 1);
}
