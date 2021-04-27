/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "asm.h"

int main(int ac, char **av)
{
    params_t params;
    core_t core;
    instu_core_t *instru = NULL;
    char **file = NULL;

    init_prog(ac, av, &params);
    file = open_read(av[1]);
    if (file == NULL)
        return (84);
    file = clean_file(file, &params);
    recup_args(&params, file);
    get_magic_int(&params);
    encode_name_coment(&params, &core);
    get_all_label(file, &params);
    params.fd = create_file(av[1]);
    create_file_and_write(&params, &core, &instru, file);
    free_tab(file);
    free_struct(&params, &core, &instru);
    return (0);
}