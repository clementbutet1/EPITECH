/*
** EPITECH PROJECT, 2019
** unit_test7.c
** File description:
** unit_test7.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(test_first_cara, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = malloc(sizeof(char *) * 2);
    pa.env.envi[0] = "usr/bin";
    pa.env.envi[1] = NULL;
    char *str = "1zer";
    char *str1 = "azet";
    char **all_cmd = malloc(sizeof(char *) * 3);
    all_cmd[0] = "env";
    all_cmd[1] = "test";
    all_cmd[2] = NULL;

    cr_assert_eq(check_exit_cara_env_no_env(&pa, str, str1, all_cmd), 11);
}

Test(test_special_cara, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = malloc(sizeof(char *) * 2);
    pa.env.envi[0] = "usr/bin";
    pa.env.envi[1] = NULL;
    char *str = "ze#r";
    char *str1 = "azet";
    char **all_cmd = malloc(sizeof(char *) * 3);
    all_cmd[0] = "env";
    all_cmd[1] = "test";
    all_cmd[2] = NULL;

    cr_assert_eq(check_exit_cara_env_no_env(&pa, str, str1, all_cmd), 11);
}

Test(test_normal_cara, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = malloc(sizeof(char *) * 2);
    pa.env.envi[0] = "usr/bin";
    pa.env.envi[1] = NULL;
    char *str = "PATH";
    char *str1 = "azet";
    char **all_cmd = malloc(sizeof(char *) * 3);
    all_cmd[0] = "env";
    all_cmd[1] = "test";
    all_cmd[2] = NULL;

    cr_assert_eq(check_exit_cara_env_no_env(&pa, str, str1, all_cmd), 0);
}

Test(check_entry_2, Return_Value_Test)
{
    int ac = 1;
    char **av;
    char **env;
    params_t params;

    char *cmd = "exit";
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "exit";
    all_cmd[1] = NULL;
    cr_assert_eq(check_entry(cmd), 0);
}

Test(check_entry_3, Return_Value_Test)
{
    int ac = 1;
    char **av;
    char **env;
    params_t params;

    char *cmd = "exit       ";
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "exit      ";
    all_cmd[1] = NULL;
    cr_assert_eq(check_entry(cmd), 0);
}