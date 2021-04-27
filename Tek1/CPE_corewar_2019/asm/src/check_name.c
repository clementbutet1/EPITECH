/*
** EPITECH PROJECT, 2019
** check_name.c
** File description:
** check_name.c
*/

#include "asm.h"

void check_end(char *str)
{
    int gd = 0;
    char *check = "\"\n";
    int size_str = my_strlen(str) - 1;
    int size_check = my_strlen(check);
    int i = 0;

    if (size_check > my_strlen(str))
        my_putstr_error("Error : Invalid name or comment");
    for (; check[i] != '\0'; i++);
    i--;
    for (; i >= 0; i--)
        if (str[size_str] == check[i]) {
            size_str--;
            gd++;
        }
    if (gd == size_check)
        return;
    my_putstr_error("Error : Invalid name or comment");
    return;
}

void check_quote(char *str)
{
    int cpt = 0;
    int j = 0;

    for (; str[j] != ' '; j++);
    j++;
    if (!(str[j] == '"'))
        my_putstr_error("Error : Invalid name or comment");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            cpt++;
        if (str[i] == '"' && str[i + 1] == '"')
            my_putstr_error("Error : No comment or name in quote");
    }
    if (cpt != 2)
        my_putstr_error("Error : No quote in comment or name");
    check_end(str);
    return;
}

char *recup_name_and_comment(char *str)
{
    char *rslt = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    int size = 0;

    for (; str[i] != '"'; i++);
    i++;
    k = i;
    for (; str[k] != '"'; k++)
        size++;
    rslt = malloc(sizeof(char) * (size + 1));
    for (; str[i] != '"'; i++) {
        rslt[j] = str[i];
        j++;
    }
    rslt[j] = '\0';
    return (rslt);
}

void recup_and_check_all_name(params_t *params, char **tab)
{
    int size_name = my_strlen(tab[0]);
    int size_comment = my_strlen(tab[1]);

    if (size_name > PROG_NAME_LENGTH || size_comment > COMMENT_LENGTH)
        my_putstr_error("Error : Name or Comment to long");
    check_quote(tab[0]);
    check_quote(tab[1]);
    params->name = recup_name_and_comment(tab[0]);
    params->comment = recup_name_and_comment(tab[1]);
    return;
}

void recup_args(params_t *params, char **tab)
{
    char *str = NULL;

    if ((tab[0] != NULL && tab[1] != NULL)) {
        tab = check_tab(tab, str);
        if (!(tab[0][0] == '.' && tab[1][0] == '.'))
            my_putstr_error("Error : No point before name or no comment");
        check_error_begin(tab);
        recup_and_check_all_name(params, tab);
    } else
        my_putstr_error("Error : No enough args to make .cor");
    return;
}