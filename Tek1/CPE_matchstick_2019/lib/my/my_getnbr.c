/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr
*/

int	my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int cpt = 0;

    if (!str)
        return (0);
    while (str[i] == '+' || str[i] == '-')
        i = i + 1;
    for (;str[i] >= '0' && str[i] <= '9'; i++)
        nb = ((nb * 10) + (str[i] - 48));
    for (int k = 0; str[k] > '9' || str[k] < '0'; k++)
        if (str[k] == '-')
            cpt++;
    if (cpt % 2 != 0)
        nb = -nb;
    return (nb);
}