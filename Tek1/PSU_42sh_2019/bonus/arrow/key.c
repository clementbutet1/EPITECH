/*
** EPITECH PROJECT, 2019
** key.c
** File description:
** key.c
*/

#include "mysh.h"

char **mycopy_tab(char **tb)
{
    int size_tab = 0;
    char **new_tab = NULL;
    int i = 0;

    if (tb == NULL)
        return (NULL);
    for (; tb[size_tab] != NULL; size_tab++);
    new_tab = malloc(sizeof(char *) * (size_tab + 1));
    for (; tb[i] != NULL; i++) {
        new_tab[i] = my_strdup(tb[i]);
    }
    new_tab[i] = NULL;
    return (new_tab);
}

void init_cursor_struct(cursor_t *cu, sh_t *sh)
{
    cu->cursor = 0;
    cu->history = NULL;
    cu->pos_str = 0;
    cu->prompt = cols(NULL);
    cu->history = mycopy_tab(sh->hist.history);
    if (cu->history != NULL)
        cu->pos_hist = size_history(cu->history);
    return;
}

char *check_arrow_cursor(char arow, char *str, cursor_t *cu, winsize_t *w)
{
    if (!check_cursor(arow)) {
        if (((arow >= 32 && arow <= 126) || (arow == 0) || (arow == '\t'))) {
            str = check_arrow_space(str, cu, arow, w);
        } else if (cu->pos_str > 0)
            str = str_move_cursor(str, cu, arow);
    } else
        str = handle_special_keys(str, arow, cu, w);
    return (str);
}

char *write_arrow(char *str)
{
    write(1, "\n", 1);
    return (str);
}

char *parse_arrow(char *display, sh_t *sh, cursor_t *cu, char *str)
{
    char arrow = 0;
    char *stra = NULL;
    winsize_t w;

    init_cursor_struct(cu, sh);
    do {
        ioctl(0, TIOCGWINSZ, &w);
        if (arrow == 4)
            return NULL;
        if (arrow != 12 && arrow != 3) {
            str = check_arrow_cursor(arrow, str, cu, &w);
        } else {
            stra = (arrow == 12) ? "\e[1;1H\e[2J" : "\n";
            write(1, stra, my_strlen(stra));
        }
        write_prompt(str, display, cu, &w);
    }
    while ((arrow = get_arrow_key()) != '\n');
    return (write_arrow(str));
}