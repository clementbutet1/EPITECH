/*
** EPITECH PROJET, 2019
** my_print_comb2.c
** File Description:
** my_print_comb2
*/
int display(int z)
{
    int a;
    int b;
    a = (z / 10) + 48;
    b  = (z % 10) + 48;
    my_putchar(a);
    my_putchar(b);
}
int my_print_comb2(void)
{
    int a = 0;
    int b = 0;
 
    while  (a <= 99) {    
        b = a + 1;
        while (b < 100) { 
	    display (a);
	    my_putchar (' ');
	    display (b);
        if (a != 98 || b != 99)
	    {
	    my_putchar (',');
            my_putchar (' ');
	    }
	    b = b + 1;
        }
    a = a + 1;
    }
}
