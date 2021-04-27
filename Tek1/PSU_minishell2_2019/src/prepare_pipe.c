/*
** EPITECH PROJECT, 2019
** prepare_pipe.c
** File description:
** prepare_pipe.c
*/

#include "my.h"
#include "mysh.h"

char *check_access_for_pipe(int len, char *rslt, params_t *params, char *entry)
{
    for (int i = 0; params->path_tab[i]; i = i + 1) {
        rslt = malloc(sizeof(char *) *
        (len + my_strlen(params->path_tab[i]) + 2));
        rslt = params->path_tab[i];
        rslt = my_strcat(rslt, "/");
        rslt = my_strcat(rslt, entry);
        if (access(rslt, R_OK) == 0)
            return (rslt);
    }
    free(rslt);
    return (NULL);
}

int check_pipe_error(char ***tab, char *str)
{
    int i = 0;
    int cpt = 0;

    for (; tab[i] != NULL; i++);
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == '|')
            cpt++;
        if (str[j] == '|' && str[j + 1] == '\0')
            return (84);
        if (str[j] == '|' && str[j + 1] == ' ' && str[j + 2] == '|')
            return (84);
    }
    return (((i - 1) == cpt) ? 0 : 84);
}

char ***parse_pipe_cmd(params_t *params, pipe_t *pipe)
{
    char *new_cmd = put_tab_buffer(params->cmd);
    new_cmd = clean_str(new_cmd, params);
    char **cmd_pipe = my_str_tab(new_cmd, '|');
    char ***all_pipe_tab;
    int size = 0;
    int i = 0;
    int nb_pipe = 0;

    for (; cmd_pipe[size] != NULL; size++);
    all_pipe_tab = malloc(sizeof(char **) * (size + 1));
    for (; i != size; i++) {
        cmd_pipe[i] = clean_str(cmd_pipe[i], params);
        all_pipe_tab[i] = my_str_tab(cmd_pipe[i], ' ');
    }
    all_pipe_tab[i] = NULL;
    if (check_pipe_error(all_pipe_tab, new_cmd) == 84)
        return (NULL);
    pipe->cmd_pipe = copy_tab(cmd_pipe);
    return (all_pipe_tab);
}

void prepare_check_access(params_t *params, pipe_t *pip, int k)
{
    pip->len = my_strlen(pip->cmd[k][0]);
    pip->path = check_access_for_pipe(pip->len, pip->path,
    params, pip->cmd[k][0]);
}