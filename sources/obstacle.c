/*
** EPITECH PROJECT, 2021
** obstacle.c
** File description:
** obstacle manage
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int min, int max)
{
    int res = 0;

    srand(time(NULL));
    res = rand();
    if (res > max)
        res %= max;
    while (res < min)
        res += 100;
    res /= 10;
    res *= 10;
    return (res);
}

void calc_high_obs(struct floor *floor)
{
    floor->pos_floor_y -= floor->pos_floor_y - floor->pos_obs.y;
}

void update_if_obstacle(struct obj *obj, sfEvent event, struct menu *menu)
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
        obj->floor->pos_obs.y = rand_int(640, 870);
        obj->floor->size_obs.x = rand_int(400, 1000);
        sfRectangleShape_setSize(obj->floor->obstacle, obj->floor->size_obs);
    }
}
