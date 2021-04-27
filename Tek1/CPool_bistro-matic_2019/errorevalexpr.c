/*
** EPITECH PROJECT, 2019
** errorevalexpr.c
** File description:
** errorevalexpr
*/

#include "my.h"
#include <stdlib.h>

int invalide_size2(char *str, int i)
{
    if (str[i] < 48 || str[i] > 57) {
        if (str[i] != '%' || str[i] != '+' || str[i] != '-' ||
        str[i] != '/' || str[i] != '*' || str[i] != '(' ||
        str[i] != ')') {
        }
        return (0);
    } else
        return (1);
}

int invalid_size(char *str)
{
    int i = 0;
    int tmp = 0;

    while (str[i] != '\0') {
        tmp = invalide_size2(str, i);
        if (tmp == 1)
            return (84);
        else {
            my_putstr("ERROR");
            return (0);
        }
        i++;
    }
//    fcterror(str);
}

////int fcterror(char *str)
//{
//    int i = 0;
//    int b = 0;
//
//    while (str[i] != '\0') {
//        if (str[i] == '(') {
//            b++;
//        }
//        if (str[i] ==')') {
//            b--;
//        }
//        i++;
//    }
//    if (b == 0) {
//        return (b);
//    } else
//        my_putstr("ERROR");
//    return (0);
//}

int errorevalexpr(char *str)
{
    int i = 0;

    str = invalid_size(str);
    i++;
    return (0);
}
