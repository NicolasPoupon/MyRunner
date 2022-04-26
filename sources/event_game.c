/*
** EPITECH PROJECT, 2021
** event_game.c
** File description:
** event game
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void jump(struct obj *obj, sfEvent event, struct menu *menu)
{
    sfSound_play(obj->music->obs);
    obj->jump->if_jump = 1;
    obj->jump->nb_jump = 2;
    obj->jump->rect->left = 0;
    sfClock_restart(obj->runner->clock);
}

void jump2(struct obj *obj, sfEvent event, struct menu *menu)
{
    sfSound_play(obj->music->obs);
    obj->jump->if_jump = 1;
    obj->jump->nb_jump = 1;
    obj->jump->rect->left = 0;
    sfClock_restart(obj->runner->clock);
}

int game_pause(struct menu *menu, sfEvent event)
{
    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            return (0);
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(menu->window);
            return (0);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            sfRenderWindow_close(menu->window);
            return (0);
        }
    }
    return (1);
}

void draw_pause(struct menu *menu)
{
    sfText *pause = create_text(menu->font, vect(750, 400), "Pause", 100);

    sfRenderWindow_drawText(menu->window, pause, NULL);
    sfRenderWindow_display(menu->window);
}

void event_draw_game(struct obj *obj, sfEvent event, struct menu *menu)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(menu->window);
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeySpace && obj->jump->nb_jump == 1)
        jump(obj, event, menu);
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeySpace && obj->jump->nb_jump == 0)
        jump2(obj, event, menu);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(menu->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP) {
        draw_pause(menu);
        while (game_pause(menu, event) == 1);
    }
}
