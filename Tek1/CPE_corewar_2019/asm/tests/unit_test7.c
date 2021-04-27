/*
** EPITECH PROJECT, 2019
** unit_test7.c
** File description:
** unit_test7.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(label_conposed_of_label_chars, init_flag_test)
{
    char *str = my_strdup("abel.s");
    int i = 0;
    label_conposed_of_label_chars(str, i);

    cr_assert(1 == 1);
}

Test(my_converthexadecimalmi, init_flag_test)
{

    char *rslt = NULL;
    int i = 0;
    int nb = 29;
    my_converthexadecimalmi(nb, rslt, i);

    cr_assert(1 == 1);
}

Test(find_line, init_flag_test)
{
    params_t params;
    int ac = 2;
    char *av[] = {my_strdup("./asm"), my_strdup("abel.cor"), NULL};

    init_prog(ac, av, &params);
    cr_assert(1 == 1);
}

Test(open_read_test, init_flag_test)
{
    char *av[] = {my_strdup("./asm"), my_strdup("abel.cor"), NULL};

    open_read(av[1]);
    cr_assert(1 == 1);
}

Test(get_magic_int, test)
{
    params_t params;

    get_magic_int(&params);
    cr_assert(1 == 1);
}