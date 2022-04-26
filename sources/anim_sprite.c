/*
** EPITECH PROJECT, 2021
** anim_runner.c
** File description:
** anim runner
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void anim_runner(struct runner *runner)
{
    runner->time = sfClock_getElapsedTime(runner->clock);
    if (runner->time.microseconds > 100000) {
        sfClock_restart(runner->clock);
        move_rect(runner->rect);
        runner->time.microseconds -= 100000;
        sfSprite_setTextureRect(runner->runner, runner->rect[0]);
    }
}

void anim_floor(struct floor *floor, struct enemy *enemy)
{
    floor->time = sfClock_getElapsedTime(floor->clock);
    if (floor->time.microseconds > 12000) {
        sfClock_restart(floor->clock);
        floor->pos_obs.x -= 10;
        enemy->pos_spike.x -= 14;
        enemy->pos_spike.y = floor->pos_floor_y - 120;
        if (enemy->pos_spike.x <= 0)
            enemy->pos_spike.x = 1920;
        sfSprite_setPosition(enemy->spike, enemy->pos_spike);
        sfRectangleShape_setPosition(floor->obstacle, floor->pos_obs);
        floor->time.microseconds -= 12000;
    }
}

void anim_jump(struct jump *jump)
{
    jump->time = sfClock_getElapsedTime(jump->clock);
    if (jump->time.microseconds > 30000) {
        sfClock_restart(jump->clock);
        jump->rect->left += 160;
        jump->pos_jump.y -= 20;
        jump->time.microseconds = -30000;
        sfSprite_setPosition(jump->jump, jump->pos_jump);
        sfSprite_setTextureRect(jump->jump, jump->rect[0]);
        if (jump->rect->left == 1120) {
            jump->if_jump = 0;
            jump->rect->left = 0;
            jump->if_fall == 1;
        }
    }
}

void anim_fall(struct jump *jump)
{
    jump->time = sfClock_getElapsedTime(jump->clock);
    if (jump->time.microseconds > 30000) {
        jump->rect->left = 960;
        sfSprite_setTextureRect(jump->jump, jump->rect[0]);
        sfClock_restart(jump->clock);
        jump->pos_jump.y += 10;
        sfSprite_setPosition(jump->jump, jump->pos_jump);
        jump->time.microseconds = -30000;
    }
}
