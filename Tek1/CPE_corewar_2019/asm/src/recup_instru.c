/*
** EPITECH PROJECT, 2019
** recup_instru.c
** File description:
** recup_instru.c
*/

#include "asm.h"

void verif_get_register(char *str, int *i, instu_core_t *new, int *nb_arg)
{
    int *nb = malloc(sizeof(int) * (2));
    int a = *i + 1;

    nb[0] = my_getnbr(&str[*i + 1]);
    nb[1] = -1;
    for (; str[a] != '\n' && str[a] != '\0' &&
    str[a] != SEPARATOR_CHAR && str[a] != ' '; a++);
    if (new->tab.type[*nb_arg] % 2 == 0 || str[a] == ' ')
        my_putstr_error("Error: ASM - bad arguments register");
    *i = a;
    (str[a] == '\0' || str[a] == '\n') ? *i = a - 1 : 0;
    new->params = add_two_tab_int(new->params, nb);
    *nb_arg = *nb_arg + 1;
}

int *verif_get_int_label(char *str, int *a, instu_core_t *new, int size)
{
    int *b = malloc(sizeof(int) * (size + 1));
    int size1 = *a;
    int comp = 0;

    for (int f = 0; f < size; f++)
        b[f] = -2;
    b[size] = -1;
    for (; str[*a] != '\n' && str[*a] != '\0' &&
    str[*a] != SEPARATOR_CHAR && str[*a] != ' '; *a += 1);
    for (int d = 0; new->label[d] != NULL; d++) {
        if (my_strncmp(&str[size1], new->label[d], *a - size1) == 0)
            comp++;
    }
    if (comp == 0)
        my_putstr_error("Error : Offset problem");
    return (b);
}

void verif_get_direct(char *str, int *i, instu_core_t *new, int *nb_arg)
{
    int a = *i + 1;
    int *b = 0;
    int c = 0;
    char *nb_char_decimal;

    check_error_get_direct(new, nb_arg);
    if (str[a] == LABEL_CHAR) {
        a++;
        b = verif_get_int_label(str, &a, new, new->dir_size);
    }
    else {
        for (; str[a] != '\n' && str[a] != '\0' &&
        str[a] != SEPARATOR_CHAR && str[a] != ' '; a++, c++);
        nb_char_decimal = my_strncpy(&str[*i + 1], c);
        c = my_getnbr(&str[*i + 1]);
        b = check_condi_magic_dir(new, nb_char_decimal, c, b);
    }
    add_incrementation_verif_get(new, nb_arg, b);
    *i = a;
    (str[a] == '\0' || str[a] == '\n') ? *i = a - 1 : 0;
}

int *create_magic_tab_negative(int c, int size)
{
    int *b = malloc(sizeof(int) * (size + 1));
    int nb = 1;

    for (int i = 0; i < size; i++)
        b[i] = 0;
    b[size] = -1;
    b[size - 1] = c;
    if (c == 0)
        return (b);
    for (int i = size - 1; i - 1 >= 0; i--) {
        for (nb = 1; b[i] <= -256; nb++)
            b[i] += 256;
        b[i - 1] = nb * -1;
    }
    for (int i = 0; i < size; i++) {
        if (b[i] < 0)
            b[i] -= 2;
    }
    return (b);
}

void verif_get_indirect(char *str, int *i, instu_core_t *new, int *nb_arg)
{
    int a = *i;
    int *b = 0;
    int c = 0;
    char *nb_char_decimal;

    check_error_indirect(new, nb_arg);
    if (str[*i] == LABEL_CHAR) {
        a++;
        b = verif_get_int_label(str, &a, new, IND_SIZE);
    }
    else {
        for (; str[a] != '\n' && str[a] != '\0' &&
        str[a] != SEPARATOR_CHAR && str[a] != ' '; a++, c++);
        nb_char_decimal = my_strncpy(&str[*i], c);
        c = my_getnbr(&str[*i]);
        b = check_condi_magic_indi(nb_char_decimal, c, b);
    }
    add_incrementation_verif_get(new, nb_arg, b);
    *i = a;
    (str[a] == '\0' || str[a] == '\n') ? *i = a - 1 : 0;
}