/*
** EPITECH PROJECT, 2021
** draw_game.c
** File description:
** draw game
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void draw_parallax(struct obj *obj, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, obj->para->ground, NULL);
    sfRenderWindow_drawSprite(window, obj->para->cloud, NULL);
    sfRenderWindow_drawSprite(window, obj->para->purple, NULL);
    sfRenderWindow_drawSprite(window, obj->para->mauve, NULL);
    sfRenderWindow_drawSprite(window, obj->para->pink, NULL);
}

void draw_runner(struct obj *obj, sfRenderWindow *window)
{
    if (obj->jump->if_jump == 0 && obj->jump->if_fall == 0) {
        anim_runner(obj->runner);
        sfRenderWindow_drawSprite(window, obj->runner->runner, NULL);
    }
    if (obj->jump->if_fall == 1 && obj->jump->if_jump == 0) {
        anim_fall(obj->jump);
        obj->runner->pos_runner.y = obj->jump->pos_jump.y;
        sfRenderWindow_drawSprite(window, obj->jump->jump, NULL);
    }
    if (obj->jump->if_jump == 1) {
        anim_jump(obj->jump);
        sfRenderWindow_drawSprite(window, obj->jump->jump, NULL);
    }
}

void draw_score(struct score *score, sfRenderWindow *window, int draw_s)
{
    char *nb_sec = NULL;

    score->time = sfClock_getElapsedTime(score->clock);
    nb_sec = int_to_str(score->time.microseconds / 100000);
    sfText_setString(score->score, nb_sec);
    if ((score->time.microseconds / 100000) != 0)
        free(nb_sec);
    if (draw_s == 1)
        sfRenderWindow_drawText(window, score->score, NULL);
    sfRenderWindow_drawSprite(window, score->heart1, NULL);
    if (score->nb_life >= 2)
        sfRenderWindow_drawSprite(window, score->heart2, NULL);
    if (score->nb_life == 3)
        sfRenderWindow_drawSprite(window, score->heart3, NULL);
}

void draw_game(struct obj *obj, sfEvent event, struct menu *menu)
{
    sfRenderWindow_clear(menu->window, sfBlack);
    obj->mouse = sfMouse_getPositionRenderWindow(menu->window);
    update_floor(obj, event, menu);
    move_parallax(obj->para);
    draw_parallax(obj, menu->window);
    draw_floor(obj->floor, menu->window, obj->enemy);
    draw_enemy(obj, menu, event, obj->music->game);
    draw_runner(obj, menu->window);
    draw_score(obj->score, menu->window, 1);
    if (obj->score->if_flash == 1) {
        sfRenderWindow_clear(menu->window, sfWhite);
        sfSound_play(obj->music->ghost);
        obj->score->if_flash = 0;
    }
    sfRenderWindow_display(menu->window);
    while (sfRenderWindow_pollEvent(menu->window, &event))
        event_draw_game(obj, event, menu);
}
