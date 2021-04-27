/*
** EPITECH PROJECT, 2019
** setenv.c
** File description:
** setenv.c
*/

#include "my.h"
#include "mysh.h"

void free_and_replace(params_t *params, char *fst_el, char *scd_el, int ln)
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
    new_path = my_strcat(params->env.envi[ln], scd_el);
    params->env.envi[ln] = NULL;
    params->env.envi[ln] = new_path;
}

int check_same_env(params_t *params, char *fst_el, char *scd_el)
{
    int j = 0;

    if (params->env.envi == NULL)
        return (11);
    for (int i = 0; params->env.envi[i] != NULL; i++, j++) {
        if (check_same_begin(params->env.envi[i], fst_el) == 11) {
            free_and_replace(params, fst_el, scd_el, i);
            return (0);
        }
    }
    return (11);
}

int check_exit_setenv(params_t *params, char **all_cmd)
{
    if (all_cmd[1] == NULL) {
        print_env(params, all_cmd);
        return (11);
    }
    if (all_cmd[3] != NULL || (all_cmd[1] != NULL &&
        all_cmd[2] == NULL))
        return (11);
    return (0);
}

void different_env(params_t *params, char *fst_el, char *scd_el)
{
    char **new_envi2 = params->env.envi;
    char *new_line = NULL;
    char *final_line = NULL;
    int ln = 0;
    int size_env = 0;

    for (; params->env.envi[size_env] != NULL; size_env++);
    new_envi2 = malloc(sizeof(char *) * size_env + 4);
    for (int i = 0; i != size_env; i++)
        new_envi2[i] = my_strdup(params->env.envi[i]);
    for (; ln != size_env + 1; ln++);
    ln--;
    new_line = my_strcat(fst_el, "=");
    final_line = my_strcat(new_line, scd_el);
    new_envi2[ln] = final_line;
    new_envi2[ln + 1] = NULL;
    params->env.envi = NULL;
    params->env.envi = new_envi2;
    return;
}

void setenv_funct(params_t *params, char **all_cmd)
{
    char *first_elem = all_cmd[1];
    char *scd_elem = all_cmd[2];
    int i = 0;

    if (params->env.envi == NULL)
        setenv_without_env(params, all_cmd);
    if (all_cmd[1] != NULL && all_cmd[2] == NULL)
        params->env.envi = write_one_element
        (params, params->env.envi, first_elem, i);
    if (check_exit_setenv(params, all_cmd) == 11)
        return;
    if (check_exit_cara_env(params, first_elem, scd_elem) == 11)
        return;
    if (check_same_env(params, first_elem, scd_elem) == 0)
        return;
    different_env(params, first_elem, scd_elem);
    return;
}
