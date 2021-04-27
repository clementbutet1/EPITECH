/*
** EPITECH PROJECT, 2018
** unit_test2.c
** File description:
** unit_test2.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include"../include/mysh.h"
#include "../include/my.h"

Test(check_unsetenv, Return_Value_Test)
{
    params_t params;
    params.envi = NULL;

    cr_assert_eq(check_unsetenv(&params), 11);
}

Test(check_same_begin, Return_Value_Test)
{
    char *first = "cd";
    char *scd = "cd";

    cr_assert_eq(check_same_begin(first, scd), 0);
}

Test(check_if_path, Return_Value_Test)
{
    params_t params;
    params.envi =malloc(sizeof(char *) * 2);
    params.envi[0] = "PATH";
    params.envi[1] = NULL;

    cr_assert_eq(check_if_path(&params), 0);
}

Test(my_count_word, Return_Value_Test)
{
    char *str = "je suis a epitech";
    char sepa = ' ';

    cr_assert_eq(my_count_word(str, sepa), 4);
}

Test(count_letter, Return_Value_Test)
{
    char *str = "epitech ";
    char sepa = ' ';
    int i = 0;

    cr_assert_eq(count_letter(str, sepa, i), 6);
}