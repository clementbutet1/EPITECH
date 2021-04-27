/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(find_size_alias_name, Return_Value_Test)
{
    int i = 0;
    char *str = strdup(" ls");

    cr_assert_eq(find_size_alias_name(str, i), 1);
}

Test(find_pos_alias_name, Return_Value_Test)
{
    char *str = strdup("    ls");

    cr_assert_eq(find_pos_alias_name(str), 4);
}

Test(my_strlen_alias, Return_Value_Test)
{
    char *str = strdup("ls");

    cr_assert_eq(my_strlen_alias(str, 0), 2);
}

Test(my_strlen_alias_2, Return_Value_Test)
{
    char *str = strdup("ls");

    cr_assert_eq(my_strlen_alias(str, 1), 0);
}

Test(find_alias_name_buff, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("jul\tls"), NULL};
    sh.alias.alias = tb;
    char *str2 = strdup("ls");

    cr_assert_eq(find_alias_name_buff(str2, &sh), str2);
}