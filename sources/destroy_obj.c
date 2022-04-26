/*
** EPITECH PROJECT, 2021
** destroy_obj.c
** File description:
** destroy obj
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void destroy_runner(struct runner *r)
{
    sfSprite_destroy(r->runner);
    sfTexture_destroy(r->t_runner);
    free(r->rect);
    sfClock_destroy(r->clock);
    free(r);
}

void destroy_jump(struct jump *j)
{
    sfSprite_destroy(j->jump);
    sfTexture_destroy(j->t_jump);
    free(j->rect);
    sfClock_destroy(j->clock);
    free(j);
}

void destroy_para(struct para *p)
{
    sfSprite_destroy(p->ground);
    sfSprite_destroy(p->pink);
    sfSprite_destroy(p->mauve);
    sfSprite_destroy(p->purple);
    sfSprite_destroy(p->cloud);
    sfTexture_destroy(p->t_ground);
    sfTexture_destroy(p->t_pink);
    sfTexture_destroy(p->t_mauve);
    sfTexture_destroy(p->t_purple);
    sfTexture_destroy(p->t_cloud);
    free(p);
}

void destroy_obj(struct obj *obj)
{
    destroy_para(obj->para);
    destroy_runner(obj->runner);
    destroy_jump(obj->jump);
    destroy_music(obj->music);
    destroy_score(obj->score);
    destroy_enemy(obj->enemy);
    sfRectangleShape_destroy(obj->floor->ground);
    sfRectangleShape_destroy(obj->floor->obstacle);
    sfClock_destroy(obj->floor->clock);
    free(obj->floor);
}
