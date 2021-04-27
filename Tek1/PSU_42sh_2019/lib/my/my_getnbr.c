/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_getnbr
*/

#include <stdlib.h>

int my_strlen_int(int nb)
{
    int size = 0;

    for (; nb > 0; size++)
        nb /= 10;
    return (size);
}

char *my_itoa(int nb)
{
    int size = my_strlen_int(nb);
    char *str = NULL;

    str = malloc(sizeof(char) * (size + 1));
    for (int s = size - 1; s > -1; s--) {
        str[s] = nb % 10 + '0';
        nb /= 10;
    }
    str[size] = '\0';
    return (str);
}

long int my_getnr1(int i, long int nb, char const *str)
{
    for (i; str[i] != '\0' && str[i] < 58 && str[i] > 47; i++) {
        nb += str[i] - 48;
        if (str[i + 1] != '\0' && str[i + 1] < 58 && str[i + 1] > 47)
            nb *= 10;
    }
    return (nb);
}

long int my_getnbr(char const *str)
{
    long int nb = 0;
    int i = 0;
    int compt = 0;
    int c = 0;

    while (str[i] == '-') {
        i++;
        compt += 1;
    }
    c = i;
    nb = my_getnr1(i, nb, str);
    if (str[c] > 57 || str[c] < 48)
        return (0);
    if (compt % 2 > 0) {
        nb *= -1;
        return (nb);
    }
    return (nb);
}