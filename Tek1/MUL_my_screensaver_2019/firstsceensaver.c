/*
** EPITECH PROJECT, 2019
** firstscreensaver.c
** File description:
** firstscreensaver.c
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

void putline(framebuffer_t *image, int x, int y, sfColor color)
{
    my_putpixel(image, x + 100, y + 100, color);
    my_putpixel(image, x + 100, y + 100, color);
    my_putpixel(image, x + 100, y + 100, color);
    my_putpixel(image, x + 100, y + 100, color);
    my_putpixel(image, y + 100, x + 100, color);
    my_putpixel(image, y + 100, x + 100, color);
    my_putpixel(image, y + 100, x + 100, color);
    my_putpixel(image, y + 100, x + 100, color);
}

void my_print_line(framebuffer_t *image, int x0, int y0, sfColor color)
{
    int radius = rand() % 2000 + 1;
    int f = 1;
    int fx = 0;
    int fy = -2 * radius;
    int x = rand() % 2000 + 1;
    int y = radius;

    while (x < y) {
        y--;
        fy += 5;
        f += fy;
        x++;
        fx += 5;
        f += fx - 1;
        putline(image, x, y, color);
    }
}

void endfct1(sfSprite *sprite, sfRenderWindow *wind, framebuffer_t *bum)
{
    int i = rand() % 1920 + 1;
    int j = rand() % 1080 + 1;
    int rad = rand() % 200 + 1;
    int red = rand() % 255 + 1;
    int green = rand() % 255 + 1;
    int blue = rand() % 255 + 1;

    sfRenderWindow_drawSprite(wind, sprite, NULL);
    sfRenderWindow_display(wind);
    sfRenderWindow_clear(wind, sfRed);
    my_print_line(bum, i, j, sfColor_fromRGB(red, green, blue));
    my_print_line(bum, i, j, sfColor_fromRGB(red, green, blue));
    my_print_line(bum, i, j, sfColor_fromRGB(red, green, blue));
    my_print_line(bum, i, j, sfColor_fromRGB(red, green, blue));
    my_print_line(bum, i, j, sfColor_fromRGB(red, green, blue));
    my_print_line(bum, i, j, sfColor_fromRGB(red, green, blue));
    my_print_line(bum, i, j, sfColor_fromRGB(red, green, blue));
}

void firstscreensaver(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *wind;
    wind = sfRenderWindow_create(mode, "1screensaver", sfResize | sfClose, 0);
    sfEvent event;
    framebuffer_t *bum = framebuffer_create(1920, 1080);
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfSprite *sprite = sfSprite_create();
    sfRenderWindow_setFramerateLimit(wind, 60);

    while (sfRenderWindow_isOpen(wind)) {
        sfTexture_updateFromPixels(texture, bum->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        while (sfRenderWindow_pollEvent(wind, &event))
            turnoffwind(event, wind);
        endfct1(sprite, wind, bum);
    }
    sfRenderWindow_destroy(wind);
}