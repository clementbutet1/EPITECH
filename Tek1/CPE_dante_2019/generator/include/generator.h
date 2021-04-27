/*
** EPITECH PROJECT, 2019
** generator.h
** File description:
** generator.h
*/

#ifndef my_generator_h_
#define my_generator_h_
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
#include <signal.h>

typedef struct params
{
    int max_lenght;
    int max_height;
    char *buffer;
    char **lab_perfect;
    char **lab_impefect;
}params_t;

void free_tab(char **tab);
char **create_tab(char **tab, params_t *params);
void create_perfect_lab(params_t *params);
void create_imperfect_lab(params_t *params);
int check_same_word(char *str, char *str1);
void print_buffer(char **tab, params_t *p);
void check_error(char **av);
void print_map(char **tab, params_t *params);

#endif /* my_generator_h_ */