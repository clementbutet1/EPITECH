/*
** EPITECH PROJECT, 2019
** unit_test15.c
** File description:
** unit_test15.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "asm.h"

Test(create_file_and_write_4, init_flag_test)
{
    params_t params;
    core_t core;
    instu_core_t *instru = NULL;
    params.comment = my_strdup("test");
    params.name = my_strdup("test");
    char *av[] = {my_strdup("./asm"), my_strdup("test.s"), NULL};
    char *file[] = {my_strdup(".name \n"), my_strdup(".comment \n"),
        my_strdup("sti r1, :hji, %1\n"), my_strdup("hji:	live %234\n"),
        my_strdup("ld %0, r3\n"), my_strdup("zjmp %:hji\n"),
        my_strdup("ld %1, r2\n"), NULL};
    char ** test = clean_file(file, &params);
    get_magic_int(&params);
    get_all_label(test, &params);
    encode_name_coment(&params, &core);
    params.fd = create_file(av[1]);
    create_file_and_write(&params, &core, &instru, file);
    cr_assert(1 == 1);
}