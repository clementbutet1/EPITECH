/*
** EPITECH PROJECT, 2019
** opt_funct.c
** File description:
** opt_funct.c
*/

#include "../include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include"../include/mysh.h"

int check_entry(char *cmd)
{
    int cpt = 0;
    int k = 0;

    for (; cmd[k] != '\0'; k++) {
        if (cmd == NULL || cmd[0] == '\n')
            return (1);
    }
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (check_cara(cmd[i]) == 1)
            return (0);
        if (cmd[i] == ' ')
            cpt++;
    }
    if (cpt == (k - 1)) {
        return (1);
    }
    return (0);
}

char *check_final(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == '\0')
            str[i] = '\0';
    }
    return (str);
}

int check_cara(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
    (c >= '0' && c <= '9' || c == '/' || c == '.' || c == '~' ||
    c == '-' || c == '_')) {
        return (1);
    }
    return (0);
}

char *clean_str(char *str, params_t *params)
{
    int size = my_strlen(str);
    char *rslt = malloc(sizeof(char *) * size + 2);
    int k = 0;
    int i = check_begin_space(str, k);
    str = check_end_space(str);
    int j = 0;

    for (; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' || str[i] == '\t') {
            rslt[j] = ' ';
            i = check_begin_space(str, i);
            j++;
        }
        rslt[j] = str[i];
    }
    rslt[j] = '\0';
    rslt = check_final(rslt);
    return (rslt);
}