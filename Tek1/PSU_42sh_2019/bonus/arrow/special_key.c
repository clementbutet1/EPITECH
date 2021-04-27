/*
** EPITECH PROJECT, 2019
** special_key.c
** File description:
** special_key.c
*/

#include "mysh.h"

int size_history(char **tb)
{
    int i = 0;

    for (; tb[i] != NULL; i++);
    return (i);
}

char *check_type_arrow(cursor_t *cu, int type)
{
    if (type == 1) {
        if (cu->pos_hist > 0) {
            cu->pos_hist -= 1;
            return (cu->history[cu->pos_hist]);
        } else
            return ("");
    }
    if (type == 2) {
        if (cu->pos_hist < (size_history(cu->history) - 1)) {
            cu->pos_hist += 1;
            return (cu->history[cu->pos_hist]);
        } else
            return ("");
    }
    return ("");
}

char *arrow_type(char *str, cursor_t *c, int got, winsize_t *w)
{
    if (got == 0) {
        str = check_type_arrow(c, 1);
        c->pos_str = (str) ? my_strlen(str) + 1 : 1;
    }
    if (got == 1) {
        c->cursor -= (c->cursor > 1) ? 1 : 0;
        c->pos_str -= (c->pos_str - 1) ? 1 : 0;
    }
    if (got == 2) {
        str = check_type_arrow(c, 2);
        c->pos_str = (str) ? my_strlen(str) + 1 : 1;
    }
    if (got == 3) {
        c->cursor += (c->cursor < my_strlen(str) + 1 &&
        sizeof(c->cursor + 1) < sizeof(w->ws_col) - sizeof(c->prompt)) ? 1 : 0;
        c->pos_str += (c->pos_str <= my_strlen(str)) ? 1 : 0;
    }
    return (str);
}

char *handle_special_keys(char *str, char arrow, cursor_t *cu, winsize_t *w)
{
    int got = 0;
    char keys_tab[] = {-1, -2, -3, -4, 1, 5, -5, -6, 0};

    for (int i = 0; keys_tab[i]; i++)
        if (keys_tab[i] == arrow)
            got = i;
    if (got != -1) {
        if (got == 0)
            str = arrow_type(str, cu, got, w);
        if (got == 1)
            str = arrow_type(str, cu, got, w);
        if (got == 2)
            str = arrow_type(str, cu, got, w);
        if (got == 3)
            str = arrow_type(str, cu, got, w);
    }
    return (str);
}