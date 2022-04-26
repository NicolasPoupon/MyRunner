/*
** EPITECH PROJECT, 2021
** p.h
** File description:
** prototypes fct
*/

#ifndef _P_H
    #define _P_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

struct menu {
    sfSprite *background;
    sfTexture *t_back;
    sfMusic *music;
    sfText *start;
    sfText *lvl1;
    sfText *lvl2;
    sfText *name;
    sfFont *font;
    sfRectangleShape *rect_start;
    sfRectangleShape *rect_lvl1;
    sfRectangleShape *rect_lvl2;
    sfRenderWindow *window;
    int if_restart;
    sfVector2i mouse;
    int **mylvl;
    int nb_ghost;
    int nb_obs;
};

struct para {
    sfSprite *ground;
    sfSprite *pink;
    sfSprite *mauve;
    sfSprite *purple;
    sfSprite *cloud;
    sfTexture *t_ground;
    sfTexture *t_pink;
    sfTexture *t_mauve;
    sfTexture *t_purple;
    sfTexture *t_cloud;
    sfVector2f pos_ground;
    sfVector2f pos_pink;
    sfVector2f pos_mauve;
    sfVector2f pos_purple;
    sfVector2f pos_cloud;
};

struct jump {
    sfSprite *jump;
    sfTexture *t_jump;
    sfVector2f pos_jump;
    sfIntRect *rect;
    sfClock *clock;
    sfTime time;
    int if_jump;
    int if_fall;
    int nb_jump;
};

struct runner {
    int nb_life;
    sfSprite *runner;
    sfTexture *t_runner;
    sfVector2f pos_runner;
    sfIntRect *rect;
    sfClock *clock;
    sfTime time;
};

struct music {
    sfMusic *game;
    sfSound *die;
    sfSound *obs;
    sfSound *vict;
    sfSound *ghost;
    sfSoundBuffer *buff_die;
    sfSoundBuffer *buff_obs;
    sfSoundBuffer *buff_ghost;
    sfSoundBuffer *buff_vict;
};

struct floor {
    sfRectangleShape *obstacle;
    sfRectangleShape *ground;
    sfVector2f pos_obs;
    sfVector2f size_obs;
    int pos_floor_y;
    int upd;
    sfClock *clock;
    sfTime time;
};

struct enemy {
    sfSprite *spike;
    sfTexture *t_spike;
    sfVector2f pos_spike;
    int hit_spike;
    sfSprite *ghost;
    sfTexture *t_ghost;
    sfVector2f pos_ghost;
    int hit_ghost;
    sfClock *clock;
    int ifwin;
    sfTime time;
};

struct score {
    sfSprite *heart1;
    sfSprite *heart2;
    sfSprite *heart3;
    sfTexture *t_heart;
    int nb_life;
    sfClock *clock;
    sfTime time;
    sfText *score;
    int if_flash;
};

struct obj {
    struct para *para;
    struct runner *runner;
    struct jump *jump;
    struct music *music;
    struct floor *floor;
    struct score *score;
    struct enemy *enemy;
    sfVector2i mouse;
};

struct obj *fill_obj(struct obj *obj, sfFont *font);
int if_runner_hit_obs(struct jump *j, struct floor *f, struct menu *menu);
int start_lvl(struct menu *menu, sfEvent event, int framerate, int lvl);
void draw_game_lvl(struct obj *obj, sfEvent event, struct menu *menu);
void lvl_over(struct score *score, struct menu *m, sfEvent e, struct music *c);

int rand_int(int min, int max);
void update_if_obstacle(struct obj *obj, sfEvent event, struct menu *menu);

void game_over(struct score *score, struct menu *m, sfEvent event, sfSound *d);

void draw_parallax(struct obj *obj, sfRenderWindow *window);
void draw_runner(struct obj *obj, sfRenderWindow *window);
void event_draw_game(struct obj *obj, sfEvent event, struct menu *menu);
void draw_score(struct score *score, sfRenderWindow *window, int draw_s);

void destroy_enemy(struct enemy *e);
void destroy_menu(struct menu *menu);
void destroy_runner(struct runner *r);
void destroy_jump(struct jump *j);
void destroy_music(struct music *m);
void destroy_para(struct para *p);
void destroy_obj(struct obj *obj);
void destroy_score(struct score *score);

int run_is_inrect(sfVector2f pos, sfVector2f size_rec, sfVector2f pos_rec);
int pos_is_inrect(sfVector2i pos, sfVector2f pos_rec, sfVector2f size_rec);

void update_floor(struct obj *obj, sfEvent event, struct menu *menu);
void draw_floor(struct floor *floor, sfRenderWindow *window, struct enemy *e);
void draw_game(struct obj *obj, sfEvent event, struct menu *menu);
void draw_enemy(struct obj *obj, struct menu *m, sfEvent e, sfMusic *g);

struct enemy *create_enemy(struct enemy *e);
struct menu *create_menu(struct menu *m, int framerate);
struct floor *create_floor(struct floor *f);
struct jump *create_jump(struct jump *j);
struct score *create_score(struct score *s, sfFont *font);
struct music *create_music(struct music *m);
struct runner *create_runner(struct runner *r);

void anim_fall(struct jump *jump);
void anim_floor(struct floor *floor, struct enemy *enemy);
void anim_jump(struct jump *jump);
void anim_runner(struct runner *runner);

void calc_high_obs(struct floor *floor);
void move_rect(sfIntRect *rect);
int rand_int(int min, int max);
void move_parallax(struct para *b);
int start_game(struct menu *menu, sfEvent event, int framerate);
sfVector2f vect(float x, float y);
sfText *create_text(sfFont *font, sfVector2f pos, char *str, int size);
sfIntRect *create_int_rect(sfIntRect *rect, int x, int y);
sfRectangleShape *create_rect(sfVector2f size, sfVector2f pos);
struct para *create_parallax(struct para *b);
int runner(int framerate);

#endif
