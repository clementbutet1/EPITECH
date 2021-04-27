/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** foreach
*/

#include "mysh.h"

char **recup_arg(char **exe)
{
    char **str = NULL;
    int len = 0, k = 0;

    for (int i = 2; exe[i] != NULL; i++) {
        len++;
        if (exe[i + 1] == NULL) {
            if (exe[i][my_strlen(exe[i]) - 1] == ')')
                exe[i][my_strlen(exe[i]) - 1] = '\0';
            else
                exe[i - 1][my_strlen(exe[i - 1]) - 1] = '\0';
        }
    }
    for (int x = 0; exe[2][x] != '\0'; x++)
        exe[2][x] = exe[2][x + 1];
    str = malloc(sizeof(char *) * (len + 1));
    for (int i = 2; exe[i] != NULL; i++) {
        str[k] = exe[i];
        k++;
    }
    str[k] = NULL;
    return str;
}

char **add_com(char **com, char *arg)
{
    char **tmp = NULL;
    int i = 0;
    int j = 0;

    for (i = 0; com[i] != NULL; i++);
    tmp = malloc(sizeof(char *) * (i + 2));
    for (j = 0; com[j] != NULL; j++)
        tmp[j] = com[j];
    tmp[j] = arg;
    tmp[j + 1] = NULL;
    return tmp;
}

int is_var(char *com, char *var)
{
    if (com[0] == '$') {
        for (int i = 0; com[i] != '\0'; i++)
            com[i] = com[i + 1];
    }
    if (my_strcmp(com, my_strcat(var, "\n")) == 0)
        return 1;
    return 0;
}

void exec_foreach(char **arg, char **com, sh_t *sh, char *var)
{
    time_t now = 0;

    for (int i = 0; arg[i] != NULL; i++) {
        for (int j = 0; com[j] != NULL; j++) {
            if (is_var(com[j], var) == 1)
                sh->buffer = arg[i];
            else
                sh->buffer = com[j];
            check_buffer(sh, now);
        }
    }
    return;
}

void foreach(sh_t *sh, char **exe)
{
    char **arg = recup_arg(exe);
    char **com = NULL;
    char *var = exe[1];

    com = malloc(sizeof(char *) * 1);
    com[0] = NULL;
    while (1) {
        sh->buffer = NULL;
        sh->s = 0;
        my_putstr("foreach? ");
        if (getline(&sh->buffer, &sh->s, stdin) == -1)
            break;
        if (my_strcmp(sh->buffer, "end\n") == 0) {
            exec_foreach(arg, com, sh, var);
            break;
        }
        else if (my_strcmp(sh->buffer, "end\n") != 0)
            com = add_com(com, sh->buffer);
    }
    return;
}