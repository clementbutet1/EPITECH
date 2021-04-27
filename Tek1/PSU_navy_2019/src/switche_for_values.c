/*
** EPITECH PROJECT, 2019
** switche_for_values.c
** File description:
** switche_for_values.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

int check_letter2(params_t *params, int values, char c)
{
    switch (c) {
    case 'D':
        values = 8;
        break;
    case 'E':
        values = 10;
        break;
    case 'F':
        values = 12;
        break;
    case 'G':
        values = 14;
        break;
    case 'H':
        values = 16;
        break;
    }
    return (values);
}

int check_letter(params_t *params, char c)
{
    int values = 0;

    switch (c) {
    case 'A':
        values = 2;
        break;
    case 'B':
        values = 4;
        break;
    case 'C':
        values = 6;
        break;
    }
    values = check_letter2(params, values, c);
    return (values);
}

char check_nb2(params_t *params, char values, int c)
{
    switch (c) {
    case 8:
        values = 'D';
        break;
    case 10:
        values = 'E';
        break;
    case 12:
        values = 'F';
        break;
    case 14:
        values = 'G';
        break;
    case 16:
        values = 'H';
        break;
    }
    return (values);
}

char check_nb(params_t *params, int c)
{
    char values;

    switch (c) {
    case 2:
        values = 'A';
        break;
    case 4:
        values = 'B';
        break;
    case 6:
        values = 'C';
        break;
    }
    values = check_nb2(params, values, c);
    return (values);
}