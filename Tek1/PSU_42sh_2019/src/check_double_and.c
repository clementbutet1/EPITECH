/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_double_and.c
*/

#include "mysh.h"

int execute_double_and(sh_t *sh)
{
    char *str;

    if (sh->spipe.is_double_and == 1) {
        str = my_strdup(sh->spipe.double_and);
        free(sh->spipe.double_and);
        sh->spipe.double_and = NULL;
        use_buffer_line(sh, str, 0);
        free(str);
        return (1);
    }
    return (0);
}

char *check_double_and(char *buffer, sh_t *sh)
{
    char *str;

    if (sh->spipe.double_and != NULL)
        return (buffer);
    sh->spipe.is_double_and = 0;
    for (int i = 0, a = 0, d = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '&')
            d++;
        if (d == 2) {
            sh->spipe.is_double_and = 1;
            sh->spipe.double_and = my_strdup(&buffer[i + 1]);
            buffer[i - 1] = '\0';
            str = clean_buffer(my_strdup(buffer), 0);
            free(buffer);
            return (str);
        }
        if (buffer[i] != ' ' && buffer[i] != '&' && a % 2 == 0)
            d = 0;
    }
    return (buffer);
}