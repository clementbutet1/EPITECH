/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    while (a <= n) {
        dest[a] = src[a];
        dest[a + 1] = '\0';
        a++;
    }
    return (dest);
}
