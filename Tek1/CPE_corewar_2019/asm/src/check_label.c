/*
** EPITECH PROJECT, 2019
** check_label.c
** File description:
** check_label.c
*/

#include "asm.h"

void change_label_to_nb2(instu_core_t *tmp, instu_core_t **instru,
params_t *params, int *cursor)
{
    int nb = 0;
    int line = 0;

    for (int d = 0; tmp->params[d] != -1; d++)
        if (tmp->params[d] == -2 && tmp->params[d + 1] != -2)
            nb++;
    for (int d = 0; d < nb; d++) {
        for (int i = 0; tmp->params[i] != -1; i++) {
            if (tmp->params[i] == -2) {
                line = find_line_labels(tmp, params, d);
                *cursor = change_int_params(tmp, instru, i, line);
            }
        }
    }
}

void change_label_to_nb(instu_core_t **instru, params_t *params)
{
    instu_core_t *tmp = *instru;

    for (; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; tmp->params[i] != -1; i++) {
            if (tmp->params[i] == -2)
                change_label_to_nb2(tmp, instru, params, &i);
        }
    }
    tmp = *instru;
}

int label_in_params(char *str, int i)
{
    char *label_c = LABEL_CHARS;
    int d = 0;
    int g = 0;

    for (int a = 0; label_c[a] != '\0' && d == 0; a++) {
        if (str[i - 1] == label_c[a] && str[i - 1] != DIRECT_CHAR)
            d = 1;
        if (str[i + 1] == label_c[a])
            g = 1;
    }
    if (g == 1 && d == 0)
        return (1);
    return (0);
}

int find_line(char *str, params_t *params)
{
    int i = 0;
    char *st;

    for (; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'
    && str[i] != SEPARATOR_CHAR; i++);
    st = my_strncpy(str, i);
    for (int a = 0; params->label[a] != NULL; a++) {
        if (my_strcmp(params->label[a], st) == 0) {
            return (params->line[a]);
        }
    }
    my_putstr_error("Error : bad label");
    return (0);
}

int find_line_labels(instu_core_t *tmp, params_t *params, int number)
{
    for (int i = 0, nb = 0; tmp->str[i] != '\0'; i++) {
        if (tmp->str[i] == LABEL_CHAR && label_in_params(tmp->str, i) == 1
            && nb == number)
            return (find_line(&tmp->str[i + 1], params));
        if (tmp->str[i] == LABEL_CHAR && label_in_params(tmp->str, i) == 1
            && nb != number)
            nb++;
    }
    my_putstr_error("Error : bad label");
    return (0);
}