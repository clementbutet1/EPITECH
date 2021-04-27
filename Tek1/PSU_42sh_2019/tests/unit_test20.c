/*
** EPITECH PROJECT, 2019
** unit_test20.c
** File description:
** unit_test20.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_alias1, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("OLDPWD=test"), strdup("test"), NULL};
    char *al[] = {strdup("OLDPWD    ls"), strdup("test"), NULL};
    sh.alias.alias = al;
    char *exe[] = {strdup("alias"), strdup("OLDPWD"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");
    sh.repertoire = strdup("~test1");
    cr_assert_eq(check_alias(exe, &sh), 1);
}

Test(check_buffer, Return_Value_Test)
{
    sh_t sh;
    time_t now = 0;
    sh.buffer = strdup("");

    cr_assert_eq(check_buffer(&sh, now), 0);
}

Test(check_error_pipe, Return_Value_Test)
{
    sh_t sh;
    sh.buffer = strdup("||");

    cr_assert_eq(check_error_pipe(sh.buffer), 1);
}

Test(check_error_pipe_1, Return_Value_Test)
{
    sh_t sh;
    sh.buffer = strdup("cd || ls");

    cr_assert_eq(check_error_pipe(sh.buffer), 0);
}