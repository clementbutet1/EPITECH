/*
** EPITECH PROJECT, 2019
** my_ls_lrm.c
** File description:
** my_ls_lrm.c
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

void total_block2(DIR *fd, char *direct, params_t *params)
{
    struct dirent *dirent;
    params->total = 0;

    while ((dirent = readdir(fd))) {
        params->cat = my_strcat(direct, "/");
        params->cat2 = my_strcat(params->cat, dirent->d_name);
        if ((lstat(params->cat2, &params->sta)) == 0)
            if (dirent->d_name[0] != '.')
                params->total += params->sta.st_blocks;
    }
    closedir(fd);
    my_putstr("total");
    my_putchar(' ');
    my_put_nbr(params->total / 2);
    my_putchar('\n');
}

void my_ls_l_for_lrm(DIR *fd, char *direct, params_t *params)
{
    struct dirent *dirent;

    check_error(fd, params);
    total_block2(opendir(direct), direct, params);
    while ((dirent = readdir(fd)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            params->str = file_inspect(direct, dirent->d_name);
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

void my_ls_rm_for_lrm(params_t *params, char *direct)
{
    struct dirent *dirent;
    struct stat sta;
    DIR *fd;
    char *name;

    my_ls_l_for_lrm(opendir(direct), direct, params);
    my_putchar('\n');
    fd = opendir(direct);
    check_error(fd, params);
    while ((dirent = readdir(fd)) != 0) {
        params->str = my_strcat(my_strcat(direct, "/"), dirent->d_name);
        name = my_strcat("./", dirent->d_name);
        stat(params->str, &sta);
        if (S_ISDIR(sta.st_mode) && dirent->d_name[0] != '.') {
            my_putstr(name);
            my_putstr(":\n");
            my_ls_rm_for_lrm(params, params->str);
        }
    }
}

void prepare_llrm(params_t *params)
{
    intit_struct(params);
    if (params->road[0] == '.' && params->road[1] == '/'
    && params->road[2] == '\0') {
        my_putchar('.');
        my_putstr(":\n");
    }
    else
        if (params->enter == NULL) {
            params->road;
            my_putstr(params->road);
            my_putchar(':');
            my_putchar('\n');
        } else {
            params->road = NULL;
            params->road = params->enter;
            my_putstr(params->road);
            my_putstr(":\n");
        }
    my_ls_rm_for_lrm(params, params->road);
}

void prepare_my_ls_lrm(params_t *params)
{
    intit_struct(params);
    prepare_llrm(params);
}