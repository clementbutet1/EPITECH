/*
** EPITECH PROJECT, 2019
** asm.h
** File description:
** asm.h
*/

#ifndef my_asm_h_
#define my_asm_h_
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
#include "op.h"
#include "my.h"

typedef struct params
{
    char *name;
    char *comment;
    int magic_number;
    int fd;
    int *line;
    int *magic_nb;
    int all_prog_size;
    char **label;
}params_t;

typedef struct instu_core {
    int instru;
    int coding_byte;
    int dir_size;
    int status;
    int *params;
    op_t tab;
    int prog_size;
    char *str;
    int line;
    char **label;
    struct instu_core *next;
}instu_core_t;


typedef struct core
{
    int *name;
    int *comment;
}core_t;

int check_line_instru(char *str, char *her_tab, int *cursor,
instu_core_t *new);
void check_dir_size(char *str, instu_core_t *new);
void write_core_params(int *tab, int fd);
char **check_tab(char **tab, char *str);
void check_error_begin(char **tab);
int *add_incrementation_verif_get(instu_core_t *new, int *nb_arg, int *b);
void init_struct_clean_file(params_t *pa);
int *check_condi_magic_indi(char *str, int c, int *b);
int *check_condi_magic_dir(instu_core_t *new, char *str, int c, int *b);
int *create_magic_tab_negative(int c, int size);
int *put_in_good_tab(int *tab, int size);
int change_int_params(instu_core_t *tmp, instu_core_t **instru, int i,
int line);
void create_file_and_write(params_t *params, core_t *core,
instu_core_t **instru, char **file);
void change_label_to_nb2(instu_core_t *tmp, instu_core_t **instru,
params_t *params, int *cursor);
int find_line_labels(instu_core_t *tmp, params_t *params, int number);
int find_line(char *str, params_t *params);
int label_in_params(char *str, int i);
void change_label_to_nb(instu_core_t **instru, params_t *params);
int *create_magic_tab_for_int(int nb, int size);
void check_err_get_indirect(int a, char *str);
void check_error_indirect(instu_core_t *new, int *nb_arg);
void check_err_get_direct(int a, char *str);
void check_error_get_direct(instu_core_t *new, int *nb_arg);
int get_all_instru(instu_core_t **instru, char **file, params_t *params);
int check_instru(char *str);
int is_instruction(char *str);
char **write_one_element(char **tab, char *fst_el, int size_tab);
int *base_hexadecima_to_int_tab(char *str, int k, int *rslt);
char *my_converthexadecimalmi_tab_spe(unsigned int nb, int size);
char *my_converthexadecimalmi_tab(int magic_nb, char *rslt, int i);
int *create_magic_tab_for_int(int nb, int size);
void write_core(int *tab, int fd, int type);
void verif_get_indirect(char *str, int *i, instu_core_t *new, int *nb_arg);
int *verif_get_indirect2(char *str, int *a);
void verif_get_direct(char *str, int *i, instu_core_t *new, int *nb_arg);
int *verif_get_direct2(char *str, int *a);
void verif_get_register(char *str, int *i, instu_core_t *new, int *nb_arg);
int recup_instru(instu_core_t *new, char *str, int line);
int check_error_params(char *str, int i, instu_core_t *new);
int *create_magic_tab(char *nb, int size);
int error_label(char *str, int i, char *label_c);
int error_label2(char *str, int i, char *label_c);
void append_l(instu_core_t **D, instu_core_t *new);
void get_all_label(char **file, params_t *pa);
void add_if_label(char *str, params_t *pa, int line);
char **add_label(char *str, int i, char **label);
int label_conposed_of_label_chars(char *str, int i);
void encode_name_coment(params_t *params, core_t *core);
int *encode(char *str, int size);
void write_core_file(params_t *pa, core_t *co, instu_core_t **instru);
int create_coding_byte(int status, char *str, int i);
int create_coding_byte2(char *str, int i, int bytes, char *binary);
char *add_binary(char *str, int *a, char *add);
int create_coding_byte(int status, char *str, int i);
int is_indirect(char *str, int *i, int cas);
int is_direct(char *str, int *i, int cas);
int is_register(char *str, int *i, int cas);
int *add_two_tab_int(int *tab, int *tab2);
int label_conposed_of_label_chars(char *str, int i);
int check_option_two_byte(char *str);
int my_check_label(char *str);
void check_end(char *str);
char *separe_magic_nb(char *rslt, char *nb, int i);
char *recup_name_and_comment(char *str);
void check_quote(char *str);
char *separe_magic_nb(char *rslt, char *nb, int i);
void base_hexadecima_to_int(char *str, int k, params_t *pa);
char *my_converthexadecimalmi(int magic_nb, char *rslt, int i);
int check_extension(char *filename);
char *separe_magic_nb(char *rslt, char *nb, int i);
int special_strlen(int nb);
void get_magic_int(params_t *params);
int create_file(char *name);
void recup_args(params_t *params, char **tab);
char **clean_file(char **file, params_t *pa);
void display_help(void);
char **open_read(char *filename);
void my_putstr_error(char const *str);
void init_struct(params_t *params);
void free_struct(params_t *params, core_t *core, instu_core_t **instru);
void init_prog(int ac, char **av, params_t *params);
int converthexami_to_int(char *str, int size);
char *separe_magic_nb(char *rslt, char *nb, int i);
void get_magic_int(params_t *pa);

#endif /* my_asm_ */