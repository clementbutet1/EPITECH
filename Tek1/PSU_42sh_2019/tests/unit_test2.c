/*
** EPITECH PROJECT, 2019
** unit_test2.c
** File description:
** unit_test2.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(verif_exit_te, Return_Value_Test)
{
    sh_t sh;
    sh.repertoire = strdup("-");
    char *exe[] = {strdup("exit"), my_strdup("1"),  NULL};

    cr_assert_eq(verif_exit(exe, &sh), 1);
}

Test(verif_type, Return_Value_Test)
{
    sh_t sh;
    char *exe[] = {strdup(""), my_strdup(""),  NULL};

    cr_assert_eq(verif_type(exe, &sh), -1);
}

Test(verif_typetest_2, Return_Value_Test)
{
    sh_t sh;
    sh.path.path = NULL;
    char *exe[] = {strdup("./lib"), my_strdup("cc"),  NULL};

    cr_assert_eq(verif_type(exe, &sh), -1);
}

Test(verif_type2, Return_Value_Test)
{
    sh_t sh;
    sh.path.path = NULL;
    char *exe[] = {strdup("./lib"), my_strdup("cc"),  NULL};

    cr_assert_eq(verif_type2(exe, &sh), -1);
}

Test(verif_type_test2, Return_Value_Test)
{
    sh_t sh;
    sh.path.path = NULL;
    char *exe[] = {strdup("unit_tests"), my_strdup("cc"),  NULL};

    cr_assert_eq(verif_type2(exe, &sh), 0);
}