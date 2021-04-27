/*
** EPITECH PROJECT, 2019
** calculope.c
** File description:
** calculope.c
*/

#include "my.h"
#include <stdlib.h>

int calculope(int a, int b, char operator)
{
    if (operator == 43) {
        return (a + b);
    }
    if (operator == 45) {
        return (a - b);
    }
    if (operator == 42) {
        return (a * b);
    }
    if (operator == 47) {
        return (a / b);
    }
    if (operator == 37) {
        return (a % b);
    }
    else
        return (0);
}
