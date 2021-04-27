/*
** EPITECH PROJECT, 2019
** my_print_params.c
** File description:
** my_print_params
*/

void my_putchar(char c);
{
  write(1, &c, 1);
}
int my_print_params(int argc, char *argv[])
{
    for (int a = 0; a < argv; a++)
        my_putchar(argv[argc][a]);
	my_putchar('\n');
}
int main (int argc, char *argv[])
{
    my_print_params(argc, argv);
    return (0);
}
 
