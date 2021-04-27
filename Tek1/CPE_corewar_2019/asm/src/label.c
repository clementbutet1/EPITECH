/*
** EPITECH PROJECT, 2019
** label.c
** File description:
** label.c
*/

#include "asm.h"

int label_conposed_of_label_chars(char *str, int i)
{
    char *label_c = LABEL_CHARS;

    error_label(str, i + 1, label_c);
    for (int d = 0, len = i; i >= 0; i--) {
        for (int a = 0; label_c[a] != '\0' && d == 0; a++)
            if (str[i] == label_c[a])
                d = 1;
        if (i == len && d == 0)
            return (1);
        if (d == 0) {
            my_putstr_error("Error : Invalid char for the label");
            exit (84);
        }
        d = 0;
    }
    return (0);
}

char **add_label(char *str, int i, char **label)
{
    char **new_tab = malloc(sizeof(char *) * (my_strlen_tab(label) + 2));
    int a = 0;

    str[i] = '\0';
    for (; label[a] != NULL; a++)
        if (my_strcmp(str, label[a]) == 0)
            my_putstr_error("Error : Multiple definition");
    for (a = 0; label[a] != NULL; a++)
        new_tab[a] = label[a];
    new_tab[a++] = my_strdup(str);
    free(str);
    free(label);
    new_tab[a] = NULL;
    return (new_tab);
}

void add_if_label(char *str, params_t *pa, int line)
{
    int *tab = malloc(sizeof(int) * 2);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == LABEL_CHAR && label_conposed_of_label_chars(str, i - 1)
        == 0) {
            tab[0] = line;
            tab[1] = -1;
            pa->line = add_two_tab_int(pa->line, tab);
            pa->label = add_label(my_strdup(str), i, pa->label);
        }
    }
    return;
}

void get_all_label(char **file, params_t *pa)
{
    for (int i = 2; file[i] != NULL; i++) {
        add_if_label(file[i], pa, i);
    }
    return;
}