/*
** EPITECH PROJECT, 2019
** unit_test3.c
** File description:
** unit_test3.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(is_a_directory_test, Return_Value_Test)
{
    char *exe[] = {strdup("./lib"), my_strdup("cc"),  NULL};

    cr_assert_eq(is_a_directory(exe), -1);
}

Test(is_a_directory_test2, Return_Value_Test)
{
    char *exe[] = {strdup("./unit_tests"), my_strdup("cc"),  NULL};

    cr_assert_eq(is_a_directory(exe), 0);
}

Test(is_a_directory_test3, Return_Value_Test)
{
    char *exe[] = {strdup("./unit_tests"), my_strdup("cc"),  NULL};

    cr_assert_eq(is_a_directory(exe), 0);
}

Test(my_strlen_redirection, Return_Value_Test)
{
    char *str = strdup("echo test > a");

    cr_assert_eq(my_strlen_redirection(str), 13);
}

Test(my_str_to_word_array_mysh, Return_Value_Test)
{
    char *str = strdup("ls");
    char *tb[] = {strdup("ls"), NULL};

    cr_assert_not(my_str_to_word_array_mysh(str, ' ') == tb);
}