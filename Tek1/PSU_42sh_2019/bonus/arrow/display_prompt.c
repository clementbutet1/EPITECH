/*
** EPITECH PROJECT, 2019
** display_prompt.c
** File description:
** display_prompt.c
*/

#include "mysh.h"

int *init_tab_int(int *sz, cursor_t *cu)
{
    for (int i = 0; i <= 6; i++)
        sz[i] = 0;
    sz[7] = cu->pos_str;
    return (sz);
}

int *check_uptdate_promt(char *str, int *sz, cursor_t *cu, winsize_t *w)
{
    char *str2 = NULL;

    (str != NULL) ? (sz[0] = my_strlen(str)) : (sz[0] = 0);
    if (sz[0] > w->ws_col) {
        sz[0] = w->ws_col;
        sz[7] = cu->cursor;
        sz[3] = cu->prompt;
    }
    write(1, "\r", 1);
    (w->ws_col > 0) ?(sz[1] = w->ws_col) : (sz[1] = 0);
    str2 = malloc(sizeof(char) * (sz[1]));
    for (int i = 0; i < sz[1]; i++)
        str2[i] = ' ';
    write(1, str2, sz[1]);
    write(1, "\r", 1);
    return (sz);
}

void write_prompt(char *str, char *prompt, cursor_t *cu, winsize_t *w)
{
    int *sz = malloc(sizeof(int) * 8);
    char *str3 = NULL;

    sz = init_tab_int(sz, cu);
    sz = check_uptdate_promt(str, sz, cu, w);
    my_putstr("$> ");
    sz[4] = w->ws_col;
    sz[5] = (str) ? my_strlen(str) : 0;
    if (sz[5] + cols(prompt) < sz[4])
        write(1, str, sz[5]);
    sz[7] = ((sz[0] - sz[3] - (sz[7] - 1)));
    (sz[7] > 0) ? (sz[2] = sz[7]) : (sz[2] = 0);
    str3 = malloc(sizeof(char) * (sz[2]));
    for (int i = 0; i < sz[2]; i++)
        str3[i] = '\b';
    write(1, str3, sz[2]);
    return;
}