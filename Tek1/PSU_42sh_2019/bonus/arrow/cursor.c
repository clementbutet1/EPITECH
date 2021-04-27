/*
** EPITECH PROJECT, 2019
** cursor.c
** File description:
** cursor.c
*/

#include "mysh.h"

char *delete_curs(char *str, int size, cursor_t *cu, int i)
{
    if (i == 0) {
        for (int i = cu->pos_str - 2; str[i + 1]; i++)
            str[(i > 0) ? i : 0] = str[i + 1];
        (size) ? (str[size - 1] = 0) : 0;
        if (cu->pos_str > 1) {
            cu->cursor -= (cu->cursor > 1) ? 1 : 0;
            cu->pos_str -= 1;
        }
    }
    if (i == 2) {
        if (cu->pos_str <= 1) {
            str = malloc(sizeof(char) * 1);
            str[0] = 0;
            cu->cursor = 1;
            cu->pos_str = 1;
        }
        str[cu->pos_str - 1] = 0;
        str = realloc(str, cu->pos_str);
    }
    return (str);
}

char *str_move_cursor(char *str, cursor_t *cu, char arrow)
{
    int size = my_strlen(str);
    int code_tab[] = {127, 21, 11, 0, -1};

    for (int i = 0; code_tab[i] != -1; i++) {
        if (arrow == code_tab[i] && i == 0)
            str = delete_curs(str, size, cu, i);
        if (arrow == code_tab[i] && i == 1) {
            free(str);
            str = malloc(sizeof(char) * 1);
            str[0] = 0;
            cu->cursor = 1;
            cu->pos_str = 1;
        }
        if (arrow == code_tab[i] && i == 2)
            str = delete_curs(str, size, cu, i);
    }
    return (str);
}