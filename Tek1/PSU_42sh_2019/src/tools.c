/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** tools.c
*/

#include "mysh.h"

int my_strlen_redirection(char *str)
{
    int i = 0;
    int a = 0;

    while (str[i] != '\0') {
        if ((str[i] == '<' && str[i - 1] != ' ' && str[i - 1] != '<') ||
            (str[i] == '>' && str[i - 1] != ' ' && str[i - 1] != '>'))
            a++;
        if ((str[i] == '<' && str[i + 1] != '\0' && str[i + 1] != ' '
            && str[i + 1] != '<') || (str[i] == '>' && str[i + 1] != '\0'
            && str[i + 1] != ' ' && str[i + 1] != '>'))
            a++;
        i++;
        a++;
    }
    return (a);
}

char **my_str_to_word_array_mysh3(char *buffer, char sepa, char **tb)
{
    int c = 0;
    int d = 0;

    for (int i = 0, a = 0; buffer[i] != '\0'; i++, c++) {
        if (buffer[i] == '"') {
            a++;
            i++;
        }
        if (a % 2 == 0 && buffer[i] == sepa && buffer[i + 1] != '\0') {
            tb[d++][c] = '\0';
            tb[d] = &buffer[i + 1];
            c = -1;
        }
        if (a % 2 == 0 && buffer[i] == sepa && buffer[i + 1] == '\0')
            tb[d][c] = '\0';
    }
    tb[d++][c] = '\0';
    tb[d] = NULL;
    for (int i = 0; tb[i] != NULL; i++)
        tb[i] = my_strdup(tb[i]);
    return (tb);
}

int my_str_to_word_array_mysh2(char *buffer, char sepa)
{
    int d = 0;

    for (int i = 0, a = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '"') {
            a++;
            i++;
        }
        if (a % 2 == 0 && buffer[i] == sepa && buffer[i + 1] != '\0')
            d++;
    }
    return (d);
}

char **my_str_to_word_array_mysh(char *buffer, char sepa)
{
    int d = 0;
    char **tb;
    char **s;

    d = my_str_to_word_array_mysh2(buffer, sepa);
    tb = malloc(sizeof(char *) * (d + 2));
    for (int s = 0; s < d + 2; s++)
        tb[s] = NULL;
    tb[0] = &buffer[0];
    tb = my_str_to_word_array_mysh3(buffer, sepa, tb);
    if (tb[d][0] == '\0') {
        s = malloc(sizeof(char *) * (d + 1));
        for (int i = 0; i < d; i++)
            s[i] = tb[i];
        s[d] = NULL;
        free(tb[d + 1]);
        free(tb);
        return (s);
    }
    return (tb);
}