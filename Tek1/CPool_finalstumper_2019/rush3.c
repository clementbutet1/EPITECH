/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** Analyse rush1
*/

#include <unistd.h>
#include "include/my.h"

void my_print(int rush, int x, int y)
{
    if (rush == 1)
        my_putstr("[rush1-1] ");
    if (rush == 2)
        my_putstr("[rush1-2] ");
    if (rush == 3)
        my_putstr("[rush1-3] ");
    if (rush == 4)
        my_putstr("[rush1-4] ");
    if (rush == 5)
        my_putstr("[rush1-5] ");
    if (rush == 1 || rush == 2 || rush == 3
    || rush == 4 || rush == 5) {
        my_putnbr(x);
        my_putchar(' ');
        my_putnbr(y);
        my_putchar('\n');
    }
}

void my_print_bis(int rush, int x, int y)
{
    if (rush == 6) {
        my_putstr("[rush1-3] ");
        my_putnbr(x);
        my_putchar(' ');
        my_putnbr(y);
        my_putstr(" || ");
        my_putstr("[rush1-4] ");
        my_putnbr(x);
        my_putchar(' ');
        my_putnbr(y);
        my_putstr(" || ");
        my_putstr("[rush1-5] ");
        my_putnbr(x);
        my_putchar(' ');
        my_putnbr(y);
        my_putchar('\n');
    }
}


void rush3(char *buff)
{
    char first[3];
    char last[3];
    int x = first_line(buff, first);
    int y = height(buff);

    last_line(buff, last, y - 1);
    my_print(def_rush(first, last, x, y), x, y);
    my_print_bis(def_rush(first, last, x, y), x, y);
}

int main(void)
{
    int BUFF_SIZE = 30000;
    char buff [BUFF_SIZE];
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return (0);
}
