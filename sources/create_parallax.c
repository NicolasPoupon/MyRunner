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

void set_position_parallax(struct para *b)
{
    sfSprite_setPosition(b->cloud, b->pos_cloud);
    sfSprite_setPosition(b->purple, b->pos_purple);
    sfSprite_setPosition(b->mauve, b->pos_mauve);
    sfSprite_setPosition(b->pink, b->pos_pink);
    sfSprite_setPosition(b->ground, b->pos_ground);
}

void move_parallax(struct para *b)
{
    b->pos_cloud.x -= 2;
    b->pos_purple.x -= 4;
    b->pos_mauve.x -= 6;
    b->pos_pink.x -= 10;
    if (b->pos_cloud.x < - 1790)
        b->pos_cloud.x = 0;
    if (b->pos_purple.x < - 1790)
        b->pos_purple.x = 0;
    if (b->pos_mauve.x < - 1790)
        b->pos_mauve.x = 0;
    if (b->pos_pink.x < - 1790)
        b->pos_pink.x = 0;
    set_position_parallax(b);
}

void set_scale_parallax(struct para *b)
{
    sfSprite_setScale(b->cloud, vect(0.7, 0.7));
    sfSprite_setScale(b->purple, vect(0.7, 0.7));
    sfSprite_setScale(b->mauve, vect(0.7, 0.7));
    sfSprite_setScale(b->pink, vect(0.7, 0.7));
    sfSprite_setScale(b->ground, vect(1, 1));
}

void set_texture_parallax(struct para *b)
{
    b->ground = sfSprite_create();
    b->pink = sfSprite_create();
    b->mauve = sfSprite_create();
    b->purple = sfSprite_create();
    b->cloud = sfSprite_create();
    b->t_ground = sfTexture_createFromFile("sprites/back_ground.png", NULL);
    b->t_pink = sfTexture_createFromFile("sprites/back_pink.png", NULL);
    b->t_mauve = sfTexture_createFromFile("sprites/back_mauve.png", NULL);
    b->t_purple = sfTexture_createFromFile("sprites/back_purple.png", NULL);
    b->t_cloud = sfTexture_createFromFile("sprites/back_cloud.png", NULL);
    sfSprite_setTexture(b->ground, b->t_ground, sfFalse);
    sfSprite_setTexture(b->pink, b->t_pink, sfFalse);
    sfSprite_setTexture(b->mauve, b->t_mauve, sfFalse);
    sfSprite_setTexture(b->purple, b->t_purple, sfFalse);
    sfSprite_setTexture(b->cloud, b->t_cloud, sfFalse);
}

struct para *create_parallax(struct para *b)
{
    b = malloc(sizeof(struct para) * 2);
    set_texture_parallax(b);
    b->pos_cloud = vect(0, 30);
    b->pos_purple = vect(0, 115);
    b->pos_mauve = vect(0, 200);
    b->pos_pink = vect(0, 285);
    b->pos_ground = vect(0, 0);
    set_position_parallax(b);
    set_scale_parallax(b);
    return b;
}
