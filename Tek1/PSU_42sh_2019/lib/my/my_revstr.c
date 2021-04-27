/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_revstr
*/

void my_swap(char *str, char *str1)
{
    int c = *str;

    *str = *str1;
    *str1 = c;
}

char *my_revstr(char *str)
{
    int compteur1 = 0;
    int compteur2 = 0;
    int d = 0;

    while (str[compteur1] != '\0') {
        compteur1 += 1;
    }
    d = compteur1;
    compteur1 = compteur1 - 1;
    while (compteur1 > compteur2) {
        my_swap(&str[compteur2], str + compteur1);
        compteur1 -= 1;
        compteur2 += 1;
    }
    str[d] = '\0';
    return (str);
}