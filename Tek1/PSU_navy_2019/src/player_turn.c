/*
** EPITECH PROJECT, 2019
** player_turn.c
** File description:
** player_turn.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

void print_nb(values_t *values, params_t *params)
{
    my_putchar(check_nb(params, (values->frst_val += 2)));
    my_put_nbr(values->scd_val);
    values->scd_val++;
}

void recup_signal_player2(params_t *param, values_t *values, char **av)
{
    usleep(3000);
    my_putchar('\n');
    *values = check_enter_other_play(param, param->pos_player1);
    send_signal(my_getnbr(av[1]), values->frst_val);
    send_signal(my_getnbr(av[1]), values->scd_val);
    usleep(3000);
    print_nb(values, param);
    param->game = recup_signal_other();
    (param->game == 2) ? my_putstr(": hit\n") : my_putstr(": missed\n");
    (param->game == 2) ? param->cpt_win_player2 += 1 : param->cpt_win_player2;
    my_putstr("\n\nmy_positions:\n");
    print_map(param->pos_player1);
    my_putstr("\nenemy's positions:\n");
    param->map_vide = put_attack(param->pos_player1,
    values->scd_val, values->frst_val, param);
    print_map(param->map_vide);
    check_victory(param, 2);
}

void boucle_inf_for_player2(params_t *param, char **av, char **mapvd)
{
    values_t values;
    int jeu = 0;

    while (param->loose == 0) {
        my_putstr("\n\nwaiting for enemy's attack...\n");
        values.frst_val = recup_signal_other();
        values.frst_val += 2;
        values.scd_val = recup_signal_other();
        my_putchar(check_nb(param, (values.frst_val)));
        my_put_nbr(values.scd_val);
        values.scd_val++;
        param->pos_player1 = ck_attack2(param->pos_player1,
        values.scd_val, values.frst_val, param);
        (param->game == 2) ? my_putstr(": hit") : my_putstr(": missed");
        (param->game == 2) ? param->cpt_win_play1 += 1 : param->cpt_win_play1;
        send_signal(my_getnbr(av[1]), param->game);
        usleep(3000);
        recup_signal_player2(param, &values, av);
        check_victory(param, 2);
    }
}

void recup_signal_player1(params_t *param, values_t *values, int pid,
char **mapvd)
{
    my_putstr("\nwaiting for enemy's attack...");
    values->frst_val = recup_signal_other();
    values->frst_val += 2;
    values->scd_val = recup_signal_other();
    my_putchar('\n');
    my_putchar(check_nb(param, (values->frst_val)));
    my_put_nbr(values->scd_val);
    values->scd_val++;
    param->pos_player1 = ck_attack1(param->pos_player1, values->scd_val,
    values->frst_val, param);
    (param->game == 2) ? my_putstr(": hit\n") : my_putstr(": missed\n");
    (param->game == 2) ? param->cpt_win_player2 += 1 : param->cpt_win_player2;
    send_signal(pid, param->game);
    usleep(3000);
    my_putstr("\nmy_positions:\n");
    print_map(param->pos_player1);
    my_putstr("\nenemy's positions:\n");
    print_map(mapvd);
    check_victory(param, 1);
}

void boucle_inf_for_player1(params_t *param, char **av, char **mapvd)
{
    values_t values;
    int pid = singleton(-1);

    while (param->loose == 0) {
        values = check_enter_other_play(param, param->pos_player1);
        send_signal(pid, values.frst_val);
        send_signal(pid, values.scd_val);
        usleep(3000);
        print_nb(&values, param);
        param->game = recup_signal_other();
        (param->game == 2) ? my_putstr(": hit\n") : my_putstr(": missed\n");
        (param->game == 2) ? param->cpt_win_play1 += 1 : param->cpt_win_play1;
        mapvd = put_attack(param->pos_player1,
        values.scd_val, values.frst_val, param);
        recup_signal_player1(param, &values, pid, mapvd);
        check_victory(param, 1);
    }
}