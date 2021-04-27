/*
** EPITECH PROJECT, 2019
** unit_test6.c
** File description:
** unit_test6.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(error_redirection3, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("test"), strdup("test"), NULL};
    int i = 1;

    cr_assert_not(error_redirection3(tb, &i, &sh) != -1);
}

Test(error_redirection_3_2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("test"), strdup("test"), strdup("test"), NULL};
    int i = 0;

    cr_assert_not(error_redirection3(tb, &i, &sh) == -1);
}


Test(change_to_set_1, Return_Value_Test)
{
    char *tb[] = {strdup("test=test"), strdup("test=test"), NULL};
    char *tb2[] = {strdup("test=\test"), strdup("test\ttest"), NULL};

    cr_assert_not(change_to_set(tb) == tb2);
}

Test(set_line, Return_Value_Test)
{
    char *str = strdup("DOTNET_ROOT=/usr/lib64/dotnet");
    int i = 29;
    int k = 10;
    char *tb2[] = {strdup("DOTNET_ROOT"), strdup("/usr/lib64/dotnet"), NULL};

    cr_assert_not(set_line(i, str, k) == tb2);
}