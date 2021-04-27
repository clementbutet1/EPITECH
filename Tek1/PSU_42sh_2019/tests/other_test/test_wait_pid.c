/*
** EPITECH PROJECT, 2019
** test_wait_pid.c
** File description:
** test_wait_pid.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(write_core_params_spe, init_flag_test)
{
    sh_t sh;
    sh.pid = -1;

    wait_last_pid(&sh);
    cr_assert(1 == 1);
}

Test(write_core_params_nega, init_flag_test)
{
    sh_t sh;
    sh.pid = -10;

    wait_last_pid(&sh);
    cr_assert(1 == 1);
}

Test(write_core_params_posi, init_flag_test)
{
    sh_t sh;
    sh.pid = 1;

    wait_last_pid(&sh);
    cr_assert(1 == 1);
}