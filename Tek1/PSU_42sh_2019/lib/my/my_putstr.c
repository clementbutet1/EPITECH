/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = my_strlen(str);

    write(1, str, i);
    return (0);
}
