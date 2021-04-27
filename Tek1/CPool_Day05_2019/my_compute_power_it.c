/*
** EPITECH PROJECT, 2019
** my_compute_power_it.c
** File description:
** my_compute_power_it
*/

int my_compute_power_it( int nb, int p)
{
    int result = 1;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    } else {
        while (p >= 1) {
            result = result * nb;
            p = p - 1;
        }
    }
    return (result);
}
