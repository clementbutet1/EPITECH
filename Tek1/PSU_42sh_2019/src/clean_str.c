/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** clean_str.c
*/

#include "mysh.h"

char **delete_quote(char **exe)
{
    for (int i = 0, a = 0, b = 0; exe[i] != NULL; i++) {
        for (a = 0, b = 0; exe[i][b] != '\0'; a++, b++) {
            if (exe[i][b] == '"')
                a--;
            else
                exe[i][a] = exe[i][b];
        }
    exe[i][a] = '\0';
    }
    return (exe);
}

char *clean_buffer3(char *buffer, int d)
{
    int i = 0;

    if (d == 1) {
        for (; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
            if (buffer[i] == '\t')
                buffer[i] = ' ';
        }
    }
    else {
        while (buffer[i] != '\0' && buffer[i] != '\n')
            i++;
        if (i > 0) {
            if (buffer[i - 1] == ' ')
                buffer[i - 1] = '\0';
        }
    }
    return (buffer);
}

void clean_buffer2(char *buffer, int *i, char *new_str, int a)
{
    while ((buffer[*i] == ' ' && new_str[a - 1] == ' ') ||
        (buffer[*i] == '\t' && new_str[a - 1] == ' ') ||
        (buffer[*i] == ' ' && new_str[a - 1] == '\t') ||
        (buffer[*i] == '\t' && new_str[a - 1] == '\t'))
        *i += 1;
}

char *clean_buffer4(char *buffer, char *new_str, int i, int a)
{
    for (a = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
        if (i > 0 && a > 0)
            clean_buffer2(buffer, &i, new_str, a);
        if ((buffer[i] == '<' && buffer[i - 1] != ' ' && buffer[i - 1]
        != '<') || (buffer[i] == '>' && buffer[i - 1] != ' ' &&
        buffer[i - 1] != '>'))
            new_str[a++] = ' ';
        if ((i == 0 && buffer[i] != ' ' && buffer[i] != '\t') ||
        (i > 0 && buffer[i] != '\n' && buffer[i] != '\0')) {
            new_str[a] = buffer[i];
            a++;
        }
        if ((buffer[i] == '<' && buffer[i + 1] != '\0' && buffer[i + 1] != ' '
        && buffer[i + 1] != '<') || (buffer[i] == '>' && buffer[i + 1] != '\0'
        && buffer[i + 1] != ' ' && buffer[i + 1] != '>'))
            new_str[a++] = ' ';
    }
    new_str[a] = '\0';
    return (new_str);
}

char *clean_buffer(char *buffer, int i)
{
    int len = my_strlen_redirection(buffer);
    char *new_str = malloc(sizeof(char) * len + 1);
    int a = 0;

    for (a = 0; a != len + 1; a++)
        new_str[a] = '\0';
    buffer = clean_buffer3(buffer, 1);
    for (; buffer[i] != '\0' && buffer[i] != '\n' && buffer[i]
    == ' '; i++);
    buffer = clean_buffer4(buffer, new_str, i, a);
    buffer = clean_buffer3(buffer, 0);
    return (buffer);
}