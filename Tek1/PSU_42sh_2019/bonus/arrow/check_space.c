/*
** EPITECH PROJECT, 2019
** check_space.c
** File description:
** check_space.c
*/

#include "mysh.h"

void check_condi_cursor(cursor_t *cu, winsize_t *w)
{
    unsigned short cursor = cu->cursor;

    cursor += 1;
    cu->pos_str += 1;
    if (cursor <= w->ws_col - cu->prompt)
        cu->cursor += 1;
    else
        cu->cursor += 0;
}

char *check_str_cursor(char *str, char c, cursor_t *cu, int size)
{
    int k = 0;

    size = my_strlen(str);
    if (size > 0)
        str = realloc(str, size + 3);
    else {
        str = malloc(sizeof(char) * 3);
        str[0] = 0;
    }
    if (cu->pos_str)
        k = cu->pos_str - 1;
    else
        k = 0;
    k++;
    str[(cu->pos_str) ? cu->pos_str - 1 : 0] = c;
    str[size + 1] = 0;
    return (str);
}

char *check_arrow_space(char *str, cursor_t *cu, char c, winsize_t *w)
{
    size_t size = (str) ? my_strlen(str) : 0;
    char *tmp = my_strdup(str);
    char *new_str = NULL;

    if (size + cu->prompt + 1 >= w->ws_col)
        return tmp;
    new_str = check_str_cursor(str, c, cu, size);
    for (size_t i = cu->pos_str - 1; i < size; i++)
        new_str[i + 1] = tmp[i];
    check_condi_cursor(cu, w);
    return (new_str);
}