/*
** EPITECH PROJECT, 2019
** unit_test.c
** File description:
** unit_test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_extension_good, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-");

    cr_assert_eq(check_cd_tiret(&sh), 0);
}

Test(check_exit, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-");
    char *exe[] = {strdup("azri"), NULL};

    cr_assert_eq(check_exit(exe, &sh), 0);
}

Test(check_exit_test, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-");
    char *exe[] = {strdup("exit"), NULL};

    cr_assert_eq(check_exit(exe, &sh), 0);
}

Test(check_exit_test2, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-");
    char *exe[] = {strdup("exit"), my_strdup("1"),  NULL};

    cr_assert_eq(check_exit(exe, &sh), 1);
}

Test(verif_exit, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-");
    char *exe[] = {strdup("exit"), my_strdup("1a"),  NULL};

    cr_assert_eq(verif_exit(exe, &sh), 3);
}