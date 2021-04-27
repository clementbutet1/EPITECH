/*
** EPITECH PROJECT, 2019
** redi_pipe.c
** File description:
** redi_pipe.c
*/

#include "my.h"
#include "mysh.h"

int check_error_excve_pipe(char *cmd, params_t *params, int error)
{
    if (errno == 8) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Exec format error. Wrong Architecture.\n", 44);
        exit (11);
    } else {
        strerror(error);
        write(2, cmd, my_strlen(cmd));
        write(2, ": Command not found.\n", 22);
        exit (11);
    }
    return (0);
}

int check_final_pipe(params_t *pa, pipe_t *p, int i, int op)
{
    if ((check_redirection_pipe(pa, p, i) == 11)) {
        if (p->cmd[i + 1] != NULL) {
            my_putstr("Ambiguous output redirect.\n");
            return (84);
        } else {
            op = open_pipe(pa, p, i);
            return (op);
        }
    }
}

int open_before(params_t *pa, pipe_t *p, int op)
{
    for (int i = 0; p->cmd[i] != NULL; i++) {
        op = check_final_pipe(pa, p, i, op);
        if (op == 84)
            return (84);
    }
    return (op);
}

int check_invalid_cmd(pipe_t *p, int k)
{
    if ((p->cmd[k][0][0] == '>' || p->cmd[k][0][0] == '<' ||
    (check_same_word(p->cmd[k][0], "<<") == 11) ||
    (check_same_word(p->cmd[k][0], ">>") == 11))) {
        my_putstr("Invalid null command.\n");
        return (84);
    }
}

int check_redirection_pipe(params_t *params, pipe_t *p, int k)
{
    for (int i = 0; p->cmd[k][i] != NULL; i++) {
        if (check_invalid_cmd(p, k) == 84)
            return (84);
        if (check_same_word(p->cmd[k][i], ">") == 11)
            return (11);
        if (check_same_word(p->cmd[k][i], "<") == 11)
            return (11);
        if (check_same_word(p->cmd[k][i], ">>") == 11)
            return (11);
    }
    return (0);
}