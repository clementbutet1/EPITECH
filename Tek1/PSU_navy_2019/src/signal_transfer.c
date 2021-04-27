/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

char *global;

void sighandler(int sig, siginfo_t *info, void *contexte)
{
    static int x;

    if (sig == SIGUSR1)
        global[x] = '1';
    if (sig == SIGUSR2)
        global[x] = '0';
    x++;
    if (x == 4)
        x = 0;
}

char *cp_buffer(void)
{
    char *rslt = NULL;
    rslt = malloc(sizeof(char *) * (5));
    rslt = my_strdup(global);

    return (rslt);
}

int recup_signal_other(void)
{
    struct sigaction act;
    int nb = 0;
    global = malloc(sizeof(char *) * 5);
    global[4] = '\0';
    char *rslt = NULL;
    int b = 0;

    act.sa_sigaction = &sighandler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &act, NULL);
    sigaction(SIGUSR1, &act, NULL);
    while (nb < 4) {
        pause();
        nb++;
    }
    rslt = cp_buffer();
    b = convert_bin_int(rslt);
    return (b);
}

void send_signal(int pid, int entry)
{
    char *str = NULL;
    usleep(200000);

    str = my_convert_bin(entry);
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == '0') {
            kill(pid, SIGUSR2);
            usleep(3000);
        } else {
            kill(pid, SIGUSR1);
            usleep(3000);
        }
    }
}