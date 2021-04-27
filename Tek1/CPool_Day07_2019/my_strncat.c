/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** my_strncat
*/

int my_strlenb(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = 0;
    int b = 0;
    while (a < nb && dest[a] != '\0')
        a++;
    while (src[b] != '\0') {
        dest[a] = src[b];
        b++;
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
