/*
** EPITECH PROJECT, 2019
** unit_test23.c
** File description:
** unit_test23.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_redirection_1, Return_Value_Test)
{
    sh_t sh;
    sh.buffer = strdup("cd || ls");
    sh.spipe.is_double_and = 0;
    sh.spipe.double_and = strdup("TEST");
    char *tb[] = {strdup("exit"), NULL};
    char *tb1[] = {strdup("ls"), strdup("cd src"), NULL};
    sh.alias.alias = tb1;
    char **e[] = {tb, tb1, NULL};
    sh.exe = e;
    sh.pipe = tb;
    sh.spipe.fd_out = 0;
    sh.spipe.fd_in = 0;
    char *t[] = {strdup("ls"), NULL};

    cr_assert_eq(check_redirection(t, &sh, 10), t);
}

Test(check_global, Return_Value_Test)
{
    char *tb[] = {strdup("ls"), NULL};

    cr_assert_eq(check_global(tb), tb);
}

Test(check_global_1, Return_Value_Test)
{
    char *tb[] = {strdup("ls"), NULL};

    cr_assert_eq(check_global(tb), tb);
}

Test(check_set_1, Return_Value_Test)
{
    char *tb1[] = {strdup("erte"), strdup("test=test"), NULL};
    print_tab(tb1);
    sh_t sh;
    char *str = strdup("set");

    cr_assert_eq(check_set(tb1, &sh, str), 0);
}

Test(check_set_2, Return_Value_Test)
{
    sh_t sh;
    char *tb1[] = {strdup("set"), NULL};
    sh.set = tb1;
    print_tab(tb1);
    char *str = strdup("set");

    cr_assert_eq(check_set(tb1, &sh, str), 1);
}