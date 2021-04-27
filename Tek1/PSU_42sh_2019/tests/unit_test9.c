/*
** EPITECH PROJECT, 2019
** unit_test9.c
** File description:
** unit_test9.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(my_strcat_slash_2, Return_Value_Test)
{
    char *str = my_strdup("b/a");
    char *name = strdup("a/");
    char *file = strdup("b");

    cr_assert_not(my_strcat_slash(file, name) == str);
}

Test(error_find_main, Return_Value_Test)
{
    int s = 1;
    sh_t sh;
    sh.path.home = NULL;

    cr_assert_eq(error_find_main(&sh, s), 3);
}

Test(error_find_main_2, Return_Value_Test)
{
    int s = 0;
    sh_t sh;
    sh.path.home = strdup("test");

    cr_assert_eq(error_find_main(&sh, s), 2);
}

Test(find_main_directory, Return_Value_Test)
{
    int s = 0;
    sh_t sh;
    char *tb[] = {strdup("HOME=test"), strdup("test"), NULL};
    sh.path.env = tb;
    sh.path.home = strdup("test");

    cr_assert_eq(find_main_directory(&sh, s), 2);
}

Test(find_main_directory_3, Return_Value_Test)
{
    int s = 1;
    sh_t sh;
    char *tb[] = {strdup("HOMEtest"), strdup("test"), NULL};
    sh.path.env = tb;
    sh.path.home = NULL;

    cr_assert_eq(find_main_directory(&sh, s), 3);
}