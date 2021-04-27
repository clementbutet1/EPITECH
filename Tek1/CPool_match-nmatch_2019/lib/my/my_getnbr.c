/*                                                                                                             
** EPITECH PROJECT, 2019                                                                                       
** my_getnbr.c                                                                                                     
** File description:                                                                                           
** my_getnbr                                                                                                       
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int a = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
        a = a * -1;
    }
    for (; str[i] != '\0'; i++) {
	if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        }
    else
        return (nb * a);
    }
    return (nb * a);
}
