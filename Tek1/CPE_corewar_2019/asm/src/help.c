/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** help.c
*/

#include "asm.h"

void display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./asm file_name[.s]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     file_name     file in assembly language to be ");
    my_putstr("converted into file_name.cor, an\n");
    my_putstr("                   executable in the Virtual Machine.\n");
    exit(0);
}