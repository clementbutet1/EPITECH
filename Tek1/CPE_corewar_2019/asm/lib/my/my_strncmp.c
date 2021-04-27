/*
** EPITECH PROJECT, 2019
** asm
** File description:
** my_strncmp.c
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n - 1 && s1[i] == s2[i] && s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}