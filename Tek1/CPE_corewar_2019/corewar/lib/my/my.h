/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/


#ifndef my_h_
#define my_h_

int check_same_word(char *str, char *str1);
char **copy_tab(char **tab);
void print_tab(char **tab);
char *put_tab_buffer(char **tab);
void my_putchar(char c);
int my_isneg(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *scr);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *src);
char **my_str_tab(char *str, char s);
int tab_len(char **tab);
char *clean_str(char *str);
void free_tab(char **tab);
void my_putstr_error(char const *str);
int my_strncmp(char *s1, char *s2, int n);

#endif /* MY _H_ */
