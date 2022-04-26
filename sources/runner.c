/*
** EPITECH PROJECT, 2021
** runner.c
** File description:
** runner
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void draw_menu(struct menu *menu)
{
    menu->mouse = sfMouse_getPositionRenderWindow(menu->window);
    sfRenderWindow_drawSprite(menu->window, menu->background, NULL);
    sfRenderWindow_drawRectangleShape(menu->window, menu->rect_start, NULL);
    sfRenderWindow_drawRectangleShape(menu->window, menu->rect_lvl1, NULL);
    sfRenderWindow_drawRectangleShape(menu->window, menu->rect_lvl2, NULL);
    sfRenderWindow_drawText(menu->window, menu->start, NULL);
    sfRenderWindow_drawText(menu->window, menu->lvl1, NULL);
    sfRenderWindow_drawText(menu->window, menu->lvl2, NULL);
    sfRenderWindow_drawText(menu->window, menu->name, NULL);
    sfRenderWindow_display(menu->window);
}

void display_menu(struct menu *menu, sfEvent event, int framerate)
{
    draw_menu(menu);
    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed &&
            pos_is_inrect(menu->mouse, vect(600, 220), vect(650, 350)) == 1)
            start_game(menu, event, framerate);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(menu->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(menu->window);
        if (event.type == sfEvtMouseButtonPressed &&
            pos_is_inrect(menu->mouse, vect(600, 220), vect(200, 700)) == 1)
            start_lvl(menu, event, framerate, 1);
        if (event.type == sfEvtMouseButtonPressed &&
            pos_is_inrect(menu->mouse, vect(600, 220), vect(1100, 700)) == 1)
            start_lvl(menu, event, framerate, 2);
    }
    sfRenderWindow_clear(menu->window, sfBlack);
}

int runner(int framerate)
{
    struct menu *menu = create_menu(menu, framerate);
    sfEvent event;

    sfMusic_play(menu->music);
    sfMusic_setLoop(menu->music, sfTrue);
    while (sfRenderWindow_isOpen(menu->window)) {
        display_menu(menu, event, framerate);
    }
    sfMusic_stop(menu->music);
    destroy_menu(menu);
    return (0);
}
