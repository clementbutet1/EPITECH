/*
** EPITECH PROJECT, 2019
** my_line_analyse.c
** File description:
** my_line_analyse.c
*/

int my_line_analyse(char **av)
{
    int nb = 0;
    int signe = 1;
    int i = 0;

    if (*av[i] == 43 || *av[i] == 45) {
        ((*av)[i] == '-') ? signe = -1, (*av)++ : 0;
    }
    if ((*av)[i] == 40) {
        (*av)++;
        nb = fct1(av);
        if ((*av)[i] == 41)
            (*av)++;
        return (signe * nb);
    }
    for (; 48 <= *av[i] && *av[i] <= 57; (*av)++) {
        nb = (nb * 10) + *av[i] - 48;
    }
    return (signe * nb);
}

