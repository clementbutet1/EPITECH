/*
** EPITECH PROJECT, 2019
** unit_test17.c
** File description:
** unit_test17.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"


Test(find_path_1, Return_Value_Test)
{
    sh_t sh;
    char *tb[] = {strdup("PATH=test"), NULL};
    sh.path.env = tb;

    cr_assert_eq(find_path(&sh), 0);
}

