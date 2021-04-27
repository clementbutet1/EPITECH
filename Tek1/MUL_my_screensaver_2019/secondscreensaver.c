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

int draw_circle(framebuffer_t *buff, sfVector2i center, int i)
{
    int rad = rand() % 200 + 1;
    int red = rand() % 255 + 1;
    int green = rand() % 255 + 1;
    int blue = rand() % 255 + 1;

    for (int j = center.x-rad; j <= center.x+rad; j++) {
        if (pow(j - center.x, 2) + pow(i - center.y, 2) <= pow(rad, 2))
            my_putpixel(buff, j, i, sfColor_fromRGB(red, green, blue));
    }
}

int put_color(framebuffer_t *buff, sfVector2i center)
{
    int rad = rand() % 200 + 1;
    int red = rand() % 255 + 1;
    int green = rand() % 255 + 1;
    int blue = rand() % 255 + 1;
    for (int i = center.y-rad; i <= center.y+rad; i++) {
        draw_circle(buff, center, i);
    }
    return (0);
}

int position(framebuffer_t *buffer)
{
    sfVector2i center;
    center.x = 200;
    center.y = 10;
    put_color(buffer, center);
    center.x = 1000;
    center.y = 950;
    put_color(buffer, center);
    center.x = 300;
    center.y = 950;
    put_color(buffer, center);
    center.x = 1000;
    center.y = 10;
    put_color(buffer, center);
    return (0);
}

void endfct2(sfSprite *sprite, sfRenderWindow *wind, framebuffer_t *bum)
{
    sfRenderWindow_drawSprite(wind, sprite, NULL);
    sfRenderWindow_display(wind);
    sfRenderWindow_clear(wind, sfBlack);
    position(bum);
}

void secondscreensaver(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *wind;
    wind = sfRenderWindow_create(mode, "2screensaver", sfResize | sfClose, 0);
    sfEvent event;
    framebuffer_t *bum = framebuffer_create(1920, 1080);
    sfTexture *tex = sfTexture_create(1920, 1080);
    sfSprite *sprite = sfSprite_create();
    sfRenderWindow_setFramerateLimit(wind, 60);

    while (sfRenderWindow_isOpen(wind)) {
        sfTexture_updateFromPixels(tex, bum->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, tex, sfTrue);
        while (sfRenderWindow_pollEvent(wind, &event))
            turnoffwind(event, wind);
        endfct2(sprite, wind, bum);
    }
    sfRenderWindow_destroy(wind);
}