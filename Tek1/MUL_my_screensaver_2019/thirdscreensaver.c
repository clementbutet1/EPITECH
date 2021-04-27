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
#include <sys/stat.h>
#include <math.h>

void putobject(framebuffer_t *image, int x, int y, sfColor color)
{
    int x0 =  550 + 1;
    int y0 =  950 + 1;

    my_putpixel(image, x0 + x, y0 + y, color);
    my_putpixel(image, x0 - x, y0 + y, color);
    my_putpixel(image, x0 + x, y0 - y, color);
    my_putpixel(image, x0 - x, y0 - y, color);
    my_putpixel(image, x0 + y, y0 + x, color);
    my_putpixel(image, x0 - y, y0 + x, color);
    my_putpixel(image, x0 + y, y0 - x, color);
    my_putpixel(image, x0 - y, y0 - x, color);
}

void my_put_square(framebuffer_t *image, sfColor color)
{
    int radius = rand() % 550 + 1;
    int f = 1;
    int fx = 0;
    int fy = -2 * radius;
    int x = 0;
    int y = radius;

    while (x < y) {
        if (f >= 0) {
            y--;
            fy = fy + 2;
            f += fy;
        }
        x++;
        fx = fx + 2;
        f += fx - 1;
        putobject(image, x, y, color);
    }
}

void endfct3(sfSprite *sprite, sfRenderWindow *wind, framebuffer_t *bum)
{
    int rad = rand() % 200 + 1;
    int red = rand() % 255 + 1;
    int green = rand() % 255 + 1;
    int blue = rand() % 255 + 1;

    sfRenderWindow_drawSprite(wind, sprite, NULL);
    sfRenderWindow_display(wind);
    sfRenderWindow_clear(wind, sfYellow);
    my_put_square(bum, sfColor_fromRGB(red, green, blue));
}

void thirdscreensaver(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *wind;
    wind = sfRenderWindow_create(mode, "3screensaver", sfResize | sfClose, 0);
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
        endfct3(sprite, wind, bum);
    }
    sfRenderWindow_destroy(wind);
}