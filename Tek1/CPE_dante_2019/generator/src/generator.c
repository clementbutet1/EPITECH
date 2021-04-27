/*
** EPITECH PROJECT, 2019
** generator.c
** File description:
** generator.c
*/

#include "my.h"
#include "generator.h"

void check(params_t *params, char **av)
{
    if (params->max_height == 1 && params->max_lenght == 1) {
        my_putchar('*');
        exit (0);
    }
    if (params->max_height == 2 && params->max_lenght == 2 &&
    (strcmp(av[3], "imperfect") == 0)) {
        my_putstr("**\nX*");
        exit (0);
    }
    if (params->max_height == 2 && params->max_lenght == 2 &&
    (strcmp(av[3], "perfect") == 0)) {
        my_putstr("**\n**");
        exit (0);
    }
}

int choose_type(int ac, char **av, params_t *params)
{
    if (ac == 3) {
        params->lab_impefect = create_tab(params->lab_perfect, params);
        create_imperfect_lab(params);
        free(params->lab_impefect);
        return (0);
    }
    if ((strcmp(av[3], "imperfect") == 0) && (ac == 4)) {
        params->lab_impefect = create_tab(params->lab_perfect, params);
        create_imperfect_lab(params);
        free(params->lab_impefect);
        return (0);
    }
    if ((strcmp(av[3], "perfect") == 0) && (ac == 4)) {
        params->lab_perfect = create_tab(params->lab_perfect, params);
        create_perfect_lab(params);
        free(params->lab_perfect);
        return (0);
    } else
        return (84);
}

int main(int ac, char **av)
{
    params_t params;
    srand(time(NULL));

    if (ac != 4 && ac != 3)
        return (84);
    check_error(av);
    params.max_lenght = my_getnbr(av[1]);
    params.max_height = my_getnbr(av[2]);
    check(&params, av);
    if (choose_type(ac, av, &params) == 84)
        return (84);
    return (0);
}