/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_global.c
*/

#include "mysh.h"

char **combine_2_tab_indice(char **exe, glob_t g, int i)
{
    int a = 0;
    char **new_tab;

    for (; exe[a] != NULL; a++);
    a += g.gl_pathc;
    new_tab = malloc(sizeof(char *) * (a));
    for (a = 0; a < i; a++)
        new_tab[a] = exe[a];
    for (size_t c = 0; c < g.gl_pathc; c++, a++)
        new_tab[a] = g.gl_pathv[c];
    free(exe[i++]);
    for (; exe[i] != NULL; i++, a++)
        new_tab[a] = exe[i];
    new_tab[a] = NULL;
    free(exe);
    return (new_tab);
}

char **add_global_in_exe(char **exe, int i)
{
    glob_t g;

    glob(exe[i], 0, NULL, &g);
    exe = combine_2_tab_indice(exe, g, i);
    return (exe);
}

char **check_global(char **exe)
{
    for (int i = 0; exe[i] != NULL; i++) {
        for (int a = 0; exe[i][a] != '\0'; a++) {
            if (exe[i][a] == '*') {
                exe = add_global_in_exe(exe, i);
                a = -1;
            }
            if (exe[i] == NULL)
                return (exe);
        }
    }
    return (exe);
}