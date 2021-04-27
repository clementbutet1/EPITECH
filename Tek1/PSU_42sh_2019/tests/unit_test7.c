/*
** EPITECH PROJECT, 2019
** unit_test7.c
** File description:
** unit_test7.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(my_strcpy_spe, Return_Value_Test)
{
    char *str2 = my_strdup("DISPLAY=10.20.86.103:0");
    char *f = strdup("10.20.86.103:0");

    cr_assert_not(my_strcpy_spe(str2, 8) == f);
}

Test(my_strncpy, Return_Value_Test)
{
    char *str = malloc(sizeof(char) * 16);
    char *str2 = my_strdup("DISPLAY=10.20.86.103:0");
    char *f = strdup("10.20.86.103:0");

    cr_assert_not(my_strncpy(str, str2, 8) == f);
}

Test(check_arg_par, Return_Value_Test)
{
    char *str = my_strdup("(ls)");
    int p = 2;
    int q = 3;

    cr_assert_eq(check_arg_par(str, &q, &p), 1);
}

Test(check_arg_par_2, Return_Value_Test)
{
    char *str = my_strdup("(ls)");
    int p = 3;
    int q = 2;

    cr_assert_eq(check_arg_par(str, &q, &p), 1);
}

Test(check_arg_par_3, Return_Value_Test)
{
    char *str = my_strdup("(ls)");
    int p = 1;
    int q = 1;

    cr_assert_eq(check_arg_par(str, &q, &p), 1);
}