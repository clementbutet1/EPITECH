/*
** EPITECH PROJECT, 2019
** setenv_without_env.c
** File description:
** setenv_without_env.c
*/

#include "my.h"
#include "mysh.h"

int check_exit_cara_env_no_env(params_t *params, char *str,
char *scd_el, char **all_cmd)
{
    int i = 0;

    if ((str[0] >= '0' && str[0] <= '9')) {
        my_putstr(all_cmd[0]);
        my_putstr(": Variable name must begin with a letter.\n");
        return (11);
    }
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' &&
        str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            my_putstr(all_cmd[0]);
            my_putstr(": Variable name must contain alphanumeric ");
            my_putstr("characters.\n");
            return (11);
        }
        i++;
    }
    return (0);
}

int check_exit_setenv_no_env(params_t *params, char **all_cmd)
{
    if (all_cmd[1] == NULL && params->env.envi != NULL) {
        print_env(params, all_cmd);
        return (11);
    }
    if (all_cmd[3] != NULL || (all_cmd[1] != NULL &&
        all_cmd[2] == NULL))
        return (11);
    return (0);
}

char **different_env_no_env(char *fst_el, char *scd_el)
{
    char **new_envi2 = NULL;
    char *new_line = NULL;
    char *final_line = NULL;
    int ln = 0;
    int size_env = 0;

    new_envi2 = malloc(sizeof(char *) * 2);
    for (; ln != size_env + 1; ln++);
    ln--;
    new_line = my_strcat(fst_el, "=");
    final_line = my_strcat(new_line, scd_el);
    new_envi2[ln] = final_line;
    new_envi2[ln + 1] = NULL;
    return (new_envi2);
}

char **write_no_env(char *fst_el)
{
    char **new_envi2;
    char *new_line = my_strcat(fst_el, "=");
    int ln = 0;
    int size_env = 0;
    int size = my_strlen(new_line);
    int i = 0;

    new_envi2 = malloc(sizeof(char *) * (2));
    new_envi2[i] = malloc(sizeof(char) * size);
    new_envi2[i] = new_line;
    i++;
    new_envi2[i] = NULL;
    return (new_envi2);
}

void setenv_without_env(params_t *param, char **all_cmd)
{
    char *first_elem = all_cmd[1];
    char *scd_elem = all_cmd[2];

    if (all_cmd[1] != NULL && all_cmd[2] == NULL)
        param->env.envi = write_no_env(first_elem);
    if (check_exit_setenv_no_env(param, all_cmd) == 11)
        return;
    if (check_exit_cara_env_no_env(param, first_elem, scd_elem, all_cmd) == 11)
        return;
    if (check_same_env(param, first_elem, scd_elem) == 0)
        return;
    param->env.envi = different_env_no_env(first_elem, scd_elem);
}