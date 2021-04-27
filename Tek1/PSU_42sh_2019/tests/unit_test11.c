/*
** EPITECH PROJECT, 2019
** unit_test11.c
** File description:
** unit_test11.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(find_main_directory_7, Return_Value_Test)
{
    int s = 0;
    sh_t sh;
    char *tb[] = {strdup("HOMEtest"), strdup("test"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");

    cr_assert_eq(find_main_directory(&sh, s), 2);
}

Test(is_var_21, Return_Value_Test)
{
    char *str = strdup("$test\n");
    char *str1 = strdup("test");

    cr_assert_eq(is_var(str, str1), 1);
}



Test(create_history_tab_2, Return_Value_Test)
{
    time_t now = 0;
    sh_t sh;
    sh.buffer = strdup("");

    cr_assert_eq(create_history_tab(&sh, now), 0);
}

Test(create_history_tab_4, Return_Value_Test)
{
    time_t now = 0;
    sh_t sh;
    sh.buffer = strdup("");
    sh.hist.history = NULL;

    cr_assert_eq(create_history_tab(&sh, now), 0);
}