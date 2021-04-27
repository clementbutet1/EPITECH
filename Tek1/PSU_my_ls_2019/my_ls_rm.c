/*
** EPITECH PROJECT, 2019
** my_ls_rm.c
** File description:
** my_ls_rm.c
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

void prepare_rm(params_t *params)
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
    my_ls_rm(params, params->road);
}

void my_ls_rm(params_t *params, char *dir)
{
    struct dirent *dirent;
    struct stat sta;
    DIR *fd;
    char *name;

    my_ls_for_rm(opendir(dir), params);
    my_putchar('\n');
    fd = opendir(dir);
    check_error(fd, params);
    while ((dirent = readdir(fd)) != 0) {
        params->str = my_strcat(my_strcat(dir, "/"), dirent->d_name);
        name = my_strcat("./", dirent->d_name);
        stat(params->str, &sta);
        if (S_ISDIR(sta.st_mode) && dirent->d_name[0] != '.') {
            my_putstr(name);
            my_putstr(":\n");
            my_ls_rm(params, params->str);
        }
    }
}