/*
** EPITECH PROJECT, 2019
** unit_test6.c
** File description:
** unit_test6.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(execute_cmd, Return_Value_Test)
{
    params_t pa;
    char *str = "ls";
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "ls";
    all_cmd[1] = NULL;

    cr_assert_eq(execute_cmd(str, &pa, all_cmd), 1);
}

Test(check_execve_option, Return_Value_Test)
{
    params_t pa;
    pid_t pid = 1;
    pa.good_path = "/usr/bin/ls";
    char *str = "ls";
    char **all_cmd = malloc(sizeof(char *) * 4);
    all_cmd[0] = "ls";
    all_cmd[1] = ">";
    all_cmd[2] = "test";
    all_cmd[3] = NULL;

    cr_assert_eq(execute_execve(str, &pa, pid, all_cmd), 1);
}

Test(check_exit_setenv_no_env_env, Return_Value_Test)
{
    char *str = "P";
    params_t pa;
    pa.env.envi = malloc(sizeof(char *) * 2);
    pa.env.envi[0] = "usr/bin";
    pa.env.envi[1] = NULL;
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "env";
    all_cmd[1] = NULL;

    cr_assert_eq(check_exit_setenv_no_env(&pa, all_cmd), 11);
}

Test(check_exit_setenv_no_args, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = malloc(sizeof(char *) * 2);
    pa.env.envi[0] = "usr/bin";
    pa.env.envi[1] = NULL;
    char **all_cmd = malloc(sizeof(char *) * 3);
    all_cmd[0] = "env";
    all_cmd[1] = "test";
    all_cmd[2] = NULL;

    cr_assert_eq(check_exit_setenv_no_env(&pa, all_cmd), 11);
}