/*
** EPITECH PROJECT, 2019
** my_show_word_array.c
** File description:
** my_show_word_array
*/

int my_show_word_array(char * const *tab)
{
    char *str;

    for (int a = 0; tab[a] != '\0'; a++) {
        my_putstr(tab[a]);
        my_putchar('\n');
    }
}
