/*
** EPITECH PROJECT, 2021
** create_menu.c
** File description:
** create menu
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void destroy_menu(struct menu *menu)
{
    sfSprite_destroy(menu->background);
    sfTexture_destroy(menu->t_back);
    sfMusic_destroy(menu->music);
    sfText_destroy(menu->start);
    sfText_destroy(menu->lvl1);
    sfText_destroy(menu->lvl2);
    sfText_destroy(menu->name);
    sfFont_destroy(menu->font);
    sfRectangleShape_destroy(menu->rect_start);
    sfRectangleShape_destroy(menu->rect_lvl1);
    sfRectangleShape_destroy(menu->rect_lvl2);
    sfRenderWindow_destroy(menu->window);
    free(menu);
}

sfRenderWindow *create_window(sfRenderWindow *window, int framerate)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfUint32 flag = sfDefaultStyle | sfResize;

    window = sfRenderWindow_create(video_mode, "Window", flag, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return (window);
}

struct menu *create_menu(struct menu *m, int framerate)
{
    m = malloc(sizeof(struct menu) * 2);
    m->background = sfSprite_create();
    m->t_back = sfTexture_createFromFile("sprites/back_menu.png", NULL);
    sfSprite_setTexture(m->background, m->t_back, sfFalse);
    sfSprite_setPosition(m->background, vect(0, 0));
    m->music = sfMusic_createFromFile("sprites/music_menu.ogg");
    m->font = sfFont_createFromFile("sprites/police.TTF");
    m->start = create_text(m->font, vect(750, 400), "start", 100);
    m->lvl1 = create_text(m->font, vect(230, 750), "level 1", 100);
    m->lvl2 = create_text(m->font, vect(1120, 750), "level 2", 100);
    m->name = create_text(m->font, vect(250, 50), "My Runner", 200);
    m->rect_start = create_rect(vect(600, 220), vect(650, 350));
    sfRectangleShape_setFillColor(m->rect_start, sfRed);
    m->rect_lvl1 = create_rect(vect(600, 220), vect(200, 700));
    sfRectangleShape_setFillColor(m->rect_lvl1, sfGreen);
    m->rect_lvl2 = create_rect(vect(600, 220), vect(1100, 700));
    sfRectangleShape_setFillColor(m->rect_lvl2, sfBlue);
    m->window = create_window(m->window, framerate);
    m->if_restart = 0;
    return m;
}
