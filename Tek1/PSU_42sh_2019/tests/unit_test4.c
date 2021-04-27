/*
** EPITECH PROJECT, 2019
** unit_test4.c
** File description:
** unit_test4.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(my_str_to_word_array_mysh2, Return_Value_Test)
{
    char *str = strdup("ls");

    cr_assert_eq(my_str_to_word_array_mysh2(str, ' '), 0);
}

Test(check_alias_name, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("jul");
    char *tb[] = {strdup("jul   ls"), NULL};

    sh.alias.alias = tb;
    cr_assert_not(check_alias_name(str, &sh) == 1);
}

Test(check_alias_name2, Return_Value_Test)
{
    sh_t sh;
    char *str = strdup("jul");
    char *tb[] = {NULL};

    sh.alias.alias = tb;
    cr_assert_not(check_alias_name(str, &sh) != -1);
}

Test(test_free_all, Return_Value_Test)
{
    char **test = malloc(sizeof(char *) * 10);
    test[10] = NULL;

    cr_assert_eq(free_all(test), 0);
}