/*
** EPITECH PROJECT, 2019
** evalexpr.c
** File description:
** evalexpr.c
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char *supp_space(char *str)
{
    int	id = 0;
    char *rslt = malloc(my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            rslt[id] = str[i];
            id++;
        }
    }
    rslt[id] = '\0';
    return (rslt);
}

int	fct1(char **av)
{
    int	a = my_line_analyse(av);
    int	b;
    char operator;
    int i = 0;

    for (; *av[i] != '\0' && *av[i] != 41;) {
        operator = (*av)[i];
        (*av)++;
        if (operator == 43 || operator == 45)
            b = fct2(av);
        else
            b = my_line_analyse(av);
        a = calculope(a, b, operator);
    }
    return (a);
}

int	fct2(char **av)
{
    int	a = my_line_analyse(av);
    int	b;
    char operator;
    int i = 0;

    for (; *av[i] == 47 || *av[i] == 37 || *av[i] == 42;) {
        operator = *av[i];
        (*av)++;
        b = my_line_analyse(av);
        a = calculope(a, b, operator);
    }
    return (a);
}

int	execute(char *str)
{
    int i = 0;

    str = supp_space(str);
    if (str[i] == '\0')
        return (0);
    return (fct1(&str));
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(execute(av[1]));
        my_putchar('\n');
        return (EXIT_SUCCESS);
    }
}

