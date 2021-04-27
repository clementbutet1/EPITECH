/*
** EPITECH PROJET 2019
** my_evil_str.c
** File Description:
** my_evil_str
*/

char *my_evil_str(char *str)
{
    int i = 0;
    int b = 0;
    char a;
    int c = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    b = i;
    while (b/2 > c) {
        a = str[c];
        str[c] = str[i - 1]; 
	str[i - 1] = a;
	c = c +1;
        i = i - 1;
    }
    return (str);
}



  
