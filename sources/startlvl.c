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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fill_lvl(char *buff, int **lvl)
{
    int i = 0;
    int j = 0;

    for (; i != 20; i++) {
        lvl[0][i] = my_getnbr(buff);
        buff += 4;
    }
    buff += 3;
    for (; j != 40; j++) {
        lvl[1][j] = my_getnbr(buff);
        buff += 4;
    }
    lvl[0][i] = - 1;
    lvl[1][j] = - 1;
}

int **my_lvl(int lvl)
{
    int i = 0;
    int fd;
    int **mylvl = malloc(sizeof(int*) * 3);
    char *buff = malloc(sizeof(char) * 247);

    mylvl[2] = NULL;
    mylvl[0] = malloc(sizeof(int) * 21);
    mylvl[1] = malloc(sizeof(int) * 41);
    if (lvl == 1)
        fd = open("level/level1.txt", O_RDONLY);
    if (lvl == 2)
        fd = open("level/level2.txt", O_RDONLY);
    read(fd, buff, 246);
    buff[246] = '\0';
    fill_lvl(buff, mylvl);
    free(buff);
    close(fd);
    return (mylvl);
}

void start_lvl_music(struct menu *menu, struct obj *obj)
{
    sfMusic_stop(menu->music);
    sfMusic_play(obj->music->game);
    sfMusic_setLoop(obj->music->game, sfTrue);
}

int start_lvl(struct menu *menu, sfEvent event, int framerate, int lvl)
{
    struct obj *obj = fill_obj(obj, menu->font);
    int restart = 0;

    menu->mylvl = my_lvl(lvl);
    menu->nb_obs = 0;
    menu->nb_ghost = 0;
    start_lvl_music(menu, obj);
    while (sfRenderWindow_isOpen(menu->window)) {
        draw_game_lvl(obj, event, menu);
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
