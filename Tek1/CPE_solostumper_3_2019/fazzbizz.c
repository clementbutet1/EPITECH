/*
** EPITECH PROJECT, 2019
** fazzbizz.c
** File description:
** fazzbizz.c
*/

#include <stdio.h>
#include <stdlib.h>

int check_fazzbizz2(int arg)
{
    if (arg % 9 == 0) {
        printf("Bizz\n");
        return (0);
    } else {
        printf("%i\n", arg);
        return (0);
    }
}

int check_fazzbizz(int arg)
{
    if (arg % 10 == 0 && arg % 9 == 0) {
        printf("FazzBizz\n");
        return (0);
    }
    if (arg % 10 == 0) {
        printf("Fazz\n");
        return (0);
    }
    check_fazzbizz2(arg);
}

int fazzbizz(int arg1, int arg2)
{
    int i = arg1;
    int j = 1;

    while (i != arg2) {
        check_fazzbizz(i);
        i++;
    }
    check_fazzbizz(i);
}

int main(int ac, char **av)
{
    int arg1 = 0;
    int arg2 = 0;

    if (ac != 3)
        return (84);
    arg1 = atoi(av[1]);
    arg2 = atoi(av[2]);
    if (arg1 > arg2) {
        printf("Error: the second parameter must ");
        printf("be greater than the first one.\n");
        return (84);
    }
    fazzbizz(arg1, arg2);
    return (0);
}
