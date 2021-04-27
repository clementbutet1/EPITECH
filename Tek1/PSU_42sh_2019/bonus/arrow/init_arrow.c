/*
** EPITECH PROJECT, 2019
** init_arrow.c
** File description:
** init_arrow.c
*/

#include "mysh.h"

termios_t *check_null_remp(termios_t *t, termios_t *bs)
{
    char *term_env = getenv("TERM");

    memcpy(t, bs, sizeof(termios_t));
    tgetent(NULL, term_env);
    t->c_lflag &= ~(ICANON);
    t->c_lflag &= ~(ECHO);
    t->c_cc[VMIN] = 1;
    t->c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSADRAIN, t) == -1)
        return NULL;
    return (bs);
}

termios_t *remp_term(void)
{
    termios_t *t = NULL;
    t = malloc(sizeof(termios_t));
    termios_t *bs = malloc(sizeof(termios_t));
    char *term_env = getenv("TERM");

    if (!term_env || my_strlen(term_env) == 0)
        return NULL;
    tcgetattr(0, bs);
    return (check_null_remp(t, bs));
}