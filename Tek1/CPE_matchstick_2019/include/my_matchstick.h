/*
** EPITECH PROJECT, 2019
** my_matchstick.h
** File description:
** my_matchstick.h
*/

#include "my.h"
#include <stddef.h>
#ifndef MY_MATCHSTICK_H
#define MY_MATCHSTICK_H
#define out_game __asm__("movq $60, %rax\nmovq $0, %rdi\nsyscall");
#define out_game1 __asm__("movq $60, %rax\nmovq $1, %rdi\nsyscall");
#define out_game2 __asm__("movq $60, %rax\nmovq $2, %rdi\nsyscall");

typedef struct params
{
    int size_height;
    int size_large;
    int nb_max_stick;
    char **map;
    char *line;
    int entry_player_l;
    int entry_player_m;
}params_t;

typedef struct ia_params
{
    int *tab;
    int size_height;
    int size_large;
    int nb_max_stick;
    int entry_ia_l;
    int entry_ia_m;
    int nb_stick;
    int nb_total_stick;
    int max_stick_per_line;
}ia_params_t;

void check_nb_stick(params_t *params, ia_params_t *ia_params);
void check_size_map(params_t *params);
void create_map(params_t *params);
void add_outline(params_t *params);
void print_map(params_t *params);
int check_positiv(int nb);
int check_nb(char *str);
int check_size_l(params_t *params);
int check_size_m(params_t *params);
int recup_player_entry_m(params_t *params);
void print_removed(params_t *params);
void remove_pipe(params_t *params);
int check_map_empty(params_t *params);
void check_pipe_line(params_t *params);
void check_out_game_l(params_t *params);
int recup_player_entry_l(params_t *params);
void ia_turn(params_t *params);
void ia_turn_init_strcut(params_t *params);
void ia_print(params_t *params, ia_params_t *ia_params);
void remove_pipe_for_ia(params_t *params, ia_params_t *ia_params);
void check_max_stick(params_t *params, ia_params_t *ia_params);
void xor_tab_simple(params_t *params, ia_params_t *ia_params);


#endif /* my_matchstick_h */