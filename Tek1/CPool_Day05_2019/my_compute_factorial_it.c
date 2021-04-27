/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it.c
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it (int nb)
{
    int result = nb;

    if (nb < 0) {
        return 0;
    }
    else if (nb == 0 || nb == 1) {
        return 1;
    }
    if (nb > 12)
        return 0;
    while (nb > 1) {
        result = result * (nb - 1);
        nb = nb - 1;
    }
    return (result);
}
