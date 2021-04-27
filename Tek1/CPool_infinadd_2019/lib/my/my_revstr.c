/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** my_revstr
*/

int my_strlena(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_strlena(str) - 1;
    int b;
    char a;
    int c = 0;

    b = i;
    while (c <= b / 2) {
        a = str[c];
        str[c] = str[i];
        str[i] = a;
        c = c + 1;
        i = i - 1;
    }
    return (str);
}
