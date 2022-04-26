/*
** EPITECH PROJECT, 2021
** create_music_score.c
** File description:
** create music
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>
#include <time.h>

void destroy_music(struct music *music)
{
    sfMusic_destroy(music->game);
    sfSound_destroy(music->die);
    sfSound_destroy(music->obs);
    sfSound_destroy(music->ghost);
    sfSound_destroy(music->vict);
    sfSoundBuffer_destroy(music->buff_die);
    sfSoundBuffer_destroy(music->buff_obs);
    sfSoundBuffer_destroy(music->buff_ghost);
    sfSoundBuffer_destroy(music->buff_vict);
    free(music);
}

struct music *create_music(struct music *m)
{
    m = malloc(sizeof(struct music) * 2);
    m->game = sfMusic_createFromFile("sprites/music_run.ogg");
    m->die = sfSound_create();
    m->obs = sfSound_create();
    m->vict = sfSound_create();
    m->ghost = sfSound_create();
    m->buff_die = sfSoundBuffer_createFromFile("sprites/sound_die.ogg");
    m->buff_obs = sfSoundBuffer_createFromFile("sprites/sound_obs.ogg");
    m->buff_ghost = sfSoundBuffer_createFromFile("sprites/sound_ghost.ogg");
    m->buff_vict = sfSoundBuffer_createFromFile("sprites/sound_vict.ogg");
    sfSound_setBuffer(m->die, m->buff_die);
    sfSound_setBuffer(m->vict, m->buff_vict);
    sfSound_setBuffer(m->obs, m->buff_obs);
    sfSound_setBuffer(m->ghost, m->buff_ghost);
    return m;
}

void destroy_score(struct score *score)
{
    sfSprite_destroy(score->heart1);
    sfSprite_destroy(score->heart2);
    sfSprite_destroy(score->heart3);
    sfTexture_destroy(score->t_heart);
    sfClock_destroy(score->clock);
    sfText_destroy(score->score);
    free(score);
}

struct score *create_score(struct score *s, sfFont *font)
{
    s = malloc(sizeof(struct score) * 2);
    s->heart1 = sfSprite_create();
    s->heart2 = sfSprite_create();
    s->heart3 = sfSprite_create();
    s->t_heart = sfTexture_createFromFile("sprites/heart.png", NULL);
    sfSprite_setTexture(s->heart1, s->t_heart, sfFalse);
    sfSprite_setTexture(s->heart2, s->t_heart, sfFalse);
    sfSprite_setTexture(s->heart3, s->t_heart, sfFalse);
    sfSprite_setPosition(s->heart1, vect(10, 100));
    sfSprite_setPosition(s->heart2, vect(70, 100));
    sfSprite_setPosition(s->heart3, vect(130, 100));
    sfSprite_setScale(s->heart1, vect(0.7, 0.7));
    sfSprite_setScale(s->heart2, vect(0.7, 0.7));
    sfSprite_setScale(s->heart3, vect(0.7, 0.7));
    s->nb_life = 3;
    s->clock = sfClock_create();
    s->score = create_text(font, vect(20, 20), "0", 50);
    sfText_setFillColor(s->score, sfBlack);
    s->if_flash = 0;
    return s;
}
