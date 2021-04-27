/*
** EPITECH PROJECT, 2019
** history.c
** File description:
** history.c
*/

#include "mysh.h"

char **add_element_into_hist(sh_t *sh, char *buffer)
{
    char **tb = NULL;
    tb = sh->hist.history;
    char *new_line = NULL;
    int ln = 0;
    int size_tab = 0;

    for (; sh->hist.history[size_tab] != NULL; size_tab++);
    tb = malloc(sizeof(char *) * (size_tab + 4));
    for (int i = 0; i != size_tab; i++)
        tb[i] = my_strdup(sh->hist.history[i]);
    for (; ln != size_tab + 1; ln++);
    ln--;
    new_line = my_strdup(buffer);
    tb[ln] = new_line;
    tb[ln + 1] = NULL;
    return (tb);
}

char **add_element_into_min(sh_t *sh, char *buffer)
{
    char **tb = sh->hist.min;
    char *new_line = NULL;
    int ln = 0;
    int size_tab = 0;

    for (; sh->hist.min[size_tab] != NULL; size_tab++);
    tb = malloc(sizeof(char *) * (size_tab + 4));
    for (int i = 0; i != size_tab; i++)
        tb[i] = my_strdup(sh->hist.min[i]);
    for (; ln != size_tab + 1; ln++);
    ln--;
    new_line = my_strdup(buffer);
    tb[ln] = new_line;
    tb[ln + 1] = NULL;
    return (tb);
}

char **add_element_into_h(sh_t *sh, char *buffer)
{
    char **tb = sh->hist.h;
    char *new_line = NULL;
    int ln = 0;
    int size_tab = 0;

    for (; sh->hist.h[size_tab] != NULL; size_tab++);
    tb = malloc(sizeof(char *) * (size_tab + 4));
    for (int i = 0; i != size_tab; i++)
        tb[i] = my_strdup(sh->hist.h[i]);
    for (; ln != size_tab + 1; ln++);
    ln--;
    new_line = my_strdup(buffer);
    tb[ln] = my_strdup(new_line);
    tb[ln + 1] = NULL;
    return (tb);
}

char **write_no_env(char *fst_el)
{
    char **new_envi2;
    char *new_line = my_strdup(fst_el);
    int size = my_strlen(new_line);
    int i = 0;

    new_envi2 = malloc(sizeof(char *) * (2));
    new_envi2[i] = malloc(sizeof(char) * size);
    new_envi2[i] = new_line;
    i++;
    new_envi2[i] = NULL;
    return (new_envi2);
}

int create_history_tab(sh_t *sh, time_t now)
{
    now = time(NULL);
    struct tm *local = localtime(&now);
    char *h = my_itoa(local->tm_hour);
    char *min = my_itoa(local->tm_min);

    if (sh->buffer[0] == '\0')
        return (0);
    if (sh->hist.history == NULL) {
        sh->hist.history = write_no_env(sh->buffer);
        sh->hist.min = write_no_env(min);
        sh->hist.h = write_no_env(h);
    } else {
        sh->hist.history = add_element_into_hist(sh, sh->buffer);
        sh->hist.min = add_element_into_min(sh, min);
        sh->hist.h = add_element_into_h(sh, h);
    }
    return (0);
}