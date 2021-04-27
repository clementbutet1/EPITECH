/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_alias_name.c
*/

#include "mysh.h"

int check_alias_name(char *name, sh_t *sh)
{
    int i = 0;

    for (int y = 0; sh->alias.alias[y] != NULL; y++) {
        i = my_strcmp_alias(sh->alias.alias[y], name);
        if (i == 9)
            return y;
    }
    return -1;
}

char *set_alias_command(int size, char *alias)
{
    int i = 0;
    int j = 0;
    char *command = malloc(sizeof(char) * size + 1);

    while (alias[i] != '\t')
        i++;
    for (int x = i + 1; alias[x] != '\0'; x++) {
        command[j] = alias[x];
        j++;
    }
    command[j] = '\0';
    return command;
}

void modify_buffer_alias(char *command, sh_t *sh)
{
    int i = 0;

    free(sh->buffer);
    sh->buffer = malloc(sizeof(char) * (strlen(command) + 2));
    while (command[i] != '\0') {
        sh->buffer[i] = command[i];
        i++;
    }
    sh->buffer[i] = '\n';
    sh->buffer[i + 1] = '\0';
}

void modify_exe_alias(char **exe, sh_t *sh)
{
    int j = 0;
    int line = check_alias_name(exe[0], sh);
    int size = my_strlen(sh->alias.alias[line]);
    char *command = NULL;

    command = malloc(sizeof(char) * (size + 1));
    command = set_alias_command(size, sh->alias.alias[line]);
    j = my_strlen(command);
    command[j] = ' ';
    j++;
    for (int z = 1; exe[z] != NULL; z++) {
        for (int x = 0; exe[z][x] != '\0'; x++) {
            command[j] = exe[z][x];
            j++;
        }
        command[j] = ' ';
        j++;
    }
    command[j] = '\0';
    modify_buffer_alias(command, sh);
}