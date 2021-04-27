/*
** EPITECH PROJECT, 2019
** unit_test28.c
** File description:
** unit_test28.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_which_3, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("which"), strdup("ls"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh.path.env = env;
    sh.parenth = 0;
    sh.spipe.is_double_pipe = 0;
    char *path[] = {strdup("/usr/local/sbin"), strdup(":/usr/local/bin"), strdup("/usr/sbin"), strdup("/usr/bin"), strdup("/sbin:/bin"), strdup("/root/.dotnet/tools"), NULL};
    sh.path.path = path;

    cr_assert_eq(check_which(tb, &sh, "which", 0), 1);
}

Test(check_where_3, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("where"), strdup("ls"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh.path.env = env;
    sh.parenth = 0;
    sh.spipe.is_double_pipe = 0;
    char *path[] = {strdup("/usr/local/sbin"), strdup(":/usr/local/bin"), strdup("/usr/sbin"), strdup("/usr/bin"), strdup("/sbin:/bin"), strdup("/root/.dotnet/tools"), NULL};
    sh.path.path = path;

    cr_assert_eq(check_where(tb, &sh, "where", 0), 1);
}

Test(check_where_4, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("where"), strdup("cd"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh.path.env = env;
    sh.parenth = 0;
    sh.spipe.is_double_pipe = 0;
    char *path[] = {strdup("/usr/local/sbin"), strdup(":/usr/local/bin"), strdup("/usr/sbin"), strdup("/usr/bin"), strdup("/sbin:/bin"), strdup("/root/.dotnet/tools"), NULL};
    sh.path.path = path;

    cr_assert_eq(check_where(tb, &sh, "where", 0), 1);
}

Test(copy_tab, Return_Value_Test)
{
    char *tb[] = {strdup("where"), strdup("cd"), NULL};

    cr_assert_not(copy_tab(tb) == tb);
}

Test(does_env_exist_1, Return_Value_Test)
{
    char *tb[] = {strdup("where"), strdup("PATH"), NULL};
    char *env[] = {strdup("PATH=test"), strdup("HOME=./"), NULL};
    sh_t sh;
    sh.path.env = env;

    cr_assert_eq(does_env_exist(tb, &sh), 0);
}
