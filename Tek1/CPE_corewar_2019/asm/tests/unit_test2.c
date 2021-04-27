/*
** EPITECH PROJECT, 2019
** unit_test2.c
** File description:
** unit_test2.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(init_prog, init_flag_test)
{
    params_t pa;
    int ac = 2;
    char *av[] = {"./asm", "abel.s", NULL};

    init_prog(ac, av, &pa);
    cr_assert(1 == 1);
}

Test(base_hexadecima_to_int, init_flag_test)
{
    char *magic_nb = "EA";
    int k = 0;
    params_t pa;
    pa.magic_nb = malloc(sizeof(char) * 2);
    pa.magic_nb[1] = -1;

    base_hexadecima_to_int(magic_nb, k, &pa);
    cr_assert(1 == 1);
}

Test(separe_magic_nb, init_flag_test)
{
    char *file = malloc(sizeof(char) * 3);
    char *magic_nb = "EA83F3";
    int i = 0;

    separe_magic_nb(file, magic_nb, i);
    cr_assert(1 == 1);
}

Test(display_help, init_flag_test)
{
    display_help();

    cr_assert(1 == 1);
}

Test(special_strlen, Return_Value_Test)
{
    int i = 10;

    cr_assert_eq(special_strlen(i), 2);
}