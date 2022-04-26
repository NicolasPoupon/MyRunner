/*
** EPITECH PROJECT, 2021
** startgame.c
** File description:
** start game
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

struct obj *fill_obj(struct obj *obj, sfFont *font)
{
    obj = malloc(sizeof(struct obj));
    obj->para = create_parallax(obj->para);
    obj->runner = create_runner(obj->runner);
    obj->jump = create_jump(obj->jump);
    obj->floor = create_floor(obj->floor);
    obj->music = create_music(obj->music);
    obj->score = create_score(obj->score, font);
    obj->enemy = create_enemy(obj->enemy);
    return obj;
}

int if_runner_hit_obs(struct jump *j, struct floor *f, struct menu *menu)
{
    if (run_is_inrect(j->pos_jump, f->size_obs, f->pos_obs) == 1)
        return 1;
    return 0;
}

int start_game(struct menu *menu, sfEvent event, int framerate)
{
    struct obj *obj = fill_obj(obj, menu->font);
    int restart = 0;

    sfMusic_stop(menu->music);
    sfMusic_play(obj->music->game);
    sfMusic_setLoop(obj->music->game, sfTrue);
    while (sfRenderWindow_isOpen(menu->window)) {
        draw_game(obj, event, menu);
        if (if_runner_hit_obs(obj->jump, obj->floor, menu) == 1) {
            sfMusic_stop(obj->music->game);
            game_over(obj->score, menu, event, obj->music->die);
        }
    }
    restart = menu->if_restart;
    sfMusic_stop(obj->music->game);
    destroy_obj(obj);
    if (restart == 1)
        runner(framerate);
    return (0);
}
