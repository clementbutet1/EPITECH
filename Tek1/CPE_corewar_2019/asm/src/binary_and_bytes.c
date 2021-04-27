/*
** EPITECH PROJECT, 2019
** binary_and_bytes.c
** File description:
** binary_and_bytes.c
*/

#include "asm.h"

char *add_binary(char *str, int *a, char *add)
{
    str[*a] = add[0];
    str[*a + 1] = add[1];
    *a = *a + 2;
    return (str);
}

int create_coding_byte2(char *str, int i, int bytes, char *binary)
{
    int a = 0;

    bytes = -1;
    for (; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] == SEPARATOR_CHAR && str[i - 1] == ' ')
            my_putstr_error("Error: ASM - space before a ','");
        if (str[i] == 'r' && is_register(str, &i, 1) == 1)
            binary = add_binary(binary, &a, "01");
        else if (str[i] != SEPARATOR_CHAR && str[i] != ' ') {
            if (is_direct(str, &i, 1) == 1)
                binary = add_binary(binary, &a, "10");
            else if (is_indirect(str, &i, 1))
                binary = add_binary(binary, &a, "11");
        }
    }
    bytes = binary_to_decimal(binary);
    free(binary);
    return (bytes);
}

int create_coding_byte(int status, char *str, int i)
{
    int bytes = 0;
    char *binary = malloc(sizeof(char) * 9);

    for (int a = 0; a < 8; a++)
        binary[a] = '0';
    binary[8] = '\0';
    if (status > 0) {
        bytes = -1;
    }
    else {
        bytes = create_coding_byte2(str, i, bytes, binary);
    }
    return (bytes);
}