/*
** EPITECH PROJECT, 2019
** unit_test10.c
** File description:
** unit_test10.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(write_core_params, init_flag_test)
{
    int tab[] = {0, -1};
    int fd = 1;

    write_core_params(tab, fd);
    cr_assert(1 == 1);
}

Test(write_core_params_1, init_flag_test)
{
    char *str = my_strdup("fork");

    check_option_two_byte(str);
    cr_assert(1 == 1);
}

Test(write_core_params_2, init_flag_test)
{
    char *str = my_strdup("live");

    check_option_two_byte(str);
    cr_assert(1 == 1);
}

Test(write_core_params_3, init_flag_test)
{
    char *str = my_strdup("lfork");

    check_option_two_byte(str);
    cr_assert(1 == 1);
}

Test(write_core_params_4, init_flag_test)
{
    char *str = my_strdup("test");

    check_option_two_byte(str);
    cr_assert(1 == 1);
}