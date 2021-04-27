/*
** EPITECH PROJECT, 2019
** unit_test21.c
** File description:
** unit_test21.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_buffer__2, Return_Value_Test)
{
    sh_t sh;
    sh.buffer = strdup("ls");
    char *tb[] = {strdup("ls"), NULL};
    char *tb1[] = {strdup("ls"), strdup("cd src"), NULL};
    sh.alias.alias = tb1;
    char **e[] = {tb, tb1, NULL};
    sh.exe = e;
    sh.parenth = 1;
    sh.pipe = tb;
    sh.spipe.fd_in = 0;
    sh.spipe.fd_out = 0;

    cr_assert_eq(check_buffer2(tb, &sh), 0);
}

Test(check_buffer3, Return_Value_Test)
{
    sh_t sh;
    sh.buffer = strdup("ls");
    char *tb[] = {strdup("ls"), NULL};
    char *tb1[] = {strdup("ls"), strdup("cd src"), NULL};
    sh.alias.alias = tb1;
    char **e[] = {tb, tb1, NULL};
    sh.exe = e;
    sh.parenth = 1;
    sh.pipe = tb;
    sh.spipe.fd_in = 0;
    sh.spipe.fd_out = 0;

    cr_assert_eq(check_buffer2(tb, &sh), 0);
}


Test(check_set, Return_Value_Test)
{
    char *tb1[] = {strdup("set"), strdup("test=test"), NULL};
    print_tab(tb1);
    sh_t sh;
    char *str = strdup("set");

    cr_assert_eq(check_set(tb1, &sh, str), 1);
}