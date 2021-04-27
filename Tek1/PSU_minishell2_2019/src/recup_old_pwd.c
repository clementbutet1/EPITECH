/*
** EPITECH PROJECT, 2019
** recup_old_pwd.c
** File description:
** recup_old_pwd.c
*/

#include "my.h"
#include "mysh.h"

char **create_tab_old_pwd(char **tab)
{
    tab = malloc(sizeof(char *) * 2);
    tab[0] = malloc(sizeof(char) * 8);
    tab[0] = "OLDPWD=";
    tab[1] = NULL;
    return (tab);
}

int get_line_old_pwd_special_tab(params_t *params)
{
    params->env.old_pwd = 0;

    for (int i = 0; params->env.tab_old_pwd[i] != NULL; i++) {
        if (params->env.tab_old_pwd[i][0] == 'O' &&
        params->env.tab_old_pwd[i][1] == 'L' &&
        params->env.tab_old_pwd[i][2] == 'D' &&
        params->env.tab_old_pwd[i][3] == 'P' &&
        params->env.tab_old_pwd[i][4] == 'W' &&
        params->env.tab_old_pwd[i][5] == 'D') {
            params->env.old_pwd = i;
            params->env.newstr_old_pwd = get_the_path
            (params->env.tab_old_pwd[i], params);
        }
    }
    return (0);
}

void replace_old_pwd(params_t *params, char *fst_el, char *scd_el, int ln)
{
    int i = 0;
    int save = 0;
    int size = 0;
    char *new_path = NULL;

    for (; fst_el[i] == params->env.tab_old_pwd[ln][i]; i++);
    i++;
    save = i;
    for (; params->env.tab_old_pwd[ln][i] != '\0'; i++)
        params->env.tab_old_pwd[ln][i] = 0;
    new_path = my_strcat(params->env.tab_old_pwd[ln], scd_el);
    params->env.tab_old_pwd[ln] = NULL;
    params->env.tab_old_pwd[ln] = new_path;
}

int check_same_old_pwd(params_t *params, char *fst_el, char *scd_el)
{
    int j = 0;

    for (int i = 0; params->env.tab_old_pwd[i] != NULL; i++, j++) {
        if (check_same_begin(params->env.tab_old_pwd[i], fst_el) == 11) {
            replace_old_pwd(params, fst_el, scd_el, i);
            return (0);
        }
    }
    return (11);
}