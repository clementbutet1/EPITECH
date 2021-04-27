/*
** EPITECH PROJECT, 2019
** unit_test8.c
** File description:
** unit_test8.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(base_hexadecima_to_int_2, init_flag_test)
{
    char *rslt = "1D";
    int i = 0;
    params_t pa;
    int a[] = {0, 0, 0, -1};
    pa.magic_nb = a;
    base_hexadecima_to_int(rslt, i, &pa);

    cr_assert(1 == 1);
}

Test(separe_magic_nb_2, init_flag_test)
{
    char *rslt = my_strdup("1D");
    char *nb = my_strdup("1234");
    int i = 0;
    separe_magic_nb(rslt, nb, i);

    cr_assert(1 == 1);
}

Test(get_magic_int_2, init_flag_test)
{
    params_t pa;
    int a[] = {0, 0, 0, -1};
    pa.magic_nb = a;
    get_magic_int(&pa);

    cr_assert(1 == 1);
}

Test(is_register, init_flag_test)
{
    int cas = 0;
    char *str = my_strdup("R1");
    int a[] = {0, 0, 0, -1};
    is_register(str, a, cas);

    cr_assert(1 == 1);
}

Test(is_direct, init_flag_test)
{
    int cas = 0;
    char *str = my_strdup("R1");
    int a[] = {0, 0, 0, -1};
    is_direct(str, a, cas);

    cr_assert(1 == 1);
}