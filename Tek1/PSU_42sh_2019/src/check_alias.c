/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_alias.c
*/

#include "mysh.h"

void prepar_command(char **exe, sh_t *sh)
{
    int lenght = 0;
    int compt = 0;
    int x = 0;

    for (int i = 2; exe[i] != NULL; i++) {
        lenght = lenght + my_strlen(exe[i]);
        compt++;
    }
    sh->alias.command = malloc(sizeof(char) * lenght + compt + 1);
    for (int i = 2; exe[i] != NULL; i++) {
        for (int j = 0; exe[i][j] != '\0'; j++) {
            sh->alias.command[x] = exe[i][j];
            x++;
        }
        sh->alias.command[x] = ' ';
        x++;
    }
    sh->alias.command[x - 1] = '\0';
}

int alias_find_line(sh_t *sh, char *str)
{
    int x = 0;
    int y = 0;
    int st = 1;

    while (sh->alias.alias[y] != NULL) {
        while ((sh->alias.alias[y][x] != '\0' || str[x] != '\0') && st == 1) {
            if (str[x] == sh->alias.alias[y][x])
                x++;
            else if (str[x] < sh->alias.alias[y][x])
                return y;
            else
                st = 0;
        }
        st = 1;
        x = 0;
        y++;
    }
    return sh->alias.height;
}

void enter_alias_in_tab(int line, sh_t *sh, char *name)
{
    char *new_line = my_strdup(sh->alias.command);
    int size = 0;

    sh->alias.alias[line] = strdup(name);
    sh->alias.alias[line] = my_strcat(sh->alias.alias[line], "\t");
    size = my_strlen(new_line);
    size += my_strlen(sh->alias.alias[line]);
    malloc(sizeof(char) * (size + 1));
    sh->alias.alias[line] = my_strcat(sh->alias.alias[line], new_line);
}

void set_alias(sh_t *sh, char *name)
{
    int line = alias_find_line(sh, name);

    sh->alias.height++;
    sh->alias.alias = realloc(sh->alias.alias, sizeof(char *) * \
    (sh->alias.height + 1));
    sh->alias.alias[sh->alias.height] = malloc(sizeof(char) * sh->alias.width);
    for (int y = sh->alias.height - 1; y != line; y--) {
        sh->alias.alias[y] = sh->alias.alias[y - 1];
    }
    enter_alias_in_tab(line, sh, name);
    sh->alias.alias[sh->alias.height] = NULL;
}

int check_alias(char **exe, sh_t *sh)
{
    char *alias = "alias";

    if (my_strcmp(alias, exe[0]) != 0) {
        if (check_alias_name(exe[0], sh) == -1) {
            return 0;
        } else {
            modify_exe_alias(exe, sh);
            return 0;
        }
    }
    if (exe[1] == NULL)
        print_alias_tab(sh);
    else if (exe[2] != NULL) {
        prepar_command(exe, sh);
        set_alias(sh, exe[1]);
    }
    return (1);
}