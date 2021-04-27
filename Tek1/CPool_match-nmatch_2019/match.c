/*
** EPITECH PROJECT, 2019
** match.c
** File description:
** match
*/
#include <stdio.h>

int my_putchar(char c)
{
  write(1, &c, 1);
}

int match(char const *s1, char const *s2)
{
    int cpt = 0;
    
    if (*s1 != *s2 && *s2 != '*') {
        return(0);
    }
    int a = difference();
}
int difference(char const *s1,char const *s2)
{
    int cpt = 0;
    while (*s2 != '\0' && *s1 == '*' || *s1 != '\0' && *s2 == '*') {
        return(1);
    }
    while ( *s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        return(1);
    }
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        return(1);
    }
}

int main (void)
{
  match("hello", "he***********************");
  return(0);
}
