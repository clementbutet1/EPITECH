/*
** EPITECH PROJECT, 2019
** my_ls.h
** File description:
** my_ls.h
*/

#ifndef my_ls_h_
#define my_ls_h_
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

typedef struct params
{
    char *road;
    char *enter;
    int total;
    char *str;
    int block;
    char *cat;
    char *cat2;
    char *cat3;
    int n_link;
    char *pw_name;
    char *gr_name;
    int stsize;
    char *ctime;
    char *name;
    int z;
    struct stat sta;
    struct group *grp;
    struct passwd *passwd;
}params_t;

typedef struct lst
{
    char **tab;
    long int *inttab;
    int ii;
    int i;
    int tempo;
    char *tempo_str;
}lst_t;


void my_ls_l(params_t *params);
void my_ls(int ac, char **av, params_t *params);
void perm(struct stat sta);
void check_error(DIR *fd, params_t *params);
void total_block(params_t *params);
void my_ls_lrm(params_t *params);
void my_ls_for_rm(DIR *fd, params_t *params);
char *file_inspect(char *ls, char *file);
char *file_inspect2(char *ls, char *file);
void my_ls_rm(params_t *params, char *road);
void intit_struct(params_t *params);
void prepare_rm(params_t *params);
void print_params(params_t *params, struct passwd *passwd, struct group  *grp);
void prepare_my_ls_lrm(params_t *params);
void my_ls_t(params_t *params, lst_t *lst);
void prepare_my_ls_t(params_t *params);

#endif /* my_ls_ */