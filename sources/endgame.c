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

void event_game_over(struct menu *menu, sfEvent event)
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

void drawend(struct score *score, struct menu *m, sfText *over, sfText *mysc)
{
    sfRenderWindow_clear(m->window, sfWhite);
    sfRenderWindow_drawSprite(m->window, m->background, NULL);
    sfRenderWindow_drawText(m->window, over, NULL);
    sfRenderWindow_drawText(m->window, mysc, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->rect_start, NULL);
    sfRenderWindow_drawText(m->window, m->start, NULL);
    sfRenderWindow_drawText(m->window, score->score, NULL);
    sfRenderWindow_display(m->window);
}

void game_over(struct score *score, struct menu *m, sfEvent event, sfSound *d)
{
    sfText *over = create_text(m->font, vect(230, 50), "Game Over", 200);
    sfText *myscore = create_text(m->font, vect(230, 700), "Score :", 100);

    sfSound_play(d);
    sfText_setColor(over, sfBlack);
    sfText_setColor(myscore, sfBlack);
    sfText_setString(m->start, "retry");
    sfText_setPosition(score->score, vect(830, 700));
    sfText_setCharacterSize(score->score, 100);
    while (sfRenderWindow_isOpen(m->window)) {
        drawend(score, m, over, myscore);
        m->mouse = sfMouse_getPositionRenderWindow(m->window);
        while (sfRenderWindow_pollEvent(m->window, &event))
            event_game_over(m, event);
    }
    sfText_destroy(over);
    sfText_destroy(myscore);
}
