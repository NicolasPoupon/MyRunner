/*
** EPITECH PROJECT, 2021
** draw_game_lvl.c
** File description:
** draw game lvl
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void anim_ghost_lvl(struct enemy *enemy, struct menu *menu)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    if (enemy->time.microseconds > 12000) {
        sfClock_restart(enemy->clock);
        enemy->pos_ghost.x -= 20;
        if (enemy->pos_ghost.x <= 0) {
            enemy->pos_ghost.x = 1920;
            enemy->pos_ghost.y = menu->mylvl[0][menu->nb_ghost];
            if (menu->nb_ghost == 10)
                enemy->ifwin = 1;
            menu->nb_ghost++;
            enemy->hit_ghost = 0;
        }
        enemy->time.microseconds -= 12000;
    }
}

void draw_enemylvl(struct obj *obj, struct menu *m, sfEvent e, sfMusic *g)
{
    sfRenderWindow_drawSprite(m->window, obj->enemy->ghost, NULL);
    anim_ghost_lvl(obj->enemy, m);
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

void update_lvl_obstacle(struct obj *obj, sfEvent event, struct menu *menu)
{
    if (obj->floor->pos_obs.x <= 570 && obj->floor->upd == 0) {
        calc_high_obs(obj->floor);
        obj->floor->upd = 1;
    }
    if (obj->floor->pos_obs.x + obj->floor->size_obs.x <= 570) {
        obj->floor->pos_floor_y = 900;
        obj->floor->upd = 0;
    }
    if (obj->floor->pos_obs.x + obj->floor->size_obs.x <= 0) {
        obj->floor->pos_obs.x = 1920;
        obj->floor->pos_obs.y = menu->mylvl[1][menu->nb_obs];
        menu->nb_obs++;
        obj->floor->size_obs.x = menu->mylvl[1][menu->nb_obs];
        menu->nb_obs++;
        sfRectangleShape_setSize(obj->floor->obstacle, obj->floor->size_obs);
    }
}

void update_floor_lvl(struct obj *obj, sfEvent event, struct menu *menu)
{
    update_lvl_obstacle(obj, event, menu);
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

void draw_game_lvl(struct obj *obj, sfEvent event, struct menu *menu)
{
    sfRenderWindow_clear(menu->window, sfBlack);
    obj->mouse = sfMouse_getPositionRenderWindow(menu->window);
    update_floor_lvl(obj, event, menu);
    move_parallax(obj->para);
    draw_parallax(obj, menu->window);
    draw_floor(obj->floor, menu->window, obj->enemy);
    draw_enemylvl(obj, menu, event, obj->music->game);
    draw_runner(obj, menu->window);
    draw_score(obj->score, menu->window, 1);
    if (obj->score->if_flash == 1) {
        sfRenderWindow_clear(menu->window, sfWhite);
        sfSound_play(obj->music->ghost);
        obj->score->if_flash = 0;
    }
    if (obj->enemy->ifwin == 1)
        lvl_over(obj->score, menu, event, obj->music);
    sfRenderWindow_display(menu->window);
    while (sfRenderWindow_pollEvent(menu->window, &event))
        event_draw_game(obj, event, menu);
}
