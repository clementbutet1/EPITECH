/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** window display
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "task01", sfResize | sfClose, NULL);
    if (!window)
        return 0;
    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}

