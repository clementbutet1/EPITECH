/*
** EPITECH PROJECT, 2019
** my_simple_ls.c
** File description:
** my_simple_ls.c
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

void my_ls(int ac, char **av, params_t *params)
{
    struct dirent *dirent;
    DIR *fd = opendir(params->road);

    check_error(fd, params);
    while ((dirent = readdir(fd)) != NULL) {
        if ((dirent->d_name[0] != '.')) {
            my_putstr(dirent->d_name);
            my_putchar('\n');
        }
    }
    exit (0);
}

void my_ls_for_rm(DIR *fd, params_t *params)
{
    struct dirent *dirent;

    check_error(fd, params);
    while ((dirent = readdir(fd)) != NULL) {
        if ((dirent->d_name[0] != '.')) {
            my_putstr(dirent->d_name);
            my_putchar('\n');
        }
    }
    return;
}