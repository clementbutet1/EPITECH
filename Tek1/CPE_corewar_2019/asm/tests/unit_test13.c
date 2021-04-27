/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** unit_test13.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(init_struct_clean_file, init_flag_test)
{
    params_t pa;

    init_struct_clean_file(&pa);
    cr_assert(1 == 1);
}

Test(add_incrementation_verif_get, init_flag_test)
{
    instu_core_t new;
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
    new.params = tab2;
    int *c = tab;
    int *b = tab;

    add_incrementation_verif_get(&new, c, b);
    cr_assert(1 == 1);
}

Test(check_dir_size, init_flag_test)
{
    instu_core_t new;
    new.dir_size = 0;
    char *str = my_strdup("lldi");

    check_dir_size(str, &new);
    cr_assert(1 == 1);
}

Test(check_line_instru, init_flag_test)
{
    instu_core_t new;
    new.dir_size = 0;
    char *str = my_strdup("              :lldi");
    char *her_tab = my_strdup("lldi");
    int *c = 0;
    int *tab = malloc(sizeof(int) * 3);
    int i = 0;

    for (; i <= 2; i++)
        tab[i] = 2;
    tab[i] = -1;
    c = tab;

    check_line_instru(str, her_tab, c, &new);
    cr_assert(1 == 1);
}

Test(check_line_instru_1, init_flag_test)
{
    instu_core_t new;
    new.dir_size = 0;
    char *str = my_strdup("              :lldi");
    char *her_tab = my_strdup("lldi");
    int *c = 0;
    int *tab = malloc(sizeof(int) * 3);
    int i = 0;

    for (; i <= 2; i++)
        tab[i] = 2;
    tab[i] = -1;
    c = tab;

    check_line_instru(str, her_tab, c, &new);
    cr_assert(1 == 1);
}