/*
** EPITECH PROJECT, 2019
** boucl_inf.c
** File description:
** boucl_inf.c
*/

#include "mysh.h"

int boucl_inf(sh_t *sh, time_t now)
{
    cursor_t cu = {0, 0, cols(NULL), NULL, 0};
    char *str = malloc(sizeof(char) * 1);

    str[0] = 0;
    while (1) {
        sh->buffer = NULL;
        sh->s = 0;
        if ((isatty(STDIN_FILENO) == 1) && getenv("TERM")) {
            sh->term = remp_term();
            sh->buffer = parse_arrow(NULL, sh, &cu, str);
        }
        if (sh->buffer == NULL) {
            my_putstr("exit\n");
            exit (0);
        }
        if (check_buffer(sh, now) == 1)
            return (sh->exit);
        free(sh->buffer);
    }
}