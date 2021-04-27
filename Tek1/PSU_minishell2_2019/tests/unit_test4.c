/*
** EPITECH PROJECT, 2019
** unit_test4.c
** File description:
** unit_test4.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_same_env_no_env, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char *str1 = NULL;
    char *str = NULL;

    cr_assert_eq(check_same_env(&pa, str, str1), 11);
}

Test(check_exit_setenv, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "aaaa";
    all_cmd[1] = NULL;

    cr_assert_eq(check_exit_setenv(&pa, all_cmd), 11);
}

Test(get_line_of_env_null, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char *cmd = "ls";
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "ls";
    all_cmd[1] = NULL;

    cr_assert_eq(get_line_of_env(&pa, cmd), 11);
}

Test(find_bulltin2, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char *cmd = "cd";
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "cd";
    all_cmd[1] = NULL;

    cr_assert_eq(find_bulltin2(&pa, cmd, all_cmd), 11);
}

Test(check_same_word_test, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char *cmd = "exit";
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "exit";
    all_cmd[1] = NULL;

    cr_assert_eq(check_same_word(cmd, "exit"), 11);
}