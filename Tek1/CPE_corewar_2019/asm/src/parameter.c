/*
** EPITECH PROJECT, 2019
** parameter.c
** File description:
** parameter.c
*/

#include "asm.h"

int is_register(char *str, int *i, int cas)
{
    int nb = my_getnbr(&str[*i + 1]);
    int a = *i + 1;

    for (; str[a] != '\n' && str[a] != '\0' &&
    str[a] != SEPARATOR_CHAR; a++) {
        if (str[a] < '0' || str[a] > '9')
            my_putstr_error("Error: ASM - bad arguments register");
    }
    if (nb == 0)
        my_putstr_error("Invalid register number.");
    if (nb < 0 || nb > REG_NUMBER)
        my_putstr_error("Error : Registre Number problem");
    if (cas == 1)
        *i = a;
    if (cas == 1 && (str[a] == '\n' || str[a] == '\0'))
        *i = a - 1;
    if (str[a] == SEPARATOR_CHAR && (str[a + 1] == '\n' || str[a + 1] == '\0'))
        my_putstr_error("Error: ASM - misplaced ','");
    return (1);
}

int is_direct(char *str, int *i, int cas)
{
    int a = *i;

    if (str[*i] != DIRECT_CHAR)
        return (0);
    for (; str[a] != '\n' && str[a] != '\0' &&
    str[a] != SEPARATOR_CHAR; a++);
    if (str[*i + 1] != LABEL_CHAR && (str[*i + 1] != '-' && (str[*i + 1] > '9'
        || str[*i + 1] < '0')))
        return (0);
    if (cas == 1)
        *i = a;
    if (cas == 1 && (str[a] == '\n' || str[a] == '\0'))
        *i = a - 1;
    if (str[a] == SEPARATOR_CHAR && (str[a + 1] == '\n' || str[a + 1] == '\0'))
        my_putstr_error("Error: ASM - misplaced ','");
    return (1);
}

int is_indirect(char *str, int *i, int cas)
{
    int a = *i;

    if (str[*i] != LABEL_CHAR && (str[*i] != '-' && (str[*i] > '9'
        || str[*i] < '0')))
        return (0);
    for (; str[a] != '\n' && str[a] != '\0' &&
    str[a] != SEPARATOR_CHAR; a++);
    if (cas == 1)
        *i = a;
    if (cas == 1 && (str[a] == '\n' || str[a] == '\0'))
        *i = a - 1;
    if (str[a] == SEPARATOR_CHAR && (str[a + 1] == '\n' || str[a + 1] == '\0'))
        my_putstr_error("Error: ASM - misplaced ','");
    return (1);
}