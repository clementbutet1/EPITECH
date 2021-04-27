/*
** EPITECH PROJECT, 2019
** error_label.c
** File description:
** error_label.c
*/

#include "asm.h"

int error_label2(char *str, int i, char *label_c)
{
    for (int d = 0; str[i] != '\n' &&
    str[i] != '\0' && str[i] != ','; i++) {
        for (int a = 0; label_c[a] != '\0' && d == 0; a++)
            if (str[i] == label_c[a])
                d = 1;
        if (d == 0)
            my_putstr_error("Error : set problem");
        d = 0;
    }
    return (0);
}

int error_label(char *str, int i, char *label_c)
{
    int d = 0;
    int g = 0;

    for (int a = 0; label_c[a] != '\0' && d == 0; a++) {
        if (str[i - 1] == label_c[a] && str[i - 1] != '%')
            d = 1;
        if (str[i + 1] == label_c[a])
            g = 1;
    }
    if (d == 0 && g == 0 && (str[i + 1] == ' ' || str[i + 1] == '\0' ||
        str[i + 1] == '\n') && str[i - 1] != ' ')
        my_putstr_error("Error : Invalid label");
    if ((d == 1 && g == 1) || (d == 0 && g == 0))
        my_putstr_error("Error : Offset problem");
    if (g == 1 && d == 0)
        error_label2(str, i + 1, label_c);
    return (0);
}