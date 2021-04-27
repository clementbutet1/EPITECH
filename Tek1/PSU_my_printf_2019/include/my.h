
/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/

#include <stdarg.h>
#ifndef my_h_
#define my_h_

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlend(char const *str);
char *my_revstr4(char *str);
int my_putstr4(char const *str);
void my_converthexadecimalma(unsigned int nb);
void my_putchar3(char c);
char *my_revstr3(char *str);
int my_putstr3(char const *str);
void my_converthexadecimalmi(unsigned int nb);
int my_strlenb(char const *str);
char *my_revstr2(char *str);
int my_putstr2(char const *str);
void my_convertoctal(unsigned int nb);
int my_strlena(char const *str);
char *my_revstr1(char *str);
int my_putstr1(char const *str);
void my_convertbinaire(unsigned int nb);
void condition2(int z, char *str, va_list ap, ...);
void condition(int z, char *str, va_list ap, ...);
void my_printf(char *str, ...);
void printbefore(int z, char *str);
void printafter(int z, char *str);
void my_putcharz(char c);
int my_put_nbrz(int unsigned nb);
unsigned int my_printunsint(unsigned int nb);
void my_printflagsu(unsigned int nb);
void my_putchar7(char c);
char *my_revstr7(char *str);
int my_putstr7(char const *str);
void my_converthexadecimalmi1(int nb);
void printflagsp(int nb);
void printflagss(unsigned char *str);
void printflagss2(unsigned char *str, int i);
void my_putcharh(char c);
void nextcondition(int z, char *str, va_list ap, ...);

#endif /* MY _H_ */
