/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** clean_file.c
*/

#include "asm.h"

int find_only_a_label3(char *str)
{
    int d = 0;
    int a = 0;

    for (int a = 0; str[a] != '\0' && d == 0; a++)
        if (str[a] == LABEL_CHAR)
            d = a + 1;
    if (d > 0 && label_conposed_of_label_chars(str, d - 2) == 0) {
        for (a = d; str[a] != '\0' && str[a] != '\n'; a++)
            if (str[a] != ' ')
                return (0);
        str[d] = ' ';
        str[d + 1] = '\0';
        return (1);
    }
    return (0);
}

char **find_only_label2(char **file, int a, int *i, params_t *pa)
{
    int *tab = malloc(sizeof(int) * 2);
    int g = 0;

    if (find_only_a_label3(file[*i]) == 1 &&
        file[*i + 1] == NULL)
        my_putstr_error("Error : label without instruction");
    if (find_only_a_label3(file[*i]) == 1 &&
        find_only_a_label3(file[*i + 1]) == 1)
        my_putstr_error("Error : label without instruction");
    if (find_only_a_label3(file[*i]) == 1) {
        tab[0] = a;
        tab[1] = -1;
        pa->line = add_two_tab_int(pa->line, tab);
        for (int f = 0; file[*i][f] != '\0' && file[*i][f] != '\n' &&
        file[*i][f] != LABEL_CHAR; g++, f++);
        pa->label = add_label(file[*i], g, pa->label);
        file[a] = file[*i + 1];
        *i += 1;
    }
    return (file);
}

char **find_only_label(char **file, params_t *pa)
{
    int a = 0;
    char **new_tab;

    for (int i = 0; file[i] != NULL; i++, a++) {
        file[a] = file[i];
        file = find_only_label2(file, a, &i, pa);
    }
    file[a] = NULL;
    new_tab = malloc(sizeof(char *) * (a + 1));
    for (int i = 0; file[i] != NULL; i++)
        new_tab[i] = file[i];
    new_tab[a] = NULL;
    return (new_tab);
}

char **clean_file(char **file, params_t *pa)
{
    int a = 0;
    char **new_tab;

    init_struct_clean_file(pa);
    for (int i = 0; file[i] != NULL; i++)
        file[i] = clean_str(file[i]);
    for (int i = 0; file[i] != NULL; i++)
        if (file[i][0] != '\n' && file[i][0] != '\0')
            file[a++] = file[i];
    file[a] = NULL;
    new_tab = malloc(sizeof(char *) * (a + 1));
    for (int i = 0; file[i] != NULL; i++)
        new_tab[i] = file[i];
    new_tab[a] = NULL;
    return (find_only_label(new_tab, pa));
}