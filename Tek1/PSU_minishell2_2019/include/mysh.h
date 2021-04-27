/*
** EPITECH PROJECT, 2019
** mysh.h
** File description:
** mysh.h
*/

#ifndef my_mysh_h_
#define my_mysh_h_
#include "my.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>

typedef struct env
{
    char **envi;
    char *str_home;
    char *str_pwd;
    char *str_old_pwd;
    char **tab_old_pwd;
    int old_pwd;
    int pwd;
    int home;
    int size_envi;
    char *newstr_old_pwd;
} env_t;

typedef struct params
{
    char **path_tab;
    char **cmd;
    char **all_cmd;
    char *save_cmd;
    char ***cmd_parse;
    char *path;
    char *good_cmd;
    char *good_path;
    char *save;
    int exe;
    int file;
    char **redi;
    env_t env;
}params_t;

typedef struct pipe
{
    char ***cmd;
    int *fd;
    pid_t pid;
    int fdd;
    char *path;
    int len;
    int status;
    char **cmd_pipe;
    int k;
    int redi;
    char **tab_redi;
    int open;
    int in;
    int bulletin;
} pipe_t;

int get_line_of_env(params_t *params, char *cmd);
int find_bulltin2(params_t *params, char *cmd, char **all_cmd);
int find_bulltin(params_t *params, char *cmd, char **all_cmd);

int check_special_cara(params_t *p, char *road_file, char **all_cmd, char *rd);
int cd_without_env(params_t *params, char *file, char *road, char *s);
int check_cd_tiret(char *road_file, params_t *params, char *road, char *cmd);
int check_arg_cd(params_t *params, char *road_file, char **cmd, char *road);
void check_cd(params_t *params, char *file, char *cmd, char **all_cmd);

int check_dir(char *cmd);
int check_directory_executable(params_t *params, char *cmd, char **all_cmd);

int check_error_excve(char *cmd, params_t *params, int error);
int check_exit_cara_env(params_t *params, char *str, char *scd_el);
void print_cmd_not_found(params_t *params, char *cmd);
void check_error_segfault(int status);
int print_error_directory(char *cmd);

int check_cara(char c);
char *check_end_space(char *str);
int check_begin_space(char *str, int i);
char *check_final(char *str);
char *clean_str(char *str, params_t *params);

int check_execve_option(char *cmd, params_t *params, pid_t pids);
int execute_execve(char *cmd, params_t *params, pid_t pid, char **all_cmd);
int execute_cmd(char *cmd, params_t *params, char **all_cmd);

void launch_cmd(params_t *params, char *cmd);
void create_cmd_tab(params_t *params, char *cmd);

void free_and_put_nul(params_t *params, char *fst_el, int ln);
char **write_one_element(params_t *params, char **tab, char *fst_el, int i);

void print_env(params_t *params, char **all_cmd);
int check_envi(char **env);
void create_envi(char **env, params_t *params);

char *check_executable(char *cmd, params_t *params);
char *check_access(int len, char *rslt, params_t *params);
int check_in_the_file(char *cmd, params_t *params, char **all_cmd);
int check_file_executable(params_t *params, char *cmd);

void exe_cmd(params_t *params, char **cmd);
char *check_good_cmd(char *cmd, params_t *params);
int check_execute_cmd(char *cmd, params_t *params, char **all_cmd);
void check_cmd(char *cmd, params_t *params);

int check_entry(char *cmd);
void check_exit(char *cmd, params_t *params, char **all_cmd);

int check_env_null(params_t *params);
void my_getenv_path(params_t *params, char *cmd);
int get_line_old_pwd(params_t *params);
int get_line_pwd(params_t *params);
int get_line_home(params_t *params);

char *get_the_path(char *env, params_t *params);
void init_struct(params_t *params);
int init_struct_pipe(pipe_t *pipe, params_t *params);

void funct_get_line(char *cmd, params_t *params);
void boucl_inf(char **env, params_t *params);

int execute_pipe_condi(params_t *params, pipe_t *p, int k, int *fd);
int execute_pipe(params_t *params, pipe_t *pip);
int prepare_pipe(params_t *params, int i);
int check_pipe(params_t *params, char *cmd);

char *check_access_for_pipe(int len, char *rslt,
params_t *params, char *entry);
int check_pipe_error(char ***tab, char *str);
char ***parse_pipe_cmd(params_t *params, pipe_t *pipe);
void prepare_check_access(params_t *params, pipe_t *pip, int k);

char **create_tab_old_pwd(char **tab);
int get_line_old_pwd_special_tab(params_t *params);
void replace_old_pwd(params_t *params, char *fst_el, char *scd_el, int ln);
int check_same_old_pwd(params_t *params, char *fst_el, char *scd_el);
int check_redirection(params_t *params, char **cmd);

int check_exit_cara_env_no_env(params_t *params, char *str,
char *scd_el, char **all_cmd);
int check_exit_setenv_no_env(params_t *params, char **all_cmd);
char **different_env_no_env(char *fst_el, char *scd_el);
char **write_no_env(char *fst_el);
void setenv_without_env(params_t *param, char **all_cmd);

void free_and_replace(params_t *params, char *fst_el, char *scd_el, int ln);
int check_same_env(params_t *params, char *fst_el, char *scd_el);
int check_exit_setenv(params_t *params, char **all_cmd);
void different_env(params_t *params, char *fst_el, char *scd_el);
void setenv_funct(params_t *params, char **all_cmd);

int check_unsetenv(params_t *params, char **all_cmd);
int check_same_begin(char *elem_env, char *entry);
int unsetenv_funct(params_t *params, char **all_cmd);
int check_if_path(params_t *params);


void my_pipe(pipe_t *pip, params_t *params);
int check_redirection_pipe(params_t *params, pipe_t *p, int k);
int open_pipe(params_t *params, pipe_t *p, int k);
int open_before(params_t *params, pipe_t *p, int op);
void execute_cmd_pipe(params_t *params, pipe_t *p, char **cmd_tab, char *cmd);
int check_bulletin(params_t *pa, pipe_t *p, int k);
int prepare_pipe(params_t *params, int i);
int check_final_pipe(params_t *pa, pipe_t *p, int i, int op);
int check_invalid_cmd(pipe_t *p, int k);
int check_error_excve_pipe(char *cmd, params_t *params, int error);

#endif /* my_mysh_ */