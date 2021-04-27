/*
** EPITECH PROJECT, 2019
** unit_test15.c
** File description:
** unit_test15.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(err_handling_foreach, Return_Value_Test)
{
    char *tb[] = {strdup("foch"), strdup("x"), NULL};

    cr_assert_eq(err_handling_foreach(tb), -1);
}

Test(err_handling_foreach_1, Return_Value_Test)
{
    char *tb[] = {strdup("foch"), strdup("x"), strdup("etst"), NULL};

    cr_assert_eq(err_handling_foreach(tb), -1);
}

Test(err_handling_foreach_2, Return_Value_Test)
{
    char *tb[] = {strdup("foch"), strdup("(x"), strdup("etst"), NULL};

    cr_assert_eq(err_handling_foreach(tb), -1);
}

Test(check_par, Return_Value_Test)
{
    char *tb[] = {strdup("foch"), strdup("(x"), strdup("etst"), NULL};

    cr_assert_eq(check_par(tb), -1);
}

Test(check_par_2, Return_Value_Test)
{
    char *tb[] = {strdup("foch"), strdup("x)"), strdup("etst"), NULL};

    cr_assert_eq(check_par(tb), -1);
}