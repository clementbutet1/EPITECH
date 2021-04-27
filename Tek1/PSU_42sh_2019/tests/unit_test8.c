/*
** EPITECH PROJECT, 2019
** unit_test8.c
** File description:
** unit_test8.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_arg_par_4, Return_Value_Test)
{
    char *str = my_strdup("(ls)");
    int p = 0;
    int q = 0;

    cr_assert_eq(check_arg_par(str, &q, &p), 0);
}

Test(in_parenth, Return_Value_Test)
{
    char *str = my_strdup("(ls)");
    int p = 1;

    cr_assert_eq(in_parenth(str, p), 0);
}

Test(in_parenth2, Return_Value_Test)
{
    char *str = my_strdup("(ls)");
    int p = 2;

    cr_assert_eq(in_parenth(str, p), 1);
}

Test(my_strcat, Return_Value_Test)
{
    char *str = my_strdup("ba");
    char *name = strdup("a");
    char *file = strdup("b");

    cr_assert_not(my_strcat(file, name) == str);
}

Test(my_strcat_slash, Return_Value_Test)
{
    char *str = my_strdup("b/a");
    char *name = strdup("a");
    char *file = strdup("b");

    cr_assert_not(my_strcat_slash(file, name) == str);
}