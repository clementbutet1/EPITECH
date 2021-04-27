/*
** EPITECH PROJECT, 2019
** verif.c
** File description:
** verif.c
*/

#include "asm.h"

void check_dir_size(char *str, instu_core_t *new)
{
    char *two_byte[] = {"lfork", "lldi", "fork", "sti", "ldi", "zjmp"};

    new->dir_size = DIR_SIZE;
    for (int i = 0; i < 6; i++) {
        if (my_strcmp(two_byte[i], str) == 0)
            new->dir_size = 2;
    }
}

int check_line_instru(char *str, char *her_tab, int *cursor, instu_core_t *new)
{
    int i = 0;
    int d = 0;
    int size = 0;

    for (int a = 0; str[a] != '\0' && d == 0; a++)
        if (str[a] == LABEL_CHAR)
            d = a;
    if (d > 0 && label_conposed_of_label_chars(str, d - 1) == 0)
        i = d + 1;
    for (; str[i] == ' '; i++);
    for (d = i; str[d] != ' ' && str[d] != '\n' &&
    str[d] != '\0'; d++, size++);
    *cursor = i;
    if (my_strncmp(&str[i], her_tab, size) == 0) {
        check_dir_size(her_tab, new);
        return (1);
    }
    return (0);
}

int check_error_params(char *str, int i, instu_core_t *new)
{
    int nbr_args = new->tab.nbr_args;
    int nb_arg = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++) {
        if (nbr_args == nb_arg)
            my_putstr_error("Error: ASM - too many arguments");
        if (str[i] == 'r' && is_register(str, &i, 0) == 1) {
            verif_get_register(str, &i, new, &nb_arg);
        }
        else if (str[i] != SEPARATOR_CHAR && str[i] != ' ') {
            if (is_direct(str, &i, 0) == 1)
                verif_get_direct(str, &i, new, &nb_arg);
            else if (is_indirect(str, &i, 0))
                verif_get_indirect(str, &i, new, &nb_arg);
        }
    }
    if (nbr_args != nb_arg)
        my_putstr_error("Error: ASM - not enough arguments");
    return (0);
}

int recup_instru(instu_core_t *new, char *str, int line)
{
    for (int j = 0, cursor = 0; op_tab[j].code != 0; j++) {
        if (check_line_instru(str, op_tab[j].mnemonique, &cursor, new) == 1) {
            cursor += my_strlen(op_tab[j].mnemonique) - 1;
            new->status = check_option_two_byte(op_tab[j].mnemonique);
            new->instru = op_tab[j].code;
            new->prog_size += 1;
            new->tab = op_tab[j];
            new->coding_byte = create_coding_byte(new->status, str, cursor + 1);
            if (new->coding_byte != -1)
                new->prog_size += 1;
            new->str = str;
            new->line = line;
            check_error_params(str, cursor + 1, new);
            for (cursor = 0; new->params[cursor] != -1; cursor++);
            new->prog_size += cursor;
            return (new->prog_size);
        }
    }
    my_putstr_error("Error : Mnemonic not found");
    return (0);
}