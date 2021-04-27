/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/


#ifndef my_h_
#define my_h_

void my_putchar(char c);
int my_isneg(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
double my_compute_square_root(double nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *scr);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);

#endif /* MY _H_ */
