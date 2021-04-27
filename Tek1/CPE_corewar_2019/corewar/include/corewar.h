/*
** EPITECH PROJECT, 2019
** corewar.h
** File description:
** corewar.h
*/

#ifndef my_corewar_h_
#define my_corewar_h_
#include <pthread.h>
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
#include "my.h"
#include "op.h"

typedef struct arena
{
    int cycle_die;
    int nbr_lives;
    int cycle_delta;
    char *info;
    int *arena;
} arena_t;

typedef struct intru
{
    int dir_size;
    int cycle_to_wait;
    char *params;
    char *memonic;
    int is_coding_byte;
    int **tab_ins;
    int size_instru;
    int nb_params;
} instru_t;

typedef struct champion
{
    int *header;
    int load_adress;
    int nb_prog;
    char *comment;
    char *name;
    int nbr;
    int size;
    unsigned int *registre;
    int is_alive;
    int pc;
    int carry;
    int *core;
    instru_t *instru;
} champ_t;

typedef struct corewar
{
    champ_t **champion;
    arena_t arena;
    int dump;
    int nb_cor;
    int living_cor;
    char *last_core;
    int size;
    int *instruction;
    int graphic;
    int *val;
} corewar_t;

void change_pc(corewar_t *core, int i);
int condi_get_instru(instru_t *instru, int a, int i);
void condi_get_instru2(int a);
void condi_get_all_instru(corewar_t *core, int i);
void condi_change_pc(corewar_t *core, int i, int j);
instru_t *get_instru(champ_t *champion, corewar_t *core);
int check_argument(char **av);
void recove_champ(char **av, corewar_t *core, int i);
void power_attack(corewar_t *core);
int check_option_two_byte(char *str);
int check_dir_size(char *str);
int check_type(char *str, char *cmp, int *len);
void option_two_byte(instru_t *instru);
void zjmp(corewar_t *co, int i);
void xor(corewar_t *op, int i);
void sub(corewar_t *op, int i);
void sti(corewar_t *op, int i);
void st(corewar_t *op, int i);
void or(corewar_t *op, int i);
void lldi(corewar_t *op, int i);
void lld(corewar_t *op, int i);
void live(corewar_t *op, int i);
void my_lfork(corewar_t *op, int i);
void ldi(corewar_t *op, int i);
void ld(corewar_t *co, int i);
void aff(corewar_t *op, int i);
void add(corewar_t *op, int i);
void and(corewar_t *op, int i);
void my_fork(corewar_t *op, int i);
int base_hexadecimal_to_int(char *str);
char *my_converthexadecimalmi_tab_spe(unsigned int nb, int size);
int change_magic_tab(int *tab);
int change_magic_tab(int *tab);
void champ_name(champ_t *champion);
void check_magic_nb(int *tab);
void get_instru_cor(champ_t *champion, corewar_t *core);
int verif_is_nb(char *str);
void check_values(corewar_t *core);
void display_help(int n);
int my_strendcmp(char *str, char *end);
int get_dump(char **av);
int get_arg(int ac, char **av, corewar_t *core);
int my_strendcmp(char *str, char *end);
int init_arena(corewar_t *core);
int get_nb_prog(char **av);
void fill_champ(champ_t *champion, corewar_t *core);
void values_of_champions(champ_t *champion, corewar_t *core);
void battle_in_arena(corewar_t *core);
void champ_size(champ_t *champion);
void champ_magic_nbr(champ_t *champion);
void champ_comment(champ_t *champion);
void champ_name(champ_t *champion);
int swap_to_endian(int buf);
int check_graphics_mode(char **av, corewar_t *core);
void launch_graphic(corewar_t *core, int i);
void lunch_instr(corewar_t *co, int i);
void add(corewar_t *op, int i);
void aff(corewar_t *op, int i);
void and(corewar_t *op, int i);
void or(corewar_t *op, int i);
void st(corewar_t *op, int i);
void sub(corewar_t *op, int i);
void xor(corewar_t *op, int i);
instru_t *get_tab_ins(champ_t *champion, corewar_t *core, instru_t *instru);
void zjmp(corewar_t *co, int i);
int init_tab_ins(champ_t *champion, corewar_t *core, instru_t *instru);
void fill_tab_ins(champ_t *champion, corewar_t *core, instru_t *instru);
void get_instruc(corewar_t *core, int i);
int what_type(char c, int dir_size);
int check_alive(corewar_t *core);
char *my_conver_base2(int nb, int size);
int *copy_int_star(int *memory, int *new, int *indice, int size);
int get_nb_prog(char **av);
int get_dump(char **av);
void get_all_champ(champ_t *champion);
int get_arg(int ac, char **av, corewar_t *C);
void recup_header(champ_t *champion, int fd);
void recup_core(champ_t *champion, int fd);

#endif /* my_corewar_ */