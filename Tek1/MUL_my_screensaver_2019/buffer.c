/*
** EPITECH PROJECT, 2019
** buffer.c
** File description:
** buffer.c
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

void turnoffwind(sfEvent event, sfRenderWindow *wind)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wind);
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *bumper = malloc(sizeof(framebuffer_t));
    bumper->width = width;
    bumper->height = height;
    bumper->pixels = malloc(width * height * 4);
    return (bumper);
}

int my_putpixel(framebuffer_t *bumper, unsigned int width, unsigned int height,
sfColor color)
{
    bumper->pixels[((*bumper).width * width + height) * 4] = color.r;
    bumper->pixels[((*bumper).width * width + height) * 4 + 1] = color.g;
    bumper->pixels[((*bumper).width * width + height) * 4 + 2] = color.b;
    bumper->pixels[((*bumper).width * width + height) * 4 + 3] = color.a;
    return (0);
}