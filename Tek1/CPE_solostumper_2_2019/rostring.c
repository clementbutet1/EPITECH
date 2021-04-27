/*
** EPITECH PROJECT, 2019
** rostring.c
** File description:
** rostring.c
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void rostring(int ac, char *str)
{
    int size = my_strlen(str);
    char *cp = malloc(sizeof(char *) * 10000000);
    char *final = malloc(sizeof(char) * 10000000);
    int i = 0;
    int k = 0;
    int tmp = 0;
    int z = 0;

    for (;str[i] != ' '; i++, tmp++)
        cp[i] = str[i];
    for (; str[i] != '\0'; i++, k++)
        final[k] = str[i];
    for (; z != tmp + 1; k++, z++)
        final[k] = cp[z];
    write(1, final, size);
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    rostring(ac, av[1]);
    return (0);
}
