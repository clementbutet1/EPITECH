/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** create_alias_tab.c
*/

#include "mysh.h"
#include "my.h"

void print_alias_tab(sh_t *sh)
{
    for (int y = 0; sh->alias.alias[y] != NULL; y++) {
        my_putstr(sh->alias.alias[y]);
        my_putchar('\n');
    }
}

void create_alias_tab(sh_t *sh)
{
    sh->alias.height = 0;
    sh->alias.width = 100;
    sh->alias.alias = malloc(sizeof(char *) * (sh->alias.height + 1));
    for (int i = 0; i != sh->alias.height + 1; i++) {
        sh->alias.alias[i] = malloc(sizeof(char) * (sh->alias.width + 1));
    }
    sh->alias.alias[0] = NULL;
}

void free_alias_tab(sh_t *sh)
{
    for (int y = 0; sh->alias.alias[y] != NULL; y++) {
        free(sh->alias.alias[y]);
    }
    free(sh->alias.alias);
}