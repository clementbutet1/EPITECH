/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int cpt = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            cpt = cpt * -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb +str[i] - '0';
            i++;
        }
        else
            return (nb * cpt);
    }
    return (nb * cpt);
}
