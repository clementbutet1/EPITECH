/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_file_input.c
*/

#include "asm.h"

char **write_one_element(char **tab, char *fst_el, int size_tab)
{
    char **new_envi2 = NULL;
    char *new_line = my_strdup(fst_el);
    int i = 0;

    new_envi2 = malloc(sizeof(char *) * (size_tab + 2));
    for (; i != size_tab; i++)
        new_envi2[i] = tab[i];
    new_envi2[i++] = new_line;
    new_envi2[i] = NULL;
    free(tab);
    return (new_envi2);
}

int check_extension(char *filename)
{
    int i = 0;

    for (; filename[i] != '\0'; i++);
    if (filename[i - 1] == 's' && filename[i - 2] == '.')
        return (0);
    else
        return (84);
}

char **open_read(char *filename)
{
    FILE *fd = fopen(filename, "r");
    char *buffer = NULL;
    char **map = NULL;
    size_t size = 0;

    if (fd == NULL)
        return (NULL);
    if (check_extension(filename) == 84)
        return (NULL);
    for (int i = 0; getline(&buffer, &size, fd) != -1; i++) {
        if (buffer == NULL)
            return (NULL);
        map = write_one_element(map, buffer, i);
    }
    if (map == NULL)
        return (NULL);
    fclose(fd);
    free(buffer);
    return (map);
}