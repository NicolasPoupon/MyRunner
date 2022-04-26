/*
** EPITECH PROJECT, 2021
** floor.c
** File description:
** floor manage
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

struct floor *create_floor(struct floor *f)
{
    f = malloc(sizeof(struct floor) * 2);
    f->pos_obs = vect(1920, 800);
    f->size_obs = vect(500, 1000);
    f->pos_floor_y = 900;
    f->obstacle = create_rect(f->size_obs, f->pos_obs);
    f->ground = create_rect(vect(1920, 300), vect(0, 900));
    sfRectangleShape_setFillColor(f->obstacle, sfBlack);
    sfRectangleShape_setFillColor(f->ground, sfBlack);
    f->clock = sfClock_create();
    f->upd = 0;
    return f;
}

void draw_floor(struct floor *floor, sfRenderWindow *window, struct enemy *e)
{
    anim_floor(floor, e);
    sfRenderWindow_drawRectangleShape(window, floor->ground, NULL);
    sfRenderWindow_drawRectangleShape(window, floor->obstacle, NULL);
}

void update_floor(struct obj *obj, sfEvent event, struct menu *menu)
{
    update_if_obstacle(obj, event, menu);
    if (obj->floor->pos_floor_y > obj->jump->pos_jump.y + 100
        && obj->jump->if_jump == 0) {
        obj->runner->pos_runner.y = 900;
        sfSprite_setPosition(obj->runner->runner, obj->runner->pos_runner);
        obj->jump->if_fall = 1;
    }
    if (obj->floor->pos_floor_y == obj->jump->pos_jump.y + 100
        && obj->jump->if_jump == 0) {
        obj->jump->rect->left = 0;
        obj->jump->if_fall = 0;
        obj->jump->time.microseconds = 0;
        obj->runner->pos_runner.y = obj->jump->pos_jump.y;
        obj->jump->nb_jump = 0;
        sfSprite_setPosition(obj->runner->runner, obj->runner->pos_runner);
    }
}
