/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

void displayerror(void)
{
    printf("USAGE\n");
    printf("    ./103cipher message key flag\n\n");
    printf("DESCRIPTION\n");
    printf("    message     a message, made of ASCII characters\n");
    printf("    key         the encryption key, made of ASCII characters\n");
    printf("    flag        0 for the message to be encrypted, 1 to be decrypted\n");
}

void checkargs(int ac, char **av)
{
    if (!(ac == 4)) {
        displayerror();
        exit (84);
    }
    if (ac == 3 || ac == 2 || ac == 1 || ac == 0) {
        displayerror();
        exit (84);
    }
}

void checkcara(int ac, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 127 && str[i] > 32)) {
            return;
        } else {
            displayerror();
            exit (84);
        }
        i++;
    }
}

int finderror(int ac, char **av)
{
    checkargs(ac, av);
    checkcara(ac, av[1]);
    checkcara(ac, av[2]);

    if (ac != 4) {
        displayerror();
        exit (84);
    }
    if (ac == 4) {
        if (!(av[3][0] == '0' || av[3][0] == '1')) {
            displayerror();
            exit (84);
        }
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        displayerror();
        exit (84);
    }
}
