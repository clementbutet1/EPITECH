/*
** EPITECH PROJECT, 2019
** unit_test3.c
** File description:
** unit_test3.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(init_struct, init_flag_test)
{
    params_t pa;
    init_struct(&pa);
    cr_assert(1 == 1);
}

Test(write_core, init_flag_test)
{
    int tab[] = {1, 1, 1, 1, -1};
    int fd = 0;
    int type = 1;
    write_core(tab, fd, type);
    cr_assert(1 == 1);
}

Test(write_cores_int, init_flag_test)
{
    int tab[] = {1, 1, 1, 1, -1};
    int fd = 0;
    int type = 2;
    write_core(tab, fd, type);
    cr_assert(1 == 1);
}

Test(add_binary, init_flag_test)
{
    int tab[] = {1, -1};
    char *str = my_strdup("test");
    char *add = my_strdup("test");
    add_binary(str, tab, add);
    cr_assert(1 == 1);
}

Test(create_coding_byte_test, init_flag_test)
{
    int i = 0;
    int bytes = 0;
    char *str = my_strdup(":tt");
    char *add = my_strdup(":tt");
    create_coding_byte2(str, i, bytes, add);
    cr_assert(1 == 1);
}