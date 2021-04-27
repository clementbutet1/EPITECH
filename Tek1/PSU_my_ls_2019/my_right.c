/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_right.c
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

void total_block(params_t *params)
{
    struct dirent *dirent;
    params->total = 0;
    DIR *fd = opendir(params->road);

    while ((dirent = readdir(fd))) {
        params->cat = my_strcat(params->road, "/");
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

void my_right_part3(struct stat sta)
{
    if ((sta.st_mode & S_ISVTX) && !(sta.st_mode & S_IXOTH)) {
        my_putchar('T');
        my_putchar(' ');
    }
    else if ((sta.st_mode & S_ISVTX) && (sta.st_mode & S_IXOTH)) {
        my_putchar('t');
        my_putchar(' ');
    }
    else
        sta.st_mode & S_IXOTH ? my_putchar('x') : my_putchar('-');
}

void my_right_part2(struct stat sta)
{
    if ((sta.st_mode & S_ISGID) && !(sta.st_mode & S_IXGRP))
        my_putchar('S');
    else if ((sta.st_mode & S_ISGID) && (sta.st_mode & S_IXGRP))
        my_putchar('s');
    else
        sta.st_mode & S_IXGRP ? my_putchar('x') : my_putchar('-');
    sta.st_mode & S_IROTH ? my_putchar('r') : my_putchar('-');
    sta.st_mode & S_IWOTH ? my_putchar('w') : my_putchar('-');
    my_right_part3(sta);
}

void perm(struct stat sta)
{
    S_ISDIR(sta.st_mode) ? my_putchar('d') : my_putchar('-');
    sta.st_mode & S_IRUSR ? my_putchar('r') : my_putchar('-');
    sta.st_mode & S_IWUSR ? my_putchar('w') : my_putchar('-');
    sta.st_mode & S_IXUSR ? my_putchar('x') : my_putchar('-');
    sta.st_mode & S_IRGRP ? my_putchar('r') : my_putchar('-');
    sta.st_mode & S_IWGRP ? my_putchar('w') : my_putchar('-');
    my_right_part2(sta);
}

void check_error(DIR *fd, params_t *params)
{
    if (fd == NULL) {
        my_putstr("my_ls: cannot acces '");
        my_putstr(params->road);
        my_putstr("': No such file or directory");
        exit (84);
    }
}