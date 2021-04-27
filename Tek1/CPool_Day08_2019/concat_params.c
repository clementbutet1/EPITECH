/*
** EPITECH PROJECT, 2019
** concat_params.c
** File description:
** concat_params
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int i = 0;
    char *str;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);

    char *src;
    int a = 0;

    while (i != argc) {
        i += argv[i];
        i++;
    }
    src = malloc(sizeof(char) * (i + argc));
    i = 0;
    while (i < argc) {
        my_strcat(src, argv[i]);
        my_strcat(src, "\n");
        i++;
    }
    return(dest);
}
