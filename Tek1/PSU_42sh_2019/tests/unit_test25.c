/*
** EPITECH PROJECT, 2019
** unit_test25.c
** File description:
** unit_test25.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_unset_2, Return_Value_Test)
{
    sh_t sh;
    char *str = "unset";
    char *tb[] = {strdup("unset"), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    char *tb1[] = {strdup("PATH="), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    sh.set = tb1;
    sh.parenth = 0;

    cr_assert_eq(check_unset(tb, &sh, str), 1);
}

Test(check_unset_3, Return_Value_Test)
{
    sh_t sh;
    char *str = "unset";
    char *tb[] = {strdup("unset"), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    sh.set = NULL;
    sh.parenth = 0;

    cr_assert_eq(check_unset(tb, &sh, str), 1);
}

Test(check_unset_4, Return_Value_Test)
{
    sh_t sh;
    char *str = "uet";
    char *tb[] = {strdup("unset"), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    sh.set = NULL;
    sh.parenth = 0;

    cr_assert_eq(check_unset(tb, &sh, str), 0);
}

Test(check_repeat, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("unset"), strdup("PATH\ttest"), strdup("PATH\ttest"), NULL};
    sh.set = NULL;
    sh.parenth = 0;

    cr_assert_eq(check_repeat(tb, &sh), 0);
}