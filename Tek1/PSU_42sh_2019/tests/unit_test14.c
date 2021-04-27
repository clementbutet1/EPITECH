/*
** EPITECH PROJECT, 2019
** unit_test14.c
** File description:
** unit_test14.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(is_var, Return_Value_Test)
{
    char *str = strdup("test\n");
    char *str2 = strdup("test");

    cr_assert_eq(is_var(str2, str), 0);
}

Test(is_var_2, Return_Value_Test)
{
    char *str = strdup("test");
    char *str2 = strdup("test\n");

    cr_assert_eq(is_var(str2, str), 1);
}

Test(add_com, Return_Value_Test)
{
    char *str = strdup("test1");
    char *tb[] = {strdup("test"), NULL};
    char *f[] = {strdup("test"), strdup("test1"), NULL};

    cr_assert_not(add_com(tb, str) == f);
}

Test(check_foreach, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("foreach"), strdup("(x)"), NULL};

    cr_assert_eq(check_foreach(tb, &sh), 1);
}

Test(check_foreach_1, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("foch"), strdup("(x)"), NULL};

    cr_assert_eq(check_foreach(tb, &sh), 0);
}