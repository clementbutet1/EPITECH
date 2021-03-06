/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** my_compute_square_root
*/

double my_compute_square_root(double nb)
{
    double result = 1;

    if (nb == 0) {
        return (0);
    }
    if (nb < 0) {
        return (0);
    }
    while ((result * result) != nb) {
        if ((result * result) > nb) {
            return (0);
        }
        result = result + 1;
    }
    return result;
}
