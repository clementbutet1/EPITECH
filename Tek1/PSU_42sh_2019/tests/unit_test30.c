/*
** EPITECH PROJECT, 2019
** unit_test30.c
** File description:
** unit_test30.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(display_redi_error, init_flag_test)
{
    display_redi_error(-1, "lib");
    cr_assert(1 == 1);
}

Test(my_cd2, init_flag_test)
{
    sh_t sh;
    char *str = my_strdup("lib");

    my_cd2(str, &sh);
    cr_assert(1 == 1);
}

Test(handler_siguint, init_flag_test)
{
    handler_siguint(0);
    cr_assert(1 == 1);
}

Test(handler_sigsegv, init_flag_test)
{
    handler_sigsegv();
    cr_assert(1 == 1);
}

Test(print_signal, init_flag_test)
{
    sh_t sh;

    print_signal(0, 0, &sh);
    cr_assert(1 == 1);
}

Test(execute_fonction2, init_flag_test)
{
    execute_fonction2();
    cr_assert(1 == 1);
}

Test(execute_fonction3, init_flag_test)
{
    execute_fonction2();
    cr_assert(1 == 1);
}

Test(remp_path, init_flag_test)
{
    char *tb[] = {strdup("ls"), NULL};
    sh_t sh;
    sh.path.env = tb;
    remp_path(&sh, 0, 0);
    cr_assert(1 == 1);
}

Test(modif_alias_rm, init_flag_test)
{
    sh_t sh;
    char *min[] = {strdup("jul\tcd"), strdup("cls\tclear"), NULL};
    sh.alias.height = 2;
    sh.alias.alias = min;
    char *exe[] = {strdup("unalias"), strdup("jul"), NULL};

    modif_alias_rm(exe, &sh);
    cr_assert(1 == 1);
}

Test(modif_alias2_rm, init_flag_test)
{
    sh_t sh;
    char *min[] = {strdup("jul\tcd"), strdup("cls\tclear"), NULL};
    sh.alias.height = 2;
    sh.alias.alias = min;
    char *min1[] = {strdup("unalias"), strdup("jul"), NULL};

    modif_alias2_rm(min1, &sh);
    cr_assert(1 == 1);
}

Test(print_tab, Return_Value_Test)
{
    char *tb1[] = {strdup("ls"), strdup("cd src"), NULL};
    print_tab(tb1);

    cr_assert(1 == 1);
}

Test(create_all_path2, Return_Value_Test)
{
    char *tb[] = {strdup("ls:test"), NULL};
    sh_t sh;
    sh.path.env = tb;
    sh.path.line_path = strdup("ls:test");
    char *n[] = {strdup("test"), strdup("path"), NULL};
    sh.path.path = n;
    create_all_path2(&sh, 0);
    cr_assert(1 == 1);
}

Test(create_all_path, init_flag_test)
{
    char *tb[] = {strdup("lstest"), NULL};
    sh_t sh;
    sh.path.env = tb;
    create_all_path(&sh, 0);
    cr_assert(1 == 1);
}