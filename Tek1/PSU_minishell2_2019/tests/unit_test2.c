/*
** EPITECH PROJECT, 2018
** unit_test2.c
** File description:
** unit_test2.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_unsetenv, Return_Value_Test)
{
    params_t params;
    params.env.envi = NULL;
    char **all_cmd = NULL;

    cr_assert_eq(check_unsetenv(&params, all_cmd), 11);
}

Test(check_same_begin, Return_Value_Test)
{
    char *first = "cd";
    char *scd = "cd";

    cr_assert_eq(check_same_begin(first, scd), 0);
}

Test(check_if_path, Return_Value_Test)
{
    params_t params;
    params.env.envi = malloc(sizeof(char *) * 2);
    params.env.envi[0] = "PATH";
    params.env.envi[1] = NULL;

    cr_assert_eq(check_if_path(&params), 0);
}

Test(check_dir, Return_Value_Test)
{
    char *cmd = "/bin/usr/ls";

    cr_assert_eq(check_dir(cmd), 0);
}