/*
** EPITECH PROJECT, 2019
** unit_test10.c
** File description:
** unit_test10.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(find_main_directory_4, Return_Value_Test)
{
    int s = 0;
    sh_t sh;
    char *tb[] = {strdup("HOMEtest"), strdup("test"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");

    cr_assert_eq(find_main_directory(&sh, s), 2);
}

Test(check_cd, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("cd"), strdup("lib"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");

    cr_assert_eq(check_cd(tb, &sh), 1);
}

Test(check_cd_2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("c"), strdup("lib"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");

    cr_assert_eq(check_cd(tb, &sh), 0);
}

Test(check_cd_3, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("ca"), strdup("lib"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");

    cr_assert_eq(check_cd(tb, &sh), 0);
}

Test(check_cd_4, Return_Value_Test)
{
    sh_t sh;
    char *tbm[] = {strdup("cd"), NULL};
    char *tb[] = {strdup("c"), strdup("lib"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");
    sh.path.env = tb;
    sh.path.home = strdup("test");

    cr_assert_eq(check_cd(tbm, &sh), 2);
}