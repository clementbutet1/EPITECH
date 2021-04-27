/*
** EPITECH PROJET, 2019
** my_print_comb.C
** File Description:
** my_print_comb
*/

int my_putchar1(int a, int b, int c)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
    if (a == '7')
         return (0);
    else {
        my_putchar(',');
        my_putchar(' ');
   }
}

int my_print_comb(void)
{
   int a = 48;
   int b = 48;
   int i = 1;
   int c = 48;

   while (i < 789) {
       if (a != b && a != c && b != c && c > b && b > a)
           my_putchar1(a, b, c);
       if (c < 57)
           c = c + 1;
       else {
	   c = 48;
           b = b + 1;
       } if (b == 57) {
           b = 48;
	   a = a + 1;
       } if (a == 57)
 	   a = 48;
       i = i + 1;
  }
   my_putchar('\n');
}
