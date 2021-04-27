/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** verif_aliastab.c
*/

#include "mysh.h"

int find_size_alias_name(char *buffer, int pos)
{
    int i = pos;

    for (;buffer[i] != ' ' && buffer[i] != '\0'; i++);
    i++;
    return i;
}

int find_pos_alias_name(char *buffer)
{
    int space = 0;
    int compt = 0;
    int i = 0;
    int x = 0;

    for (int j = 0; buffer[j] != '\0'; j++) {
        if (buffer[j] == ' ')
            compt++;
    }
    for (int k = 0; buffer[k] != '\0'; k++) {
        if (buffer[k] == ' ')
            space++;
        if (space == compt)
            i++;
    }
    x = my_strlen(buffer) - i;
    if (space > 0)
        x++;
    return x;
}

int my_strlen_alias(char *str, int cas)
{
    int i = 0;
    int y = 0;

    for (; str[i] != '\0' && str[i] != '\t'; i++);
    if (cas == 0)
        return (i);
    i++;
    for (; str[i] != '\0'; y++, i++);
    return (y);
}

char *complete_alias(sh_t *sh, int i, int line, char *buffer)
{
    char *str = my_strdup(buffer);
    char *str2;

    str[i] = '\0';
    str2 = my_strcat(str, &sh->alias.alias[line]
    [my_strlen_alias(sh->alias.alias[line], 0) + 1]);
    if (buffer[i + my_strlen_alias(sh->alias.alias[line], 0)] != '\0')
        str2 = my_strcat(str2, &buffer[i + \
        my_strlen_alias(sh->alias.alias[line], 0)]);
    free(str);
    free(buffer);
    return (str2);
}

char *find_alias_name_buff(char *buffer, sh_t *sh)
{
    for (int i = 0; buffer[i] != '\0' && buffer[i] != ' '; i++) {
        for (int y = 0; sh->alias.alias[y] != NULL; y++) {
            if (my_strncmp(&buffer[i], sh->alias.alias[y],
            my_strlen_alias(sh->alias.alias[y], 0)) == 0) {
                buffer = complete_alias(sh, i, y, buffer);
                return (buffer);
            }
        }
    }
    return (buffer);
}