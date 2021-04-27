/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** check_buffer.c
*/

#include "mysh.h"

int buffer_pipe2(sh_t *sh, int fd_in, int fd_out, int d)
{
    sh->good_redi = 0;
    sh->pid = -1;
    sh->exe[d - 1] = check_redirection(sh->exe[d - 1], sh, -1);
    for (int i = 0; sh->exe[i] != NULL; i++) {
        if (i < d - 1 && d > 1) {
            buffer_pipe2_part1(sh, &fd_in, i);
        }
        else {
            buffer_pipe2_part2(sh, &fd_in, &fd_out, i);
        }
    }
    sh->good_redi = 0;
    if (dup2(sh->spipe.fd_in, 0) == -1)
        exit(84);
    if (dup2(sh->spipe.fd_out, 1) == -1)
        exit(84);
    wait_last_pid(sh);
    return (0);
}

int check_buffer_pipe(sh_t *sh, int fd_in, int fd_out)
{
    int d = 0;

    for (; sh->pipe[d] != NULL; d++);
    sh->exe = malloc(sizeof(char **) * (d + 1));
    for (d = 0; sh->pipe[d] != NULL; d++) {
        sh->pipe[d] = clean_buffer(sh->pipe[d], 0);
        sh->pipe[d] = find_alias_name_buff(sh->pipe[d], sh);
        sh->exe[d] = create_executable(sh->pipe[d]);
    }
    sh->exe[d] = NULL;
    buffer_pipe2(sh, fd_in, fd_out, d);
    return (0);
}

int check_error_pipe(char *buffer)
{
    for (int i = 0, a = 0, d = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '|' && a % 2 == 0)
            d++;
        if ((d > 2 && d > 0 && buffer[i + 1] == '\0') || (i == 0 && d > 0)
        || (i > 0 && d > 0 && (buffer[i - 1] == ';' ||
        buffer[i + 1] == ';'))) {
            my_putstr_error("Invalid null command.\n");
            return (1);
        }
        if (buffer[i] != ' ' && buffer[i] != '|' && a % 2 == 0)
            d = 0;
    }
    return (0);
}

void use_buffer_line(sh_t *sh, char *ligne, int free_or_not)
{
    char **test;
    char *str;

    sh->spipe.free_or_not = free_or_not;
    sh->buffer = clean_buffer(ligne, 0);
    str = my_strcpy(sh->buffer);
    test = my_str_to_word_array_mysh(str, ' ');
    if (my_strcmp(test[0], "foreach") != 0) {
        sh->buffer = my_parenth(sh->buffer, sh);
        if (sh->parenth == 2)
            return;
    }
    sh->buffer = check_double_pipe(sh->buffer, sh);
    sh->buffer = check_double_and(sh->buffer, sh);
    sh->pipe = my_str_to_word_array(sh->buffer, '|');
    check_buffer_pipe(sh, dup(sh->spipe.fd_in), dup(sh->spipe.fd_out));
    sh->spipe.free_or_not = 1;
}

int check_buffer(sh_t *sh, time_t now)
{
    sh->buffer = clean_buffer(sh->buffer, 0);
    if (create_history_tab(sh, now) == 1)
        return (0);
    if (check_error_pipe(sh->buffer) == 1)
        return (84);
    sh->ligne = my_str_to_word_array_mysh(sh->buffer, ';');
    for (int i = 0; sh->ligne[i] != NULL; i++) {
        use_buffer_line(sh, sh->ligne[i], 1);
    }
    return (0);
}