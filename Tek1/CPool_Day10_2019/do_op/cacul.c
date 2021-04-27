/*
** EPITECH PROJECT, 2019
** cacul.c
** File descritpion:
** calcul et erreur
*/

#include "my_lib.h"

int soustraction(char *a, char *b);
int addition(char *a, char *b);
int division(char *a, char *b);
int modulo(char *a, char *b);

int calcul(char *a, char *signe, char *b)
{
    int (*cal[4])(char*, char*); 
  
    for (cal[0] = &soustraction; signe[0] == '-';) {
        cal[0](a, b);
    }
    for (cal[1] = &addition; signe[1] == '+';) {
        cal[1](a, b);
    }
    for (cal[2] = &division; signe[2] == '/';) {
        cal[2](a, b);
    }
    for (cal[3] = &modulo; signe[3] == '%';) {
        cal[3](a, b);
    }
}

int main(int ac, char **av)
{
    if (av[2] == "0") {
        my_putstr("Stop : division by zero");
    } else if (av[3] == "0") {
        my_putstr("Stop : division by modulo");
    } 
}
