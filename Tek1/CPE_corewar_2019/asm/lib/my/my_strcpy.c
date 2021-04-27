/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** my_strcpy
*/

int my_strlenc(char const *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len = len + 1;
    }
    return (len);
}

char *my_strcpy(char *dest, char const *src)
{
    int size = my_strlenc(src);
    int a = 0;

    while (src[a] != size) {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}