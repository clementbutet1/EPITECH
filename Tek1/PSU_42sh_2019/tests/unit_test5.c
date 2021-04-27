/*
** EPITECH PROJECT, 2019
** unit_test5.c
** File description:
** unit_test5.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(free_end, Return_Value_Test)
{
    sh_t sh;
    sh.path.env = malloc(sizeof(char *) * 10);
    sh.path.env[10] = NULL;
    sh.alias.alias = malloc(sizeof(char *) * 10);
    sh.alias.alias[10] = NULL;
    sh.path.pwd = malloc(sizeof(char) * 10);
    sh.path.oldpwd = malloc(sizeof(char) * 10);

    cr_assert_eq(free_end(&sh), 0);
}

Test(error_redirection, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("test"), NULL};
    int i = 0;

    cr_assert_eq(error_redirection(tb, &sh, i), -1);
}

Test(error_redirection2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("test"), strdup("lib"), NULL};
    int i = 0;

    cr_assert_not(error_redirection(tb, &sh, i) == -1);
}

Test(error_redirection_2, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("test"), NULL};
    int i = 0;

    cr_assert_not(error_redirection2(tb, &i, &sh) != -1);
}

Test(error_redirection_3, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("test"), strdup("test"), NULL};
    int i = 0;

    cr_assert_not(error_redirection2(tb, &i, &sh) == -1);
}