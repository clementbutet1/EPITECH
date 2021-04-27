/*
** EPITECH PROJECT, 2019
** create_tab_ins.c
** File description:
** create_tab_ins.c
*/

#include "corewar.h"

int fill_params(instru_t *instru, char *base2, int *len)
{
    for (int i = 0, a = 0; i < MAX_ARGS_NUMBER; i++) {
        if (my_strncmp(&base2[i * 2], "00", 2) == 0 && a > 0) {
            return (-1);
        }
        if (check_type(&base2[i * 2], "01", len) > 0)
            instru->params[i] = 'r';
        else if (check_type(&base2[i * 2], "10", len) > 0)
            instru->params[i] = 'd';
        if (check_type(&base2[i * 2], "11", len) > 0)
            instru->params[i] = 'i';
        if (my_strncmp(&base2[i * 2], "00", 2) == 0) {
            a++;
        }
    }
    return (0);
}

int init_tab_ins(champ_t *champion, corewar_t *core, instru_t *instru)
{
    int len = 0;
    char *base2;

    if (check_option_two_byte(instru->memonic) != 0) {
        option_two_byte(instru);
        instru->is_coding_byte = 0;
    } else {
        instru->is_coding_byte = 1;
        base2 = my_conver_base2(core->arena.arena[(champion->pc + 1) %
        MEM_SIZE], 8);
        if (fill_params(instru, base2, &len) < 0)
            return (-1);
        instru->tab_ins = malloc(sizeof(int *) * (len + 3));
    }
    return (len + 2);
}

void fill_tab_ins(champ_t *champion, corewar_t *core, instru_t *instru)
{
    int d = 0;
    int pc = champion->pc;

    instru->tab_ins[d++] = malloc(sizeof(int) * 2);
    if (instru->is_coding_byte == 1)
        instru->tab_ins[d++] = malloc(sizeof(int) * 2);
    for (int size = 0, i = 0; d < instru->size_instru; d++, i++) {
        size = what_type(instru->params[i], instru->dir_size);
        instru->tab_ins[d] = malloc(sizeof(int) * (size + 1));
    }
    instru->tab_ins[d] = NULL;
    d = 0;
    copy_int_star(core->arena.arena, instru->tab_ins[d++], &pc, 1);
    if (instru->is_coding_byte == 1)
        copy_int_star(core->arena.arena, instru->tab_ins[d++], &pc, 1);
    for (int i = 0; d < instru->size_instru; d++, i++)
        copy_int_star(core->arena.arena,
        instru->tab_ins[d], &pc, what_type(instru->params[i],
        instru->dir_size));
}

instru_t *get_tab_ins(champ_t *champion, corewar_t *core, instru_t *instru)
{
    instru->is_coding_byte = 0;
    instru->params = malloc(sizeof(char) * (MAX_ARGS_NUMBER + 1));
    for (int i = 0; i < MAX_ARGS_NUMBER + 1; i++)
        instru->params[i] = '\0';
    instru->dir_size = check_dir_size(instru->memonic);
    instru->size_instru = init_tab_ins(champion, core, instru);
    if (instru->size_instru < 0 || instru->nb_params != my_strlen(instru->params)) {
        champion->pc += 2;
        return (get_instru(champion, core));
    }
    fill_tab_ins(champion, core, instru);
    return (instru);
}