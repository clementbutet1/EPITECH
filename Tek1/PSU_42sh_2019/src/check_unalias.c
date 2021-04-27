/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_unalias.c
*/

#include "mysh.h"

void modif_alias2_rm(char **exe, sh_t *sh)
{
    int line = check_alias_name(exe[1], sh);
    int y = line;

    while (sh->alias.alias[y] != NULL) {
        sh->alias.alias[y] = sh->alias.alias[y + 1];
        y++;
    }
    sh->alias.alias[y] = NULL;
    sh->alias.height--;
}

void modif_alias_rm(char **exe, sh_t *sh)
{
    int i = 0;

    while (exe[i] != NULL)
        i++;
    if (i < 2) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("unalias: Too few arguments.\n");
    } else
        modif_alias2_rm(exe, sh);
}

int check_unalias(char **exe, sh_t *sh)
{
    char *unalias = "unalias";
    int a = 0;
    int i = 0;

    for (; i < 7 && exe[0][i] != '\0'; i++) {
        if (exe[0][i] == unalias[i])
            a++;
        else
            return (0);
    }
    if (exe[0][i] != ' ' && exe[0][i] != '\0')
        return (0);
    if (a == 7)
        modif_alias_rm(exe, sh);
    return (1);
}