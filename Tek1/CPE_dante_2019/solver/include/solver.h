/*
** EPITECH PROJECT, 2019
** solver.h
** File description:
** solver.h
*/

#ifndef my_solver_h_
#define my_solver_h_
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
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>
#include "solver.h"

typedef struct params
{
    int max_height;
    int max_lenght;
    int size;
    char **map;
    char *buffer;
    int rslt;
    int pos;
}params_t;

void fs_open_file(char const *filename, params_t *params);
void check_error(params_t *params);
int error(int fd, char *buffer);
char **put_nb(char **tab);
void resolve_lab(params_t *params);
void print_map(char **tab);
int algo(params_t *pa, int k);
int algo(params_t *params, int head);
void print_road(params_t *pa);

#endif /* my_solver_h_ */