/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/

#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
#include <SFML/Graphics.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
int my_putpixel(framebuffer_t *bumper, unsigned int width,
unsigned int height, sfColor color);
void splash(void);
int put_color(framebuffer_t *buff, sfVector2i center);
int position(framebuffer_t *buffer);
int draw_circle(framebuffer_t *buff, sfVector2i center, int i);
void turnoffwind(sfEvent, sfRenderWindow *wind);
void endfct1(sfSprite *sprite, sfRenderWindow *wind, framebuffer_t *bum);
void endfct2(sfSprite *sprite, sfRenderWindow *wind, framebuffer_t *bum);
void endfct3(sfSprite *sprite, sfRenderWindow *wind, framebuffer_t *bum);
void displayerror(void);
void displayhelp(void);
int other(char **av);
void putline(framebuffer_t *image, int x, int y, sfColor color);
void my_print_line(framebuffer_t *image, int x0, int y0, sfColor color);
void my_put_square(framebuffer_t *image, sfColor color);
void endfct3(sfSprite *sprite, sfRenderWindow *wind, framebuffer_t *bum);
void secondscreensaver(void);
void thirdscreensaver(void);
void firstscreensaver(void);


#endif/* FRAMEBUFFER_H_ */