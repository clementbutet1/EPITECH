/*
** EPITECH PROJECT, 2019
** my_screensaver.c
** File description:
** my_screensaver.c
*/

#include "include/graphics.h"
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>

void diserror(void)
{
    my_putstr("./my_screensaver: bad arguments: 0 given but ");
    my_putstr("1 is required retry with -h \n84\n");
}

void displayerror(void)
{
    my_putstr("animation rendering in a CSFML window.\n\n");
    my_putstr("Usage: \n");
    my_putstr(" ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr("  animation_id    ID of the animation to process ");
    my_putstr("(between 1 and 20).\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -d               print the description of all ");
    my_putstr("the animations and quit.\n");
    my_putstr(" -h               print the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" LEFT_ARROW        switch to the previous animation.\n");
    my_putstr(" RIGHT_ARROW       switch to the next animation.\n");
}

void displayhelp(void)
{
    my_putstr("The screensaver 1 -> screen that display line of color with ");
    my_putstr(" color it's like the same idea like the light pass into ");
    my_putstr("a prism. \n");
    my_putstr("The screensaver 2 -> Screensaver that diplay some circle");
    my_putstr(" with a lot of color.\n");
    my_putstr("The screensaver 3 -> Screensaver that diplay a big circle");
    my_putstr(" with a lot of different size of color circle.\n");
}

int other(char **av)
{
    if (av[1][0] == '-' && av[1][1] == '3') {
        thirdscreensaver();
        return (0);
    }
    if (av[1][0] == '-' && av[1][1] == 'd') {
        displayhelp();
        return (0);
    } else {
        diserror();
        return (84);
    }
}

int main(int ac, char **av)
{
    if (ac != 2) {
        diserror();
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        displayerror();
        return (0);
    }
    if (av[1][0] == '-' && av[1][1] == '1') {
        firstscreensaver();
        return (0);
    }
    if (av[1][0] == '-' && av[1][1] == '2') {
        secondscreensaver();
        return (0);
    }
    other(av);
}