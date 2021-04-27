/*
** EPITECH PROJECT, 2019
** signal.c
** File description:
** signal.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

int signal_player_two(int ac, char **av, params_t *params, char **map_vide)
{
    int pid = 0;

    if (ac == 3) {
        params->enemy_pid = getpid();
        my_putstr("my_pid: ");
        my_put_nbr(params->enemy_pid);
        pid = my_getnbr(av[1]);
        if (kill(pid, SIGUSR1) == -1) {
            my_putstr("bad pid");
            exit_error;
        }
        my_putstr("\nsuccessfully connected\n\n");
        if (execute_all_funct_player2(params, av, map_vide) == 84)
            return (84);
    }
    return (0);
}

int singleton(int info)
{
    static int pid;

    if (info != -1)
        pid = info;
    return pid;
}

void pid_usr(int i, siginfo_t *info, void *contexte)
{
    singleton(info->si_pid);
}

int signal_player_one(int ac, char **av, params_t *params, char **map_vide)
{
    struct sigaction act;

    if (ac == 2) {
        params->my_pid = getpid();
        my_putstr("my_pid: ");
        my_put_nbr(params->my_pid);
        my_putstr("\nwaiting for enemy connection...\n");
        act.sa_sigaction = &pid_usr;
        sigemptyset(&act.sa_mask);
        act.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &act, NULL);
        pause();
        my_putstr("\nenemy connected\n\n");
        if (execute_all_funct_player1(params, av, map_vide) == 84)
            return (84);
    } else
        signal_player_two(ac, av, params, map_vide);
    return (0);
}