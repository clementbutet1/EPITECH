/*
** EPITECH PROJECT, 2019
** unit_test13.c
** File description:
** unit_test13.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(is_forking, Return_Value_Test)
{
    cr_assert_eq(is_forking(10), 10);
}

Test(is_forking_1, Return_Value_Test)
{
    cr_assert_eq(is_forking(-1), -1);
}

Test(add_com_1, Return_Value_Test)
{
    char *str = strdup("test");
    char *tb[] = {strdup("foeach"), strdup("x"), strdup("1 2 3"), NULL};
    char *env[] = {strdup("foeach"), strdup("x"), strdup("1 2 3"), strdup("test"), NULL};

    cr_assert_not(add_com(tb, str) == env);
}

Test(is_var_11, Return_Value_Test)
{
    char *str = strdup("test\n");
    char *str1 = strdup("test");

    cr_assert_eq(is_var(str, str1), 1);
}