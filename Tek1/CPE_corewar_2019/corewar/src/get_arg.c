/*
** EPITECH PROJECT, 2020
** get_arg.c
** File description:
** get_arg
*/

#include "corewar.h"

void create_registre(champ_t *champion)
{
    champion->registre = malloc(sizeof(unsigned int) * REG_NUMBER);

    for (int i = 0; i < REG_NUMBER; i++)
        champion->registre[i] = 0;
}

void get_instru_cor(champ_t *champion, corewar_t *core)
{
    int fd;

    if ((fd = open(champion->name, O_RDONLY)) == -1)
        my_putstr_error("bad file given\n");
    champion->is_alive = 1;
    recup_header(champion, fd);
    get_all_champ(champion);
    recup_core(champion, fd);
    fill_champ(champion, core);
    create_registre(champion);
    close(fd);
}

void recove_champ(char **av, corewar_t *core, int i)
{
    static int n = 0;

    core->champion[n] = malloc(sizeof(champ_t) * 1);
    core->champion[n]->load_adress = (MEM_SIZE / core->nb_cor) * n;
    core->champion[n]->nb_prog = n + 1;
    core->champion[n]->name = av[i];
    for (; i > 0 && my_strendcmp(av[i], ".cor") == 0; i--) {
        if (my_strcmp(av[i], "-a") == 0 && verif_is_nb(av[i + 1]) == 1)
            core->champion[n]->load_adress = (my_getnbr(av[i + 1]) % MEM_SIZE);
        if (my_strcmp(av[i], "-n") == 0 && verif_is_nb(av[i + 1]) == 1)
            core->champion[n]->nb_prog = my_getnbr(av[i + 1]);
    }
    n++;
}

int check_argument(char **av)
{
    int flag = 0;

    if ((check_same_word(av[1], "--help") == 11) ||
        (check_same_word(av[1], "-h") == 11))
        display_help(0);
    for (int i = 1; av[i] != NULL; i++) {
        flag = 0;
        if ((my_strcmp(av[i], "-dump") == 0) || (my_strcmp(av[i], "-n") == 0))
            flag = 1;
        if (my_strcmp(av[i], "-a") == 0)
            flag = 1;
        if ((flag == 1 && av[i + 1] == NULL) ||
            (flag == 1 && my_str_isnum(av[i + 1]) == 0))
            display_help(84);
        else if ((flag == 0 && my_strendcmp(av[i], ".cor") == 0) &&
            (my_str_isnum(av[i]) == 0))
            display_help(84);
    }
    return 0;
}

int verif_is_nb(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] > '9' || str[i] < '0')
            my_putstr_error("Error : after the -a or -n the argument must be \
            a number");
    }
    return (1);
}