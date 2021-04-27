/*
** EPITECH PROJECT, 2019
** unit_test8.c
** File description:
** unit_test8.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(opentets, Return_Value_Test)
{
    params_t pa;
    pipe_t p;
    char *ls[] = {"/bin/ls", "-l", ">", NULL};
    char **tab[] = {ls, NULL};
    p.cmd = tab;
    p.k = 0;
    int i = 0;
    pa.env.envi = NULL;
    int op = 0;

    cr_assert_eq(check_final_pipe(&pa, &p, i, op), 84);
}

Test(check_invalid_cmd, Return_Value_Test)
{
    params_t pa;
    pipe_t p;
    char *ls[] = {">", "-l", ">", NULL};
    char **tab[] = {ls, NULL};
    p.cmd = tab;
    p.k = 0;
    pa.env.envi = NULL;
    int op = 0;

    cr_assert_eq(check_invalid_cmd(&p, op), 84);
}

Test(check_redirection_pipe, Return_Value_Test)
{
    params_t pa;
    pipe_t p;
    char *ls[] = {"/bin/ls", "-l", ">", "test", NULL};
    char **tab[] = {ls, NULL};
    p.cmd = tab;
    p.k = 0;
    int k = 0;
    pa.env.envi = NULL;

    cr_assert_eq(check_redirection_pipe(&pa, &p, k), 11);
}

Test(check_redirection_pipe_bad, Return_Value_Test)
{
    params_t pa;
    pipe_t p;
    char *ls[] = {">", "test", NULL};
    char **tab[] = {ls, NULL};
    p.cmd = tab;
    p.k = 0;
    int k = 0;
    pa.env.envi = NULL;

    cr_assert_eq(check_redirection_pipe(&pa, &p, k), 84);
}