/*
** EPITECH PROJECT, 2018
** unit_test.c
** File description:
** unit_test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include"../include/mysh.h"
#include "../include/my.h"

Test(check_entry, Return_Value_Test)
{
    char *enter = "                 ";

    cr_assert_eq(check_entry(enter), 0);
}

Test(get_line_of_env, Return_Value_Test)
{
    params_t params;

    cr_assert_eq(get_line_of_env(&params), 11);
}

Test(check_same_word, Return_Value_Test)
{
    cr_assert_eq(check_same_word("exit", "exit"), 11);
}

Test(check_same_env, Return_Value_Test)
{
    params_t params;
    params.envi = NULL;
    char *first;
    char *scd;

    cr_assert_eq(check_same_env(&params, first, scd), 11);
}

Test(check_begin_space, Return_Value_Test)
{
    int i = 0;
    char *str = "    a";

    cr_assert_eq(check_begin_space(str, i), 4);
}