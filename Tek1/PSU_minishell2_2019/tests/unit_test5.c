/*
** EPITECH PROJECT, 2019
** unit_test5.c
** File description:
** unit_test5.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_redirection_bad, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = ">";
    all_cmd[1] = NULL;

    cr_assert_eq(check_redirection(&pa, all_cmd), 84);
}

Test(check_redirection_good, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 4);
    all_cmd[0] = "ls";
    all_cmd[1] = ">";
    all_cmd[2] = "test";
    all_cmd[3] = NULL;

    cr_assert_eq(check_redirection(&pa, all_cmd), 11);
}

Test(check_redirection_bad_after, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 4);
    all_cmd[0] = "ls";
    all_cmd[1] = ">";
    all_cmd[2] = NULL;

    cr_assert_eq(check_redirection(&pa, all_cmd), 84);
}

Test(check_redirection_after, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 4);
    all_cmd[0] = "ls";
    all_cmd[1] = ">";
    all_cmd[2] = NULL;

    cr_assert_eq(check_redirection(&pa, all_cmd), 84);
}

Test(check_arg_cd_null, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 4);
    char *str = NULL;
    char *str1 = NULL;
    all_cmd[0] = "cd";
    all_cmd[1] = "src";
    all_cmd[2] = "az";
    all_cmd[3] = NULL;

    cr_assert_eq(check_arg_cd(&pa, str, all_cmd, str1), 11);
}