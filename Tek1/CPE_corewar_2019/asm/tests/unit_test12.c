/*
** EPITECH PROJECT, 2019
** unit_test12.c
** File description:
** unit_test12.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"


Test(check_tab_1, init_flag_test)
{
    char *tab[] = {my_strdup(".name \n"), my_strdup(".comment \n"), NULL};
    char *str = NULL;

    check_tab(tab, str);
    cr_assert(1 == 1);
}

Test(check_condi_magic_dir, init_flag_test)
{
    instu_core_t new;
    new.dir_size = 2;
    char *str = my_strdup("test");
    int c = -1;
    int *b = 0;

    check_condi_magic_dir(&new, str, c, b);
    cr_assert(1 == 1);
}

Test(check_condi_magic_dir_1, init_flag_test)
{
    instu_core_t new;
    new.dir_size = 2;
    char *str = my_strdup("test");
    int c = 1;
    int *b = 0;

    check_condi_magic_dir(&new, str, c, b);
    cr_assert(1 == 1);
}

Test(check_condi_magic_indi, init_flag_test)
{
    char *str = my_strdup("test");
    int c = 1;
    int *b = 0;

    check_condi_magic_indi(str, c, b);
    cr_assert(1 == 1);
}

Test(check_condi_magic_indi_1, init_flag_test)
{
    char *str = my_strdup("test");
    int c = -1;
    int *b = 0;

    check_condi_magic_indi(str, c, b);
    cr_assert(1 == 1);
}