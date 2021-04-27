/*
** EPITECH PROJECT, 2019
** unit_test29.c
** File description:
** unit_test29.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"


Test(does_env_exist, Return_Value_Test)
{
    char *tb[] = {strdup("where"), strdup("test"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh_t sh;
    sh.path.env = env;


    cr_assert_eq(does_env_exist(tb, &sh), -1);
}

Test(recup_arg, Return_Value_Test)
{
    char *tb[] = {strdup("foeach"), strdup("x"), strdup("1 2 3"), NULL};
    char *env[] = {strdup("1"), strdup("2"), strdup("3"), NULL};

    cr_assert_not(recup_arg(tb) == env);
}

Test(recup_arg_2, Return_Value_Test)
{
    char *tb[] = {strdup("foeach"), strdup("x"), strdup("1 2 3)"), NULL};
    char *env[] = {strdup("1"), strdup("2"), strdup("3"), NULL};

    cr_assert_not(recup_arg(tb) == env);
}

Test(check_history, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("history");
    char *tb[] = {strdup("history"), strdup("tesr"), NULL};
    cr_assert_eq(check_history(tb, &sh, str, 0), 1);
}

Test(check_history_1, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("history");
    char *tb[] = {strdup("hi"), NULL};
    cr_assert_eq(check_history(tb, &sh, str, 0), 0);
}