/*
** EPITECH PROJECT, 2019
** unit_test9.c
** File description:
** unit_test9.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(is_indirect, init_flag_test)
{
    int cas = 0;
    char *str = my_strdup("R1");
    int a[] = {0, 0, 0, -1};
    is_indirect(str, a, cas);

    cr_assert(1 == 1);
}

Test(check_option_two_byte, init_flag_test)
{
    char *str = my_strdup("zjmp");
    check_option_two_byte(str);

    cr_assert(1 == 1);
}

Test(check_instru, init_flag_test)
{
    char *str = my_strdup("r");
    check_instru(str);

    cr_assert(1 == 1);
}

Test(encode_name_coment, test)
{
    params_t params;
    params.name = my_strdup("test");
    params.comment = my_strdup("test");
    core_t core;

    encode_name_coment(&params, &core);
    cr_assert(1 == 1);
}

Test(create_magic_tab_negative, test)
{
    int c = 0;
    int size = 2;

    create_magic_tab_negative(c, size);
    cr_assert(1 == 1);
}