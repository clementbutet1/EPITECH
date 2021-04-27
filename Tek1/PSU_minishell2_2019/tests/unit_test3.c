/*
** EPITECH PROJECT, 2019
** unit_test3.c
** File description:
** unit_test3.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_unsetenv_return, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd;

    cr_assert_eq(check_unsetenv(&pa, all_cmd), 11);
}

Test(check_unsetenv_bad_args, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 4);
    all_cmd[0] = "aaaa";
    all_cmd[1] = "bv";
    all_cmd[2] = "zze";
    all_cmd[3] = NULL;

    cr_assert_eq(check_unsetenv(&pa, all_cmd), 11);
}

Test(check_unsetenv_bad_args_cmd, Return_Value_Test)
{
    params_t pa;
    pa.env.envi = NULL;
    char **all_cmd = malloc(sizeof(char *) * 2);
    all_cmd[0] = "aaaa";
    all_cmd[1] = NULL;

    cr_assert_eq(check_unsetenv(&pa, all_cmd), 11);
}

Test(check_same_begin_retur, Return_Value_Test)
{
    char *str1 = "PATH=";
    char *str = "PATH";


    cr_assert_eq(check_same_begin(str1, str), 11);
}

Test(check_same_begin_return_bad, Return_Value_Test)
{
    char *str1 = "TH=";
    char *str = "PTH";


    cr_assert_eq(check_same_begin(str1, str), 0);
}