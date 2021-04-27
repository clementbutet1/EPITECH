/*
** EPITECH PROJECT, 2019
** my_is_prime.c
** File description:
** "my_is_prime"
*/

int my_is_prime(int nb)
{
    int a;

    if (nb < 2) {
        return 0;
    }
    else if (nb == 2) {
        return 1;
    }
    else if (nb % 2 == 0) {
        return 0;
    } else {
        a = 3;
        while (a * a <= nb) {
            if (nb % a == 0) {
                return 0;
            }
            a = a + 2;
        }
    }
    return 1;
}
