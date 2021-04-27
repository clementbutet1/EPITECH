/*
** EPITECH PROJECT, 2019
** unit_test19.c
** File description:
** unit_test19.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_cd_tiret, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-");

    cr_assert_eq(check_cd_tiret(&sh), 0);
}

Test(check_cd_tiret_2, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup(" test");

    cr_assert_eq(check_cd_tiret(&sh), 0);
}

Test(check_cd_tiret_3, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-test -");

    cr_assert_eq(check_cd_tiret(&sh), 0);
}

Test(check_cd_tiret21, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("OLDPWD=test"), strdup("test"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");
    char *str = strdup("test");
    sh.repertoire = strdup("~test1");
    check_cd_tiret2(&sh);
    cr_assert_not(sh.path.oldpwd ==  str);
}

Test(check_alias, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("OLDPWD=test"), strdup("test"), NULL};
    char *al[] = {strdup("OLDPWD=test"), strdup("test"), NULL};
    sh.alias.alias = al;
    char *exe[] = {strdup("test"), strdup("jul"), strdup("ls"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");
    sh.repertoire = strdup("~test1");
    cr_assert_eq(check_alias(exe, &sh), 0);
}