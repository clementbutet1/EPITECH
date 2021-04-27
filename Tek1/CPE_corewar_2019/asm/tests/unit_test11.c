/*
** EPITECH PROJECT, 2019
** unit_test11.c
** File description:
** unit_test11.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(check_instru_2, init_flag_test)
{
    char *str = my_strdup("r");

    check_option_two_byte(str);
    cr_assert(1 == 1);
}

Test(check_instru_5, init_flag_test)
{
    char *str = my_strdup("%");

    check_option_two_byte(str);
    cr_assert(1 == 1);
}

Test(check_instru_4, init_flag_test)
{
    char *str = my_strdup("aaa");

    check_option_two_byte(str);
    cr_assert(1 == 1);
}

Test(check_tab, init_flag_test)
{
    char *tab[] = {my_strdup(".name \n"), my_strdup(".comment"), NULL};
    char *str = NULL;

    check_tab(tab, str);
    cr_assert(1 == 1);
}

Test(check_error_begin, init_flag_test)
{
    char *tab[] = {my_strdup(".name \n"), my_strdup(".comment "), NULL};

    check_error_begin(tab);
    cr_assert(1 == 1);
}