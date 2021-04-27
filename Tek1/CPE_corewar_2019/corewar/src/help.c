/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** help.c
*/

#include "corewar.h"

void display_help(int n)
{
    my_putstr("USAGE\n");
    my_putstr("     ./corewar [-dump nbr_cycle] ");
    my_putstr("[[-n prog_number] [-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     -dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_putstr("execution (if the round isn’t\n");
    my_putstr("                     already over) with ");
    my_putstr("the following format:  32 bytes/line in\n");
    my_putstr("                     hexadecimal (A0BCDEFE1DD3...)\n     ");
    my_putstr("-n prog_number  sets the next program’s number. ");
    my_putstr("By default, the first free number\n");
    my_putstr("                     in the parameter order\n     ");
    my_putstr("-a load_address sets the next program’s ");
    my_putstr("loading address.  When no address is\n");
    my_putstr("                     specified, optimize the addresses so ");
    my_putstr("that the processes are as far\n");
    my_putstr("                     away from each other as possible.");
    my_putstr("  The addresses are MEM_SIZE modulo\n");
    exit(n);
}