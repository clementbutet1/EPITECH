/*
** EPITECH PROJECT, 2019
** unit_test22.c
** File description:
** unit_test22.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_buffer_3, Return_Value_Test)
{
    sh_t sh;
    sh.buffer = strdup("cd || ls");
    char *tb[] = {strdup("exit"), NULL};
    char *tb1[] = {strdup("ls"), strdup("cd src"), NULL};
    sh.alias.alias = tb1;
    char **e[] = {tb, tb1, NULL};
    sh.exe = e;
    sh.pipe = tb;

    cr_assert_eq(check_buffer3(&sh, tb), 1);
}

Test(execute_double_and, Return_Value_Test)
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

    cr_assert_eq(execute_double_and(&sh), 0);
}

Test(check_double_and, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("ls && cd src");
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

    cr_assert_not(check_double_and(str, &sh) != str);
}

Test(check_double_and_1, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("cd src");
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

    cr_assert_eq(check_double_and(str, &sh), str);
}

Test(check_double_and_5, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("ls && cd src");
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

    cr_assert_eq(check_double_and(str, &sh), str);
}