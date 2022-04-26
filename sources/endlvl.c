/*
** EPITECH PROJECT, 2021
** endgame.c
** File description:
** end game
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void event_lvl_over(struct menu *menu, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(menu->window);
    if (event.type == sfEvtMouseButtonPressed &&
        pos_is_inrect(menu->mouse, vect(600, 220), vect(650, 350)) == 1) {
        menu->if_restart = 1;
        sfRenderWindow_close(menu->window);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(menu->window);
}

void drawelvl(struct score *score, struct menu *m, sfText *over)
{
    sfRenderWindow_clear(m->window, sfWhite);
    sfRenderWindow_drawSprite(m->window, m->background, NULL);
    sfRenderWindow_drawText(m->window, over, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->rect_start, NULL);
    sfRenderWindow_drawText(m->window, m->start, NULL);
    sfRenderWindow_display(m->window);
}

void lvl_over(struct score *score, struct menu *m, sfEvent e, struct music *c)
{
    sfText *over = create_text(m->font, vect(30, 50), "LEVEL FINISHED", 155);

    sfMusic_stop(c->game);
    sfSound_play(c->vict);
    sfText_setColor(over, sfBlack);
    sfText_setString(m->start, "Return to menu");
    sfText_setPosition(score->score, vect(830, 700));
    sfText_setCharacterSize(score->score, 100);
    sfText_setCharacterSize(m->start, 49);
    sfText_setPosition(m->start, vect(665, 430));
    while (sfRenderWindow_isOpen(m->window)) {
        drawelvl(score, m, over);
        m->mouse = sfMouse_getPositionRenderWindow(m->window);
        while (sfRenderWindow_pollEvent(m->window, &e))
            event_lvl_over(m, e);
    }
    sfText_destroy(over);
}
