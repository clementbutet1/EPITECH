/*
** EPITECH PROJET, 2019
** my_print_alpha.c
** File Description:
** my_print_alpha
*/

int my_print_alpha(void)
{
    int a = 97;
   
    while (a < 123) {
        my_putchar(a);
        a = a + 1;
    }
}
