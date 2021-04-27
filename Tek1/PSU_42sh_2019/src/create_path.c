/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** create_path.c
*/

#include "mysh.h"

void create_all_path2(sh_t *sh, int q)
{
    int c = 0;
    int d = 0;

    for (int i = q; sh->path.line_path[i] != 0; i++, c++) {
        if (sh->path.line_path[i] == ':') {
            sh->path.path[d++][c] = '\0';
            sh->path.path[d] = &sh->path.line_path[i + 1];
            c = -1;
        }
    }
    sh->path.path[d++][c] = '\0';
    sh->path.path[d] = NULL;
    for (int i = 0; sh->path.path[i] != NULL; i++) {
        sh->path.path[i] = my_strdup(sh->path.path[i]);
    }
}

void create_all_path(sh_t *sh, int q)
{
    int d = 0;

    if (sh->path.line_path != NULL) {
        for (int i = 0; sh->path.line_path[i] != '\0' &&
        sh->path.line_path[i] != '\n'; i++) {
            if (sh->path.line_path[i] == ':')
                d++;
        }
    }
    if ((sh->path.line_path == NULL && sh->taille_env < 0) ||
    sh->path.line_path != NULL) {
        sh->path.path = malloc(sizeof(char *) * (d + 2));
        for (int s = 0; s < d + 2; s++)
            sh->path.path[s] = NULL;
        if (sh->path.line_path != NULL) {
            sh->path.path[0] = &sh->path.line_path[q];
            create_all_path2(sh, q);
        }
    }
}

void remp_path(sh_t *sh, int a, int d)
{
    if (a == 5) {
        sh->path.line_path = my_strdup(sh->path.env[d]);
    } else {
        sh->path.line_path = my_strdup
        ("PATH=/usr/local/sbin:/usr/local/bin:/usr/");
        sh->path.line_path = my_strcat
        (sh->path.line_path, "sbin:/usr/bin:/sbin:/bin:");
        sh->path.line_path = my_strcat
        (sh->path.line_path, "/root/.dotnet/tools");
    }
}

int find_path(sh_t *sh)
{
    char *path = "PATH=";
    int d = 0;
    int a = 0;
    int i = 0;

    for (; sh->path.env[d] != NULL; d++) {
        for (i = 0, a = 0; i < 5 && sh->path.env[d][i] != '\0'; i++) {
            if (sh->path.env[d][i] == path[i])
                a++;
        }
        if (a == 5)
            break;
    }
    sh->path.line_path = NULL;
    remp_path(sh, a, d);
    create_all_path(sh, i);
    return (0);
}