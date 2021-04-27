/*
** EPITECH PROJECT, 2019
** unit_test5.c
** File description:
** unit_test5.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(base_hexadecima_to_int_tab, init_flag_test)
{
    int i[] = {0, -1};
    int j = 1;
    char *rslt = "1D";
    base_hexadecima_to_int_tab(rslt, j, i);

    cr_assert(1 == 1);
}

Test(create_magic_tab, init_flag_test)
{
    int size = 4;
    char *rslt = "11";
    create_magic_tab(rslt, size);

    cr_assert(1 == 1);
}

Test(create_magic_tab_for_int, init_flag_test)
{
    int size = 4;
    int nb = 11;
    create_magic_tab_for_int(nb, size);

    cr_assert(1 == 1);
}

Test(encode, init_flag_test)
{
    int size = 4;
    char *str = my_strdup("1D");
    encode(str, size);

    cr_assert(1 == 1);
}

Test(encode_name_coment, init_flag_test)
{
    params_t pa;
    core_t co;
    pa.name = my_strdup("abel.s");
    pa.comment = my_strdup("l'arme est noir");
    encode_name_coment(&pa, &co);

    cr_assert(1 == 1);
}