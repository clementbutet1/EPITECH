/*
** EPITECH PROJECT, 2019
** my_ls_t.c
** File description:
** my_ls_t.c
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

void swap_name(params_t *params, lst_t *lst)
{
    lst->tempo = lst->inttab[lst->i];
    lst->tempo_str = lst->tab[lst->i];

    while (lst->inttab[lst->i] > lst->inttab[lst->ii]) {
        if (lst->inttab[lst->i] > lst->inttab[lst->ii]) {
            lst->tempo = lst->inttab[lst->i];
            lst->inttab[lst->i] = lst->inttab[lst->ii];
            lst->inttab[lst->ii] = lst->tempo;
            lst->tempo_str = lst->tab[lst->i];
            lst->tab[lst->i] = lst->tab[lst->ii];
            lst->tab[lst->ii] = lst->tempo_str;
        }
    }
}

void tab_time(params_t *params, lst_t *lst)
{
    lst->inttab = malloc(sizeof(long int) * params->z);
    struct stat s;
    lst->ii = 1;

    for (int k = 0; k != params->z; k++) {
        stat(my_strcat(params->road, lst->tab[k]), &s);
        lst->inttab[k] = s.st_mtime;
    }
    for (; lst->i != params->z; lst->i++) {
        for (;lst->ii != params->z; lst->ii++)
            swap_name(params, lst);
        lst->ii = 0;
    }
    for (int i = 0; i != params->z; i++) {
        my_putstr(lst->tab[i]);
        my_putchar(10);
    }
}

void my_ls_t(params_t *params, lst_t *lst)
{
    struct dirent *dirent;
    DIR *fd = opendir(params->road);

    check_error(fd, params);
    while (dirent = readdir(fd))
        if (dirent->d_name[0] != '.')
            params->z++;
    closedir(fd);
    fd = opendir(params->road);
    lst->tab = malloc(sizeof(char *) * (params->z + 1));
    for (int j = 0; (dirent = readdir(fd));) {
        if (dirent->d_name[0] != '.') {
            lst->tab[j] = malloc(sizeof(char) * (my_strlen(dirent->d_name)+1));
            lst->tab[j] = my_strcat(lst->tab[j], dirent->d_name);
            j++;
        }
    }
    closedir(fd);
    tab_time(params, lst);
}

void prepare_my_ls_t(params_t *params)
{
    lst_t lst;

    lst.i = 0;
    lst.ii = 0;
    lst.tab = NULL;
    lst.inttab = NULL;
    lst.tempo = 0;
    lst.tempo_str = NULL;
    intit_struct(params);
    my_ls_t(params, &lst);
    exit(0);
}
