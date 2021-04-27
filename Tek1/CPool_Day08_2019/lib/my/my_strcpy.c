/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
