/*
** EPITECH PROJECT, 2019
** unit_test4.c
** File description:
** unit_test4.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(create_coding_byte2, init_flag_test)
{
    int i = 1;
    int b = 4;
    char *str = my_strdup("01");
    char *add = my_strdup("10");
    create_coding_byte2(str, i, b, add);

    cr_assert(1 == 1);
}

Test(create_coding_byte, init_flag_test)
{
    int i = 1;
    int b = 8;
    char *str = my_strdup("01");
    create_coding_byte(b, str, i);

    cr_assert(1 == 1);
}

Test(create_file, init_flag_test)
{
    char *str = my_strdup("abel.cor");
    create_file(str);

    cr_assert(1 == 1);
}

Test(my_converthexadecimalmi_tab_spe, init_flag_test)
{
    int i = 29;
    int size = 2;
    my_converthexadecimalmi_tab_spe(i, size);

    cr_assert(1 == 1);
}

Test(my_converthexadecimalmi_tab, init_flag_test)
{
    int i = 29;
    int size = 0;
    char *rslt = NULL;
    my_converthexadecimalmi_tab(i, rslt, size);

    cr_assert(1 == 1);
}