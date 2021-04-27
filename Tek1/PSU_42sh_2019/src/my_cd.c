/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_cd.c
*/

#include "mysh.h"

int error_find_main(sh_t *sh, int s)
{
    if (sh->path.home == NULL && s == 1) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("cd: No home directory.\n");
        return (3);
    }
    return (2);
}

int find_main_directory(sh_t *sh, int s)
{
    char *home = "HOME=";
    int d = 0;
    int a = 0;
    int i = 0;

    for (; sh->path.env[d] != NULL; d++) {
        for (i = 0, a = 0; i < 5 && sh->path.env[d][i] != '\0'; i++) {
            if (sh->path.env[d][i] == home[i])
                a++;
        }
        if (a == 5)
            break;
    }
    if (a < 5) {
        return (error_find_main(sh, s));
    }
    sh->path.home = my_strdup(&sh->path.env[d][i]);
    return (2);
}

int check_cd(char **exe, sh_t *sh)
{
    char *cd = "cd";
    int i = 0;
    int a = 0;

    for (; i < 2 && exe[0][i] != '\0'; i++) {
        if (exe[0][i] == cd[i])
            a++;
        else
            return (0);
    }
    if (exe[0][i] != '\0' || a < 2)
        return (0);
    if (exe[1] == NULL)
        return (find_main_directory(sh, 1));
    else
        sh->repertoire = my_strdup(exe[1]);
    check_cd_tiret(sh);
    return (1);
}

void my_cd2(char *chemin, sh_t *sh)
{
    int d = 0;

    if ((d = chdir(chemin)) == -1) {
        strerror(d);
        my_putstr_error(chemin);
        switch (errno) {
        case EACCES:
            if (execute_double_pipe(sh) != 1)
                my_putstr_error(": Permission denied.\n");
            break;
        case ENOTDIR:
            if (execute_double_pipe(sh) != 1)
                my_putstr_error(": Not a directory.\n");
            break;
        case ENOENT:
            if (execute_double_pipe(sh) != 1)
                my_putstr_error(": No such file or directory.\n");
            break;
        }
    }
}

void my_cd(char **exe, sh_t *sh, int cas)
{
    char s[256];

    s[0] = 0x0;
    getcwd(s, 100);
    sh->path.oldpwd = my_strdup(s);
    if (cas == 1) {
        if (exe[2] != NULL) {
            if (execute_double_pipe(sh) != 1)
                my_putstr_error("cd: Too many arguments.\n");
        } else
            my_cd2(sh->repertoire, sh);
    }
    else {
        my_cd2(sh->path.home, sh);
    }
    s[0] = 0x0;
    getcwd(s, 100);
    replace_env(sh, my_strdup(s), "PWD=");
}