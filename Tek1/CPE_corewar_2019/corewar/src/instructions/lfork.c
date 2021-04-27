/*
** EPITECH PROJECT, 2019
** lfork.c
** File description:
** lfork.c
*/

#include "corewar.h"

champ_t *new_champ_l(corewar_t *op, champ_t *champ)
{
    champ_t *tmp = malloc(sizeof(champ_t));

    op->nb_cor++;
    tmp->header = champ->header;
    tmp->carry = champ->carry;
    tmp->is_alive = champ->is_alive;
    tmp->registre = malloc(sizeof(int) * REG_NUMBER);
    tmp->instru = malloc(sizeof(instru_t));
    tmp->instru->cycle_to_wait = 2;
    for (int i = 0; i < REG_NUMBER; i++)
        tmp->registre[i] = champ->registre[i];
    return tmp;
}

void my_lfork(corewar_t *op, int i)
{
    champ_t *tmp;
    champ_t **new;
    int j;

    tmp = new_champ_l(op, op->champion[i]);
    tmp->pc = op->champion[i]->pc + op->champion[i]->instru->tab_ins[1
    + op->champion[i]->instru->is_coding_byte][0];
    new = malloc(sizeof(champ_t *) * (op->nb_cor + 1));
    for (j = 0; i < op->nb_cor - 1; j++)
        new[j] = op->champion[j];
    new[j] = tmp;
    new[j++] = NULL;
    return;
}