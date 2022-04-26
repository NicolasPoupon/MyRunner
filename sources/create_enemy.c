/*
** EPITECH PROJECT, 2021
** create_enemy.c
** File description:
** create enemy runner
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>
#include <time.h>

void destroy_enemy(struct enemy *e)
{
    sfSprite_destroy(e->spike);
    sfSprite_destroy(e->ghost);
    sfTexture_destroy(e->t_spike);
    sfTexture_destroy(e->t_ghost);
    sfClock_destroy(e->clock);
    free(e);
}

struct enemy *create_enemy(struct enemy *e)
{
    e = malloc(sizeof(struct enemy) * 2);
    e->spike = sfSprite_create();
    e->ghost = sfSprite_create();
    e->t_spike = sfTexture_createFromFile("sprites/spike.png", NULL);
    e->t_ghost = sfTexture_createFromFile("sprites/ghost.png", NULL);
    sfSprite_setTexture(e->spike, e->t_spike, sfFalse);
    sfSprite_setTexture(e->ghost, e->t_ghost, sfFalse);
    e->pos_spike = vect(1600, 780);
    e->pos_ghost = vect(1500, 500);
    sfSprite_setPosition(e->spike, e->pos_spike);
    sfSprite_setPosition(e->ghost, e->pos_ghost);
    sfSprite_setScale(e->spike, vect(0.25, 0.25));
    sfSprite_setScale(e->ghost, vect(0.5, 0.5));
    e->hit_spike = 0;
    e->hit_ghost = 0;
    e->ifwin = 0;
    e->clock = sfClock_create();
    return e;
}

void anim_ghost(struct enemy *enemy)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    if (enemy->time.microseconds > 12000) {
        sfClock_restart(enemy->clock);
        enemy->pos_ghost.x -= 20;
        if (enemy->pos_ghost.x <= 0) {
            enemy->pos_ghost.x = 1920;
            enemy->pos_ghost.y = rand_int(500, 800);
            enemy->hit_ghost = 0;
        }
        enemy->time.microseconds -= 12000;
    }
}

void draw_enemy(struct obj *obj, struct menu *m, sfEvent e, sfMusic *g)
{
    sfRenderWindow_drawSprite(m->window, obj->enemy->ghost, NULL);
    anim_ghost(obj->enemy);
    if (run_is_inrect(obj->jump->pos_jump, vect(70, 70), obj->enemy->pos_ghost)
        == 1 && obj->enemy->hit_ghost == 0) {
        obj->score->nb_life--;
        obj->score->if_flash = 1;
        if (obj->score->nb_life == 0) {
            sfMusic_stop(g);
            game_over(obj->score, m, e, obj->music->die);
        }
        obj->enemy->hit_ghost = 1;
    }
    sfSprite_setPosition(obj->enemy->ghost, obj->enemy->pos_ghost);
}
