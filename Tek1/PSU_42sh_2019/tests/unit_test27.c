/*
** EPITECH PROJECT, 2019
** unit_test27.c
** File description:
** unit_test27.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_where, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("re"), strdup("a"), strdup("ls"), NULL};
    sh.set = NULL;
    sh.parenth = 0;

    cr_assert_eq(check_where(tb, &sh, "where", 0), 0);
}

Test(check_where_1, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("where"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh.path.env = env;
    sh.parenth = 0;
    sh.spipe.is_double_pipe = 0;

    cr_assert_eq(check_where(tb, &sh, "where", 0), 1);
}

Test(check_which, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("which"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh.path.env = env;
    sh.parenth = 0;
    sh.spipe.is_double_pipe = 0;

    cr_assert_eq(check_which(tb, &sh, "which", 0), 1);
}

Test(check_which_1, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("re"), strdup("a"), strdup("ls"), NULL};
    sh.set = NULL;
    sh.parenth = 0;

    cr_assert_eq(check_which(tb, &sh, "which", 0), 0);
}

Test(check_which_2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("which"), strdup("cd"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh.path.env = env;
    sh.parenth = 0;
    sh.spipe.is_double_pipe = 0;
    char *path[] = {strdup("/usr/local/sbin"), strdup(":/usr/local/bin"), strdup("/usr/sbin"), strdup("/usr/bin"), strdup("/sbin:/bin"), strdup("/root/.dotnet/tools"), NULL};
    sh.path.path = path;

    cr_assert_eq(check_which(tb, &sh, "which", 0), 1);
}