/*
** EPITECH PROJECT, 2019
** my_ls_l.c
** File description:
** my_ls_l.c
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

char *file_inspect2(char *ls, char *file)
{
    char *str = my_strdup(ls);

    str = my_strcat(str, "/");
    str = my_strcat(str, file);
    return (str);
}

char *file_inspect(char *ls, char *file)
{
    char *str = my_strdup(ls);

    if (my_strcmp(str, ".") == 0) {
        str = my_strcat(str, "/");
        str = my_strcat(str, file);
        return (str);
    }
    str = file_inspect2(ls, file);
}

void print_params(params_t *params, struct passwd *passwd, struct group  *grp)
{
    perm(params->sta);
    params->pw_name = passwd->pw_name;
    params->gr_name = grp->gr_name;
    my_putchar(' ');
    my_put_nbr(params->n_link);
    my_putchar(' ');
    my_putstr(params->pw_name);
    my_putchar(' ');
    my_putstr(params->gr_name);
    my_putchar(' ');
    my_put_nbr(params->stsize);
    my_putchar(' ');
    for (int i = 3; i < 16; i++)
        my_putchar(params->ctime[i]);
    my_putchar(' ');
    my_putstr(params->name);
    my_putchar('\n');
}

void my_ls_l(params_t *params)
{
    DIR *fd = opendir(params->road);
    struct dirent *dirent;

    check_error(fd, params);
    total_block(params);
    while ((dirent = readdir(fd)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            params->str = file_inspect(params->road, dirent->d_name);
            stat(params->str, &params->sta);
            params->passwd = getpwuid(params->sta.st_uid);
            params->grp = getgrgid(params->sta.st_gid);
            params->n_link = params->sta.st_nlink;
            params->stsize = params->sta.st_size;
            params->ctime = ctime(&params->sta.st_mtime);
            params->name = dirent->d_name;
            print_params(params, params->passwd, params->grp);
        }
    }
}