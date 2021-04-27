/*
** EPITECH PROJET, 2019
** my_print_revalpha.c
** File Descritpion:
** my_print_revalpha
*/

int my_print_revalpha(void)
{
    int a = 122;
   
    while (a > 96) {
        my_putchar(a);
        a = a - 1;
    }
}
