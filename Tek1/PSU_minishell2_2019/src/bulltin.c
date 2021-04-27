/*
** EPITECH PROJECT, 2019
** bulltin.c
** File description:
** bulltin.c
*/

#include "my.h"
#include "mysh.h"

int get_line_of_env(params_t *params, char *cmd)
{
    if (params->env.envi == NULL) {
        my_putstr(cmd);
        my_putstr(": Command not found.\n");
        return (11);
    }
    if (get_line_pwd(params) == 11)
        return (11);
    if (get_line_old_pwd(params) == 11)
        return (11);
}

int find_bulltin2(params_t *params, char *cmd, char **all_cmd)
{
    if (check_same_word(all_cmd[0], "exit") == 11) {
        check_exit(cmd, params, all_cmd);
        return (11);
    }
    if (check_same_word(all_cmd[0], "unsetenv") == 11) {
        unsetenv_funct(params, all_cmd);
        return (11);
    }
    if (check_same_word(all_cmd[0], "setenv") == 11) {
        setenv_funct(params, all_cmd);
        return (11);
    }
    if (check_same_word(all_cmd[0], "env") == 11) {
        print_env(params, all_cmd);
        return (11);
    }
    if (get_line_of_env(params, cmd) == 11)
        return (11);
    return (0);
}

int find_bulltin(params_t *params, char *cmd, char **all_cmd)
{
    get_line_home(params);
    if ((cmd[0] == '.' || cmd[1] == '/') || cmd[0] == '/') {
        if (check_directory_executable(params, cmd, all_cmd) == 11)
            return (11);
        else
            return (0);
    }
    if (check_in_the_file(cmd, params, all_cmd) == 11)
        return (11);
    if (check_same_word(all_cmd[0], "cd") == 11) {
        check_cd(params, all_cmd[1], cmd, all_cmd);
        return (11);
    }
    if (find_bulltin2(params, cmd, all_cmd) == 11)
        return (11);
    return (0);
}