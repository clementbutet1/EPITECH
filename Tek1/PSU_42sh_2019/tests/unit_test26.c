/*
** EPITECH PROJECT, 2019
** unit_test26.c
** File description:
** unit_test26.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_repeat_1, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("repeat"), strdup("a"), strdup("ls"), NULL};
    sh.set = NULL;
    sh.parenth = 0;

    cr_assert_eq(check_repeat(tb, &sh), 1);
}


Test(print_repeat, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("repeat"), strdup("a"), strdup("ls"), NULL};
    sh.set = NULL;
    sh.parenth = 0;

    cr_assert_eq(print_repeat(tb, &sh), 1);
}

Test(check_repeat_2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("repeat"), strdup("-10"), strdup("ls"), NULL};
    sh.set = NULL;

    cr_assert_eq(check_repeat(tb, &sh), 1);
}

Test(check_unsetenv, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("uenv"), strdup("PATH"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh.path.env = env;

    cr_assert_eq(check_unsetenv(tb, &sh), 0);
}
