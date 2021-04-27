/*
** EPITECH PROJECT, 2019
** env_prog.c
** File description:
** env_prog.c
*/

#include "my.h"
#include"mysh.h"

void free_and_put_nul(params_t *params, char *fst_el, int ln)
{
    int i = 0;
    int save = 0;
    int size = 0;
    char *new_path = NULL;

    for (; fst_el[i] == params->env.envi[ln][i]; i++);
    i++;
    save = i;
    for (; params->env.envi[ln][i] != '\0'; i++)
        params->env.envi[ln][i] = 0;
    new_path = my_strcat(fst_el, "=");
    params->env.envi[ln] = NULL;
    params->env.envi[ln] = new_path;
}

char **write_one_element(params_t *params, char **tab, char *fst_el, int i)
{
    char **new_envi2;
    char *new_line = my_strcat(fst_el, "=");
    int size_env = 0;
    int size = my_strlen(new_line);

    for (int i = 0; params->env.envi[i] != NULL; i++)
        if (check_same_begin(params->env.envi[i], fst_el) == 11) {
            free_and_put_nul(params, fst_el, i);
            return (params->env.envi);
        }
    for (; tab[size_env] != NULL; size_env++);
    new_envi2 = malloc(sizeof(char *) * (size_env + 3));
    for (; i != size_env; i++)
        new_envi2[i] = my_strdup(tab[i]);
    new_envi2[i] = malloc(sizeof(char) * size);
    new_envi2[i] = new_line;
    i++;
    new_envi2[i] = NULL;
    return (new_envi2);
}