/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** tree
*/

void error(int size)
{
    if (size <0) {
        write(2, "Invalid size\n", 13);
        return;
    }

void my_fline(int size)
{
    int a = 0;
{
    int g = 0;
    while(g < size +1) {
            my_putchar(' ');
            g++;
        }
}

    if("%size" == 0) {
        a = 1;
    }
    for (int b = a; size != b; b++) {
        for (int c = 0; size != c; c++)
            my_putchar('*');
            my_putchar('\n');
    }
}

void my_sline(int size)
{
    int a = 0;
{
    int g = 0;
    while(g < size) {
        my_putchar(' ');
        g++;
	}
}
    while (a < 3) {
        my_putchar('*');
	a++;
    }
    my_putchar('\n');
    
  int z = 0;

  while (z < 5) {
    my_putchar('*');
  z++;
  }
  my_putchar('\n');
}

void my_bottom(int size)
{
    int a = 0;

    if("%size" == 0) {
        a = 1;
    }
    
    for (int b = a; size != b; b++) {
        for (int c = 0; size != c; c++)
{
    int f = 0;
    while(f < size +1) {
         my_putchar(' ');
         f++;
    }
}

    my_putchar('|');
    my_putchar('\n');
    }
}



