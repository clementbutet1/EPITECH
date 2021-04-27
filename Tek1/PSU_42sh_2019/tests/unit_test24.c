/*
** EPITECH PROJECT, 2019
** unit_test24.c
** File description:
** unit_test24.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_same_begin, Return_Value_Test)
{
    char *str1 = strdup("aa\ta");
    char *str = strdup("aa\ta");

    cr_assert_eq(check_same_begin(str1, str), 0);
}

Test(check_same_begin_1, Return_Value_Test)
{
    char *str1 = strdup("azert");
    char *str = strdup("set");

    cr_assert_eq(check_same_begin(str1, str), 0);
}

Test(execute_unset, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("PATH="), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    sh.set = tb;

    cr_assert_eq(execute_unset(&sh, tb), 1);
}

Test(check_unset, Return_Value_Test)
{
    sh_t sh;
    char *str = "unset";
    char *tb[] = {strdup("unset"), strdup("PATH\ttest"), NULL};
    char *tb1[] = {strdup("PATH="), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    sh.set = tb1;

    cr_assert_eq(check_unset(tb, &sh, str), 1);
}

Test(check_unset_1, Return_Value_Test)
{
    sh_t sh;
    char *str = "unset";
    char *tb[] = {strdup("unset"), strdup("PATH=test"), NULL};
    char *tb1[] = {strdup("PATH="), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    sh.set = tb1;
    sh.parenth = 0;

    cr_assert_eq(check_unset(tb, &sh, str), 1);
}