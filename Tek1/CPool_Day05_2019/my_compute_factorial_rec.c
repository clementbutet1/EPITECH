/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec.c
** File description:
** my_compute_factorial_rec
*/

int my_compute_factorial_rec(int nb)
{
    int result = nb;

    if (nb < 0) {
        return 0;
    }
    else if (nb == 0 || nb == 1) {
        return 1;
    }
    if (nb > 12) {
        return 0;
    }
    if (nb > 1) {
        result = nb * my_compute_factorial_rec(nb - 1);
    }
    return (result);
}
