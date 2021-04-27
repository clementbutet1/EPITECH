/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_core.c
*/

#include "asm.h"

void write_core_params(int *tab, int fd)
{
    for (int i = 0; tab[i] != -1; i++) {
        if (tab[i] < 0) {
            tab[i] += 2;
            write(fd, &tab[i], 1);
        }
        else {
            write(fd, &tab[i], 1);
        }
    }
    return;
}

void write_core_file(params_t *pa, core_t *co, instu_core_t **instru)
{
    int nb[] = {0, -1};
    int *prog;
    instu_core_t *tmp = *instru;

    write_core(nb, pa->fd, 1);
    write_core(pa->magic_nb, pa->fd, 1);
    write_core(co->name, pa->fd, 1);
    prog = create_magic_tab_for_int(pa->all_prog_size, 4);
    write_core(prog, pa->fd, 1);
    write_core(co->comment, pa->fd, 1);
    for (int a = 0; tmp != NULL; tmp = tmp->next, a++) {
        write_core(&tmp->instru, pa->fd, 2);
        if (tmp->coding_byte != -1)
            write_core(&tmp->coding_byte, pa->fd, 2);
        write_core_params(tmp->params, pa->fd);
    }
    return;
}

void create_file_and_write(params_t *params, core_t *core,
instu_core_t **instru, char **file)
{
    params->all_prog_size = get_all_instru(instru, file, params);
    change_label_to_nb(instru, params);
    write_core_file(params, core, instru);
    return;
}