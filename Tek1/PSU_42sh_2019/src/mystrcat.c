/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** mystrcat.c
*/

#include "mysh.h"

char *my_strcat_slash(char *file, char *name)
{
    int i = 0;
    char *c_st;

    for (; file[i] != '\0'; i++);
    for (int a = 0; name[a] != '\0'; i++, a++);
    c_st = malloc(sizeof(char) * i + 3);
    for (i = 0; file[i] != '\0'; i++)
        c_st[i] = file[i];
    if (c_st[i - 1] != '/') {
        c_st[i] = '/';
        i++;
    }
    for (int a = 0; name[a] != '\0'; i++, a++)
        c_st[i] = name[a];
    c_st[i] = '\0';
    return (c_st);
}

char *my_strcat(char *file, char *name)
{
    int i = 0;
    char *c_st;

    for (; file[i] != '\0'; i++);
    for (int a = 0; name != NULL && name[a] != '\0'; i++, a++);
    c_st = malloc(sizeof(char) * i + 1);
    for (i = 0; file[i] != '\0'; i++)
        c_st[i] = file[i];
    for (int a = 0; name != NULL && name[a] != '\0'; i++, a++)
        c_st[i] = name[a];
    c_st[i] = '\0';
    return (c_st);
}