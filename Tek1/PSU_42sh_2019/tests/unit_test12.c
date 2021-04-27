/*
** EPITECH PROJECT, 2019
** unit_test12.c
** File description:
** unit_test12.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(create_history_tab_3, Return_Value_Test)
{
    time_t now = 0;
    sh_t sh;
    sh.buffer = strdup("");
    char *tb[] = {strdup("ls"), strdup("cd"), NULL};
    sh.hist.history = tb;

    cr_assert_eq(create_history_tab(&sh, now), 0);
}

Test(write_no_env, Return_Value_Test)
{
    char *str = strdup("ls");
    char *tb[] = {strdup("ls"), NULL};

    cr_assert_not(write_no_env(str) == tb);
}

Test(add_element_into_h, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("ls");
    char *tb1[] = {strdup("cat"), strdup("cd"), NULL};
    sh.hist.h = tb1;
    char *tb[] = {strdup("cat"), strdup("cd"), strdup("ls"), NULL};

    cr_assert_not(add_element_into_h(&sh, str) == tb);
}

Test(add_element_into_min, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("ls");
    char *tb1[] = {strdup("cat"), strdup("cd"), NULL};
    sh.hist.min = tb1;
    char *tb[] = {strdup("cat"), strdup("cd"), strdup("ls"), NULL};

    cr_assert_not(add_element_into_min(&sh, str) == tb);
}

Test(add_element_into_hist, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("ls");
    char *tb1[] = {strdup("cat"), strdup("cd"), NULL};
    sh.hist.history = tb1;
    char *tb[] = {strdup("cat"), strdup("cd"), strdup("ls"), NULL};

    cr_assert_not(add_element_into_hist(&sh, str) == tb);
}