/*
** EPITECH PROJECT, 2019
** rush3_bis
** File description:
** storage
*/

int def_rush(char *first, char *last, int x, int y)
{
    int rush = 0;

    if (first[0] == 'o')
        rush = 1;
    if (first[0] == '/' || first[0] == '*')
        rush = 2;
    if (first[0] == 'B')
        rush = 6;
    if (first[0] == 'A' && first[1] == 'A')
        rush = 3;
    if (last[0] == 'A' && last[1] == 'C')
        rush = 4;
    if (last[0] == 'C' && last[1] == 'A')
        rush = 5;
    return rush;
}

int first_line(char *buff, char *first)
{
    int size = 0;

    for (int i = 0; buff[i] != '\n' ; i++)
        size = i;
    first[0] = buff[0];
    first[1] = buff[size];
    return (size + 1);
}

int height(char *buff)
{
    int nb = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            nb++;
    }
    return nb;
}

void last_line(char *buff, char *last, int y)
{
    int nb = 0;
    int i = 0;

    for (;nb < y; i++) {
        if (buff[i] == '\n')
            nb++;
    }
    last[0] = buff[i];
    while (buff[i] != '\n')
        i++;
    last[1] = buff[i - 1];
}
