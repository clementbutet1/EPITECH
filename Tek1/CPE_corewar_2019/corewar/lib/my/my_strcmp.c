/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    return (s1[i] - s2[i]);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n - 1 && s1[i] == s2[i] && s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}