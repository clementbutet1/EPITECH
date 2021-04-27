/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/

#include <my_macro_abs.h>
#ifndefine my_h_
#define my_h_



void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *tofind);
char *my_strcat(char *dest, char const *scr);
int my_getnbr(char *str);
int soustraction(char *a, char *b);
int addition(char *a, char *b);
int divsion(char *a, char *b);
int modulo(char *a, char *b);

#endif /* MY_H_ */
