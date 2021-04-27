/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** navy.h
*/

#ifndef my_navy_h_
#define my_navy_h_
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
#define exit_error __asm__("movq $60, %rax\nmovq $84, %rdi\nsyscall");
#define exit_win __asm__("movq $60, %rax\nmovq $0, %rdi\nsyscall");
#define exit_loose __asm__("movq $60, %rax\nmovq $1, %rdi\nsyscall");
#include <fcntl.h>
#include <string.h>
#include <getopt.h>
#include <signal.h>

typedef struct params
{
    int game;
    int loose;
    int enemy_pid;
    int my_pid;
    int cpt_win_play1;
    int cpt_win_player2;
    char *cmd;
    char **pos;
    char **map;
    char **pos_player1;
    char **map_vide;
    struct sigaction act;
}params_t;

typedef struct error
{
    int a;
    int b;
    int c;
    int d;
}error_t;

typedef struct values
{
    int scd_val;
    int frst_val;
}values_t;

typedef struct boat_error
{
    int boat1;
    int boat2;
    int boat3;
    int boat4;
}boat_error_t;

int check_same_pos_for_boat(char **pos, params_t *params);
char **put_attack(char **map_pos, int scd_val, int frst_val, params_t *params);
char **ck_attack2(char **map_pos, int scd_val, int frst_val, params_t *params);
char **ck_attack1(char **map_pos, int scd_val, int frst_val, params_t *params);
int check_pos_boat(params_t *params);
void boucle_inf_for_player2(params_t *params, char **av, char **mapvd);
void boucle_inf_for_player1(params_t *params, char **av, char **mapvd);
int check_victory_player1(params_t *params);
char **put_attack(char **map_pos, int scd_val, int frst_val, params_t *params);
char check_nb(params_t *params, int c);
char check_nb2(params_t *params, char values, int c);
char *my_convertbinaire(unsigned int nb);
int singleton(int info);
int check_victory(params_t *params, int player);
char **ck_attack(char **map_pos, int scd_val, int frst_val, params_t *params);
values_t check_enter_other_play(params_t *params, char **map_pos);
int convert_bin_int(char *str);
char *my_convert_bin(int nb);
int recup_signal_other(void);
void send_signal(int pid, int entry);
int execute_all_funct_player2(params_t *params, char **av, char **mapvd);
int execute_all_funct_player1(params_t *params, char **av, char **mapvd);
int signal_player_one(int ac, char **av, params_t *params, char **map_vide);
int init_player_turn(params_t *params, int ac, char **av, char **map_vide);
char **copy_map(params_t *params, char **map);
int check_cmd(char *cmd);
void print_map(char **map);
char **put_boat(params_t *params, char **pos);
void recup_all_boat(params_t *params);
void print_boat_position(params_t *params);
int check_enter(char *cmd);
int check_error_on_line(char **pos, params_t *params);
int check_letter2(params_t *params, int values, char c);
int check_letter(params_t *params, char c);
int recup_signal(params_t *params, int ac , char **av);
int check_entry_player_size_boat(char **pos);
void create_map(params_t *params);
void execute_all_funct(params_t *params, int ac, char **av);
int prepare_size_map(params_t *params);
char **open_read(char *filename, params_t *params);
int count_column(char *buffer);
int count_line(char *buffer);
void recup_all_boat(params_t *params);
void display_help(void);
char **recup_coord_boat(params_t *params);
char **remove_boat_from_map(params_t *params, char **map_pos, int cpt);

#endif /* my_navy_ */