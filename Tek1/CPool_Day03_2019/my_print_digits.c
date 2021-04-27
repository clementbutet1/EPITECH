/*
** EPITECH PROJET, 2019
** my_print_digits.c
** File Description
** my_print_digits
*/

int my_print_digits(void)
{
    int a = 48;
    
    while (a < 58) {
        my_putchar(a);
        a = a + 1;
    }
}
