/*
** EPITECH PROJECT, 2019
** unit_test32.c
** File description:
** unit_test32.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(is_var_31, Return_Value_Test)
{
    char *str = strdup("$test\n");
    char *str1 = strdup("tt");

    cr_assert_eq(is_var(str, str1), 0);
}

Test(is_var41, Return_Value_Test)
{
    char *str = strdup("test\n");
    char *str1 = strdup("tt");

    cr_assert_eq(is_var(str, str1), 0);
}

Test(replace_env, Return_Value_Test)
{
    sh_t sh;
    char *name = strdup("PATH");
    char *str = strdup("test");
    char *tb[] = {strdup("PATH=test"), NULL};
    char *env[] = {strdup("PATH=ls"), NULL};
    sh.path.env = env;
    sh.taille_env = 1;
    sh.spipe.fd_out = 0;
    sh.spipe.fd_in = 0;
    replace_env(&sh, str, name);

    cr_assert_not(sh.path.env == tb);
}

Test(replace_env_2, Return_Value_Test)
{
    sh_t sh;
    char *name = strdup("PATH");
    char *str = strdup("test");
    char *tb[] = {strdup("HOME=test"), strdup("PATH=test"), NULL};
    char *env[] = {strdup("HOME=ls"), strdup("PATH=ls"), NULL};
    sh.path.env = env;
    sh.taille_env = 2;
    sh.spipe.fd_out = 0;
    sh.spipe.fd_in = 0;
    replace_env(&sh, str, name);

    cr_assert_not(sh.path.env == tb);
}

Test(replace_env_3, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("alias"), strdup("jul"), strdup("ls"), NULL};
    char *env[] = {NULL};
    char *al[] = {strdup("HOME=ls"), strdup("PATH=ls"), NULL};
    sh.alias.alias = al;
    sh.alias.height = 2;
    sh.alias.command = strdup("ls");
    sh.alias.new = strdup("jul");
    sh.alias.width = 2;
    sh.parenth = 1;
    sh.spipe.is_double_pipe = 0;
    sh.path.env = env;
    prepar_command(tb, &sh);

    cr_assert_not(sh.alias.alias == tb);
}

Test(alias_find_line_2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("alias"), strdup("jul"), strdup("ls"), NULL};
    char *env[] = {NULL};
    char *al[] = {strdup("HOME=ls"), strdup("PATH=ls"), NULL};
    sh.alias.alias = al;
    sh.alias.height = 2;
    sh.alias.command = strdup("ls");
    sh.alias.new = strdup("jul");
    sh.alias.width = 2;
    sh.parenth = 1;
    sh.spipe.is_double_pipe = 0;
    sh.path.env = env;
    alias_find_line(&sh, sh.alias.command);

    cr_assert_not(sh.alias.alias == tb);
}

Test(enter_alias_in_tab, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("alias"), strdup("jul"), strdup("ls"), NULL};
    char *env[] = {NULL};
    char *al[] = {strdup("HOME=ls"), strdup("PATH=ls"), NULL};
    sh.alias.alias = al;
    sh.alias.height = 2;
    sh.alias.command = strdup("ls");
    sh.alias.new = strdup("jul");
    sh.alias.width = 2;
    sh.parenth = 1;
    sh.spipe.is_double_pipe = 0;
    sh.path.env = env;
    enter_alias_in_tab(0, &sh, sh.alias.command);

    cr_assert_not(sh.alias.alias == tb);
}