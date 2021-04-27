/*
** EPITECH PROJECT, 2019
** countwords.c
** File description:
** countwords.c
*/

#include <stdio.h>
#include <stdlib.h>

int count_print_word(char *strword)
{
    int i = 0;
    char *saveword;
    char *the_word;

    while (saveword[i] == strword[i]) {
        the_word[i] = saveword[i];
        i++;
    }
    printf("%c:", the_word);
    printf("%i\n", i);
}

int countcara(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void checksameword(char *str, char *save)
{
    int i = 0;
    int save = 0;
    char *word;

    while (str[i] != '\0') {
        if (str[i] == ' ')
	    save = i;
        i++;
    }
    word = malloc(sizeof(char *) * (save);
    
}

int countwords(int ac, char *str)
{
    int i = 0;
    int size = countcara(str);
    char *save = malloc(sizeof(char *) * size + 1);

    while (str[i] != '\0') {
	for (int k = 0; k <= size; k++) {
	    save[k] = str[i];
	}
	i++;
    }
    checksameword(str, save);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        printf("\n");
        return (0);
    }
    if (ac != 2)
        return (84);
    countwords(ac, av[1]);
}
