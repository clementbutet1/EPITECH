/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    } else {
        if (p >= 1) {
            nb = my_compute_power_rec(nb, p - 1) * result;
            p = p - 1;
        } else {
            return (result);
        }
    }
    return (0);
}
