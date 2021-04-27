/*
** EPITECH PROJECT, 2019
** PSU_navyfab_2019
** File description:
** convert_bin_int.c
*/

int power_it(int nb, int p)
{
    int a = nb;

    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    if (p >= 1) {
        while (p > 1) {
            nb = nb * a;
            p = p - 1;
        }
        return (nb);
    }
    return (0);
}

int convert_bin_int(char *str)
{
    int nb_final = 0;
    int len = 0;
    int power = 0;
    int calc = 0;

    for (int y = 0; str[y] != '\0'; y++)
        len++;
    for (int x = len - 1; str[x] >= 0; x--) {
        calc = power_it(2, power);
        if (str[x] == '0')
            nb_final += 0;
        if (str[x] == '1')
            nb_final += (str[x] - 48) * calc;
        power++;
    }
    return nb_final;
}