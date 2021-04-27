/*
** EPITECH PROJECT, 2019
** unit_test6.c
** File description:
** unit_test6.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(error_label, init_flag_test)
{
    char *str = my_strdup("sti r1, :hji, 1");
    int i = 8;
    char *label = my_strdup("abcdefghijklmnopqrstuvwxyz_0123456789");
    error_label(str, i, label);

    cr_assert(1 == 1);
}

Test(open_read, init_flag_test)
{
    char *str = my_strdup("abel.s");
    open_read(str);

    cr_assert(1 == 1);
}

Test(check_extension, init_flag_test)
{
    char *str = my_strdup("abel.s");
    check_extension(str);

    cr_assert(1 == 1);
}

Test(write_one_element, init_flag_test)
{
    char *str = my_strdup("abel.s");
    char **tab = NULL;
    int i = 0;
    write_one_element(tab, str, i);

    cr_assert(1 == 1);
}

Test(init_prog_2, init_flag_test)
{
    int ac = 2;
    char *tab[] = {my_strdup("./asm"), my_strdup("-h"), NULL};
    params_t pa;
    init_prog(ac, tab, &pa);

    cr_assert(1 == 1);
}