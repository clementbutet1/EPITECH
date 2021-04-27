/*
** EPITECH PROJECT, 2019
** options.c
** File description:
** options.c
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

void intit_struct(params_t *params)
{
    params->total = 0;
    params->str = NULL;
    params->block = 0;
    params->cat = NULL;
    params->cat2 = NULL;
    params->cat3 = NULL;
    params->n_link = 0;
    params->pw_name = NULL;
    params->gr_name = NULL;
    params->stsize = 0;
    params->ctime = NULL;
    params->name = NULL;
    params->grp = NULL;
    params->passwd = NULL;
    params->z = 0;
}
