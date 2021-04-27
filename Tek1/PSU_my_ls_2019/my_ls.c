/*
** EPITECH PROJECT, 2019
** my_ls.c
** File description:
** my_ls.c
*/

#include "include/my_ls.h"
#include "my.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>

int flags_options(int ac, char *flag, params_t *params)
{
    for (int i = 0; flag[i] != '\0'; i++) {
        (flag[i] == 'l' && flag[i + 1] == 'R'
        || flag[i] == 'R' && flag[i + 1] == 'l')
        ? prepare_my_ls_lrm(params),  exit (0) : 0;
        switch (flag[i]) {
        case 'l':
            intit_struct(params);
            my_ls_l(params);
            break;
        case 't':
            prepare_my_ls_t(params);
            break;
        case 'R':
            prepare_rm(params);
            break;
        }
    }
}

int check_flags_options(int ac, char *flag, params_t *params)
{
    for (int i = 1; flag[i] != '\0'; i++) {
        if (flag[i] != 'l' && flag[i] != 'r'
        && flag[i] != 'd'
        && flag[i] != 'R' && flag[i] != 't') {
            exit (84);
        }
    }
    if (flags_options(ac, flag, params) == 0)
        return (0);
}

void check_input(int ac, char **av, params_t *params)
{
    int nb = -1;
    static int i = 1;

    for (int m = 0; m != ac; m++)
        if (av[m][0] != '-')
            nb = nb + 1;
    for (i; i != ac; i++)
        if (av[i][0] != '-')
            break;
    if (nb == 0) {
        params->road = ("./");
    } else if (nb == 1)
        params->road = my_strcat("./", (av[i]));
    params->enter = av[i];
    for (int i = 1; i < ac; i++)
        if (av[i][0] == '-')
            if (check_flags_options(ac, av[i], params) == 0)
                return;
    (nb == 0 && ac == 1 || ac == 2) ? my_ls(ac, av, params) : 0;
}

int main(int ac, char **av)
{
    params_t params;

    check_input(ac, av, &params);
    return (0);
}