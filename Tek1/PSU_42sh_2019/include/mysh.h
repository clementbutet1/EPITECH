/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** mysh.h
*/

#include <unistd.h>
#include <glob.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <curses.h>
#include <term.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include "my.h"

typedef struct termios termios_t;
typedef struct winsize winsize_t;

typedef struct cursor {
    int cursor;
    int pos_str;
    size_t prompt;
    char **history;
    int pos_hist;
}cursor_t;

typedef struct alias_s
{
    char **alias;
    char *new;
    int width;
    int height;
    char *command;
}alias_t;

typedef struct history
{
    char **min;
    char **h;
    char **history;
}history_t;

typedef struct spipe
{
    int free_or_not;
    char *double_and;
    char *double_pipe;
    int is_double_and;
    int is_double_pipe;
    int fd_in;
    int fd_out;
}spipe_t;

typedef struct path
{
    char **env;
    char **path;
    char *home;
    char *line_path;
    char *pwd;
    char *oldpwd;
}path_t;

typedef struct sh
{
    pid_t pid;
    char *buffer;
    int is_redirection;
    size_t s;
    char ***exe;
    char **ligne;
    char **pipe;
    char *repertoire;
    int taille_env;
    int exit;
    int good_redi;
    char **set;
    int parenth;
    path_t path;
    spipe_t spipe;
    termios_t *term;
    history_t hist;
    alias_t alias;
}sh_t;

void wait_last_pid(sh_t *sh);
int size_history(char **tb);
char get_arrow_key(void);
int cols(char *str);
char *str_move_cursor(char *str, cursor_t *cu, char arrow);
void write_prompt(char *str, char *prompt, cursor_t *cu, winsize_t *w);
int check_cursor(char arrow);
termios_t *remp_term(void);
char *parse_arrow(char *display, sh_t *sh, cursor_t *cu, char *str);
char *handle_special_keys(char *str, char arrow, cursor_t *cu, winsize_t *w);
char *check_arrow_space(char *str, cursor_t *cu, char c, winsize_t *w);
int cols(char *str); 
void execute_fonction2(void);
int boucl_inf(sh_t *sh, time_t now);
void check_cd_tiret2(sh_t *sh);
void copy_string(sh_t *sh, char *str);
void verif_wave(sh_t *sh);
int check_cd_tiret(sh_t *sh);
void prepar_command(char **exe, sh_t *sh);
int alias_find_line(sh_t *sh, char *str);
void enter_alias_in_tab(int line, sh_t *sh, char *name);
void set_alias(sh_t *sh, char *name);
int check_alias(char **exe, sh_t *sh);
int buffer_pipe2(sh_t *sh, int fd_in, int fd_out, int d);
int check_buffer_pipe(sh_t *sh, int fd_in, int fd_out);
int check_buffer_pipe(sh_t *sh, int fd_in, int fd_out);
void use_buffer_line(sh_t *sh, char *ligne, int free_or_not);
int check_buffer(sh_t *sh, time_t now);
int check_buffer2(char **exe, sh_t *sh);
int check_buffer3(sh_t *sh, char **exe);
int buffer_pipe2_part2(sh_t *sh, int *fd_in, int *fd_out, int i);
int buffer_pipe2_part1(sh_t *sh, int *fd_in, int i);
int check_all_builtin(char **exe, sh_t *sh);
int check_all_function(char **exe, sh_t *sh);
int execute_double_and(sh_t *sh);
char *check_double_and(char *buffer, sh_t *sh);
int execute_double_pipe(sh_t *sh);
char *check_double_pipe(char *buffer, sh_t *sh);
void print_echo(char **exe, int type);
int check_echo(char **exe);
void print_env(sh_t *sh);
int check_env(char **exe, sh_t *sh);
char **combine_2_tab_indice(char **exe, glob_t g, int i);
char **add_global_in_exe(char **exe, int i);
char **check_global(char **exe);
void check_print(int type, int cpt, char *str);
void print_history_tab(sh_t *sh);
int check_arg(char *str);
int check_history(char **exe, sh_t *sh, char *name_cmd, int i);
char **check_redirection3(char **tb, int *d, sh_t *sh, int cas);
char **check_redirection2(char **tb, int *d, sh_t *sh, int cas);
char **check_redirection(char **tb, sh_t *sh, int cas);
int print_repeat(char **exe, sh_t *sh);
int check_repeat(char **exe, sh_t *sh);
void print_tab(char **tb);
int check_set(char **exe, sh_t *sh, char *name_cmd);
void modif_env3(char **exe, sh_t *sh);
int modif_env2(char **exe, sh_t *sh);
int modif_env(char **exe, sh_t *sh);
int check_setenv(char **exe, sh_t *sh);
void modif_alias2_rm(char **exe, sh_t *sh);
void modif_alias_rm(char **exe, sh_t *sh);
int check_unalias(char **exe, sh_t *sh);
int check_same_begin(char *elem_env, char *entry);
int execute_unset(sh_t *sh, char **all_cmd);
int check_unset(char **exe, sh_t *sh, char *name_cmd);
int does_env_exist(char **exe, sh_t *sh);
void rm_env(sh_t *sh, int d);
void modif_env2_rm(char **exe, sh_t *sh);
void modif_env_rm(char **exe, sh_t *sh);
int check_unsetenv(char **exe, sh_t *sh);
void check_bulletin_where(char **cmd);
void print_path(char *path);
int check_where(char **exe, sh_t *sh, char *name_cmd, int i);
char *check_access(int len, char *rslt, sh_t *sh, char *cmd);
int check_bulletin_which(char *cmd);
void execute_which(char **exe, sh_t *sh);
int check_which(char **exe, sh_t *sh, char *name_cmd, int i);
char **delete_quote(char **exe);
char *clean_buffer3(char *buffer, int d);
void clean_buffer2(char *buffer, int *i, char *new_str, int a);
char *clean_buffer4(char *buffer, char *new_str, int i, int a);
char *clean_buffer(char *buffer, int i);
void print_alias_tab(sh_t *sh);
void create_alias_tab(sh_t *sh);
void free_alias_tab(sh_t *sh);
void create_executable3(char *buffer, int j, char **exe);
int create_executable2(char *buffer, int d, int j);
char **create_executable(char *buffer);
void create_all_path2(sh_t *sh, int q);
void create_all_path(sh_t *sh, int q);
void remp_path(sh_t *sh, int a, int d);
int check_error_pipe(char *buffer);
int check_buffer(sh_t *sh, time_t now);
int find_path(sh_t *sh);
char *my_strcat(char *file, char *name);
void execute_fonction3(char **exe, sh_t *sh);
int execute_fonction(char **exe, sh_t *sh);
int check_par(char **str);
int err_handling_foreach(char **str);
int check_foreach(char **str, sh_t *sh);
char **recup_arg(char **exe);
char **add_com(char **com, char *arg);
int is_var(char *com, char *var);
void exec_foreach(char **arg, char **com, sh_t *sh, char *var);
void foreach(sh_t *sh, char **exe);
int is_forking(int sig);
void handler_siguint(int i);
void handler_sigsegv(void);
void print_signal(int sig, int status, sh_t *sh);
char **add_element_into_hist(sh_t *sh, char *buffer);
char **add_element_into_min(sh_t *sh, char *buffer);
char **add_element_into_h(sh_t *sh, char *buffer);
char **write_no_env(char *fst_el);
int create_history_tab(sh_t *sh, time_t now);
char **copy_tab(char **tb);
void function_help(int ac, char **av);
void init_sh2(sh_t *sh, char **env);
void init_sh(sh_t *sh, char **env, int ac, char **av);
int error_find_main(sh_t *sh, int s);
int find_main_directory(sh_t *sh, int s);
int check_cd(char **exe, sh_t *sh);
void my_cd2(char *chemin, sh_t *sh);
void my_cd(char **exe, sh_t *sh, int cas);
char *my_strcat_slash(char *file, char *name);
char *my_strcat(char *file, char *name);
int in_parenth(char *str, int p);
int check_arg_par(char *str, int *p, int *q);
char *my_parenth(char *str, sh_t *sh);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy_spe(char const *src, int n);
char **set_line(int size_line, char *str, int size_egal);
char **change_to_set(char **tb);
void display_redi_error(int fd, char *str);
char **rm_redirection_exe(char **tb, int *d);
int error_redirection3(char **tb, int *d, sh_t *sh);
int error_redirection2(char **tb, int *d, sh_t *sh);
int error_redirection(char **tb, sh_t *sh, int d);
void replace_env2(sh_t *sh, char *str, char *name);
void replace_env(sh_t *sh, char *str, char *name);
int check_alias_name(char *name, sh_t *sh);
char *set_alias_command(int size, char *alias);
void modify_buffer_alias(char *command, sh_t *sh);
void modify_exe_alias(char **exe, sh_t *sh);
int my_strlen_redirection(char *str);
char **my_str_to_word_array_mysh3(char *buffer, char sepa, char **tb);
int my_str_to_word_array_mysh2(char *buffer, char sepa);
char **my_str_to_word_array_mysh(char *buffer, char sepa);
int free_all(char **exe);
int free_end(sh_t *sh);
void add_equal(char **exe, int len);
int is_a_directory(char **exe);
int verif_type2(char **exe, sh_t *sh);
int verif_type(char **exe, sh_t *sh);
int verif_exit(char **exe, sh_t *sh);
int check_exit(char **exe, sh_t *sh);
int find_size_alias_name(char *buffer, int pos);
int find_pos_alias_name(char *buffer);
int my_strlen_alias(char *str, int cas);
char *complete_alias(sh_t *sh, int i, int line, char *buffer);
char *find_alias_name_buff(char *buffer, sh_t *sh);
void wait_last_pid(sh_t *sh);