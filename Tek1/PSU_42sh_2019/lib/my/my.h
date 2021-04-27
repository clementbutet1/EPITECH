/*
** EPITECH PROJECT, 2019
** CPE_pushswap_bootstrap_2019
** File description:
** push_swap.h
*/

#include <stdlib.h>
#include <unistd.h>

int my_strncmp(char *s1, char *s2, int n);
int my_strcmp(char *s1, char *s2);
char **my_str_to_word_array(char *buffer, char sepa);
char *my_strdup(char const *src);
void my_putchar(char c);
int my_strlen(char const *str);
void my_put_nbr(long int nb);
int my_putstr(char const *str);
long int my_getnbr(char const *str);
int my_putstr_long(char const *str, int rows);
char *change_buffer(char *buffer, int i, int size);
int my_putstr_error(char const *str);
char **my_strdup_2d(char **tb);
int special_strlen(int nb);
char *my_itoa(int nb);
int my_strcmp_alias(char *s1, char *s2);
char *my_strcpy(char *str);