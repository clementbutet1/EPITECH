/*
** EPITECH PROJECT, 2019
** unit_test31.c
** File description:
** unit_test31.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_history_2, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("history");
    char *tb[] = {strdup("history"), NULL};
    char *h[] = {strdup("ls"), strdup("cd"), NULL};
    char *heu[] = {strdup("ls"), strdup("cd"), NULL};
    char *min[] = {strdup("ls"), strdup("cd"), NULL};
    sh.hist.h = heu;
    sh.hist.min = min;
    sh.hist.history = h;

    cr_assert_eq(check_history(tb, &sh, str, 0), 1);
}

Test(check_arg_1, Return_Value_Test)
{
    char *str = strdup("history");

    cr_assert_eq(check_arg(str), 1);
}

Test(check_arg_2, Return_Value_Test)
{
    char *str = strdup("1");

    cr_assert_eq(check_arg(str), 0);
}