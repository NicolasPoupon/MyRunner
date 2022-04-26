/*
** EPITECH PROJECT, 2021
** create_parallax.c
** File description:
** create parallaxe
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void move_rect(sfIntRect *rect)
{
    if (rect->left < 800) {
        rect->left += 160;
    } else {
        rect->left = 0;
    }
}

struct runner *create_runner(struct runner *r)
{
    r = malloc(sizeof(struct runner) * 2);
    r->nb_life = 3;
    r->runner = sfSprite_create();
    r->t_runner = sfTexture_createFromFile("sprites/runner_run.png", NULL);
    sfSprite_setTexture(r->runner, r->t_runner, sfFalse);
    r->pos_runner = vect(500, 800);
    sfSprite_setPosition(r->runner, r->pos_runner);
    r->rect = create_int_rect(r->rect, 0, 165);
    sfSprite_setScale(r->runner, vect(0.6, 0.6));
    sfSprite_setTextureRect(r->runner, r->rect[0]);
    r->clock = sfClock_create();
    return r;
}

struct jump *create_jump(struct jump *j)
{
    j = malloc(sizeof(struct jump) * 2);
    j->jump = sfSprite_create();
    j->t_jump = sfTexture_createFromFile("sprites/runner_jump.png", NULL);
    sfSprite_setTexture(j->jump, j->t_jump, sfFalse);
    j->pos_jump = vect(500, 800);
    sfSprite_setPosition(j->jump, j->pos_jump);
    j->rect = create_int_rect(j->rect, 0, 165);
    sfSprite_setScale(j->jump, vect(0.6, 0.6));
    sfSprite_setTextureRect(j->jump, j->rect[0]);
    j->clock = sfClock_create();
    j->if_jump = 0;
    j->if_fall = 0;
    j->nb_jump = 0;
    return j;
}
