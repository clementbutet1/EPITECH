/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a = a + 1;
    }
    return (a);
}

int special_strlen(int nb)
{
    int i = 0;

    for (; nb > 0; i++)
        nb = nb / 10;
    return (i);
}