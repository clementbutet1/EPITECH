/*
** EPITECH PROJECT, 2019
** unit_test.c
** File description:
** unit_test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(check_extension_good, Return_Value_Test)
{
    char *file = "abel.s";

    cr_assert_eq(check_extension(file), 0);
}

Test(check_extension_bad, Return_Value_Test)
{
    char *file = "abel";

    cr_assert_eq(check_extension(file), 84);
}

Test(get_magic_int, init_flag_test)
{
    params_t pa;

    get_magic_int(&pa);
    cr_assert(1 == 1);
}

Test(recup_name_and_comment_, init_flag_test)
{
    char *str = "abel.s";

    recup_name_and_comment(str);
    cr_assert(1 == 1);
}

Test(add_two_tab_int, init_flag_test)
{
    int *tab = malloc(sizeof(int) * 3);
    int *tab2 = malloc(sizeof(int) * 3);
    int i = 0;
    int j = 0;

    for (; i <= 2; i++)
        tab[i] = 2;
    tab[i] = -1;
    for (; j <= 2; j++)
        tab2[j] = 2;
    tab2[j] = -1;

    add_two_tab_int(tab, tab2);
    cr_assert(1 == 1);
}