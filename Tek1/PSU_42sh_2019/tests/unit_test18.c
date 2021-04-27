/*
** EPITECH PROJECT, 2019
** unit_test18.c
** File description:
** unit_test18.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"



Test(verif_wave, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("te~st");
    char *tb[] = {strdup("OLDPWD=test"), strdup("test"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("HOME=test");
    char *str = strdup("test1");
    verif_wave(&sh);
    cr_assert(str != sh.repertoire);
}

Test(copy_string_1, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("test1");
    char *str = strdup("test");
    copy_string(&sh, str);
    cr_assert_not(str != sh.repertoire);
}

Test(copy_string_2, Return_Value_Test)
{
    sh_t sh;
    sh.path.home = strdup("home");
    sh.repertoire = strdup("te~st1");
    char *str = strdup("test");
    copy_string(&sh, str);
    cr_assert_not(str != sh.repertoire);
}

Test(check_cd_tiret2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("HOMEtest"), strdup("test"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");
    sh.repertoire = strdup("~test1");
    check_cd_tiret2(&sh);
    cr_assert_not(sh.path.oldpwd == NULL);
}