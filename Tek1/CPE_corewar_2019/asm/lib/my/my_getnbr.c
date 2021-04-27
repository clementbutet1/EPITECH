/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_getnbr
*/

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