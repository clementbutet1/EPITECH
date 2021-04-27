/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd_tiret.c
*/

#include "mysh.h"

void check_cd_tiret2(sh_t *sh)
{
    char *home = "OLDPWD=";
    int d = 0;
    int a = 0;
    int i = 0;

    for (; sh->path.env[d] != NULL; d++) {
        for (i = 0, a = 0; i < 7 && sh->path.env[d][i] != '\0'; i++) {
            if (sh->path.env[d][i] == home[i])
                a++;
        }
        if (a == 7)
            break;
    }
    if (sh->path.env[d] != NULL)
        sh->path.oldpwd = my_strdup(&sh->path.env[d][i]);
    else {
        sh->path.oldpwd = malloc(sizeof(char) * 1);
        sh->path.oldpwd[0] = '\0';
    }
}

void copy_string(sh_t *sh, char *str)
{
    int a = 0;

    for (int i = 0; sh->repertoire[i] != '\0'; i++) {
        if (sh->repertoire[i] == '~') {
            for (int g = 0; sh->path.home != NULL &&
            g != my_strlen(sh->path.home);
            g++, a++)
                str[a] = sh->path.home[g];
        }
        else {
            str[a] = sh->repertoire[i];
            a++;
        }
    }
    str[a] = '\0';
    free(sh->repertoire);
    sh->repertoire = str;
}

void verif_wave(sh_t *sh)
{
    char *str;
    int d = 0;
    int a = 0;

    for (int i = 0; sh->repertoire[i] != '\0'; i++) {
        if (sh->repertoire[i] == '~') {
            a++;
        }
    }
    if (a > 0) {
        find_main_directory(sh, 0);
        if (sh->path.home != NULL)
            d = (my_strlen(sh->path.home) - 1) * a + my_strlen(sh->repertoire);
        str = malloc(sizeof(char) * d + 1);
        for (int i = 0; i != d + 1; i++)
            str[i] = '\0';
        copy_string(sh, str);
    }
}

int check_cd_tiret(sh_t *sh)
{
    if (sh->repertoire[0] == '-') {
        for (int i = 1; sh->repertoire[i] != '\0'; i++) {
            if (sh->repertoire[i] != ' ' || sh->repertoire[i] != '-')
                return (0);
        }
        free(sh->repertoire);
        sh->repertoire = sh->path.oldpwd;
    }
    else
        verif_wave(sh);
    return (0);
}