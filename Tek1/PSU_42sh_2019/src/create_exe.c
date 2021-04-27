/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** create_exe.c
*/

#include "mysh.h"

void create_executable3(char *buffer, int j, char **exe)
{
    int c = 0;
    int d = 0;
    int a = 0;

    for (int i = j; buffer[i] != '\0' && buffer[i] != '\n'; i++, c++) {
        if (buffer[i] == '"') {
            a++;
        }
        if (a % 2 == 0 && buffer[i] == ' ') {
            exe[d++][c] = '\0';
            exe[d] = &buffer[i + 1];
            c = -1;
        }
    }
    exe[d++][c] = '\0';
    exe[d] = NULL;
    for (int i = 0; exe[i] != NULL; i++) {
        exe[i] = my_strdup(exe[i]);
    }
    if (a > 0)
        delete_quote(exe);
}

int create_executable2(char *buffer, int d, int j)
{
    for (int a = 0, i = j; buffer[i] != '\0' && buffer[i] != '\n';
    i++) {
        if (buffer[i] == '"') {
            a++;
            i++;
        }
        if (a % 2 == 0 && buffer[i] == ' ' && buffer[i + 1] != ' ')
            d++;
    }
    return (d);
}

char **create_executable(char *buffer)
{
    int d = 0;
    int j = 0;
    char **exe;

    for (j = 0; buffer[j] != '\0' && buffer[j] != '\n' &&
    buffer[j] == ' '; j++);
    d = create_executable2(buffer, d, j);
    exe = malloc(sizeof(char *) * (d + 2));
    for (int s = 0; s < d + 2; s++)
        exe[s] = NULL;
    d = 0;
    exe[0] = &buffer[j];
    create_executable3(buffer, j, exe);
    return (exe);
}