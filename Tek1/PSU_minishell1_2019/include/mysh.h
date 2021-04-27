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
    char **path_tab;
    char **cmd;
    char *path;
    char **envi;
    char *good_cmd;
    char *good_path;
    int old_pwd;
    int pwd;
    int home;
    char *str_home;
    char *str_pwd;
    char *str_old_pwd;
    char *old_road;
    char *save_str_old_pwd;
    int size_envi;
    char *save;
    int exe;
    int file;
}params_t;

int check_unsetenv(params_t *params);
int my_count_word(char *str, char separator);
int count_letter(char *word, char separator, int i);
int get_line_of_env(params_t *params);
int check_cd_tiret(char *road_file, params_t *params, char *road, char *cmd);
void check_error_excve(char *cmd, params_t *params, size_t size, int error);
int check_directory_executable(params_t *params, char *cmd);
int check_file_executable(params_t *params, char *cmd, size_t size);
int check_space_or_tab(char *str, char *rslt, int i);
int check_exit_cara_env(params_t *params, char *str, char *scd_el);
void write_one_element(params_t *params, char *fst_el);
int check_same_env(params_t *params, char *fst_el, char *scd_el);
int check_same_begin(char *elem_env, char *entry);
int check_if_path(params_t *params);
void setenv_funct(params_t *params);
int unsetenv_funct(params_t *params);
int check_tab_and_space(char *str, int i, int c);
char *check_access(int len, char *rslt, params_t *params);
int check_env_null(params_t *params);
int get_line_old_pwd_save(params_t *params);
void funct_get_line(char *cmd, params_t *params);
void check_exit(char *cmd, params_t *params);
char **my_str_tab(char *str, char separator);
char *clean_str(char *str, params_t *params);
void check_cmd(char *cmd, params_t *params, size_t size);
int check_begin_space(char *str, int i);
char *check_end_space(char *str);
int check_space(char *str, int c, int i);
int check_cara(char c);
int check_entry(char *cmd);
int find_bulltin(params_t *params, char *cmd, size_t size);
int check_same_word(char *str, char *str1);
void check_cd(params_t *params, char *file, char *cmd);
char *my_get_env(params_t *params, char *search);
void my_getenv_path(params_t *params, char *cmd);
void print_env(params_t *params);
char *check_space_tab(char *str);
int check_in_the_file(char *cmd, params_t *params, size_t size);
int check_envi(char **env);
int get_line_old_pwd(params_t *params);
int get_line_pwd(params_t *params);
int get_line_home(params_t *params);
char *get_the_path(char *env, params_t *params);
int execute_cmd(char *cmd, params_t *params, size_t size);
void check_error_segfault(int status);

#endif /* my_ls_ */