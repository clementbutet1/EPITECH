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

    for (;str[i] == '+' || str[i] == '-'; i++)
        (str[i] == '-') ? cpt = cpt * - 1 : (cpt = 1);
    for (;str[i] != '\0';) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        }
        else
            return (nb * cpt);
    }
    return (nb * cpt);
}
