/*
** EPITECH PROJECT, 2019
** check_unset.c
** File description:
** check_unset.c
*/

#include "mysh.h"

int check_same_begin(char *elem_env, char *entry)
{
    int i = 0;
    int size = my_strlen(entry);
    int cpt = 0;

    while (elem_env[i] != '\t') {
        if (elem_env[i] == entry[i])
            cpt++;
        else if (elem_env[i] != '\0' || entry[i] != '\0')
            return (0);
        i++;
    }
    if (cpt == size)
        return (11);
    else
        return (0);
}

int execute_unset(sh_t *sh, char **all_cmd)
{
    char *element = all_cmd[1];
    char **new_envi = NULL;
    int j = 0;
    int size = 0;

    for (; sh->set[size] != NULL; size++);
    new_envi = malloc(sizeof(char *) * size + 2);
    for (int i = 0; sh->set[i] != NULL; i++, j++) {
        if (check_same_begin(sh->set[i], element) == 11) {
            sh->set[i] = 0;
            i++;
        }
        new_envi[j] = sh->set[i];
    }
    sh->set = NULL;
    sh->set = new_envi;
    return (1);
}

int check_unset(char **exe, sh_t *sh, char *name_cmd)
{
    if (my_strcmp(name_cmd, exe[0]) != 0)
        return (0);
    if (sh->set == NULL)
        return (1);
    if (exe[2] != NULL)
        return (1);
    if (exe[1] == NULL) {
        my_putstr("unset: Too few arguments.\n");
        return (1);
    }
    if (sh->parenth == 1)
        return (0);
    return (execute_unset(sh, exe));
}