/*
** EPITECH PROJECT, 2021
** check_colli.c
** File description:
** check collision
*/

#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int pos_is_inrect(sfVector2i pos, sfVector2f size_rec, sfVector2f pos_rec)
{
    if (pos.x > pos_rec.x && pos.y > pos_rec.y &&
        pos.x < (pos_rec.x + size_rec.x) &&
        pos.y < (pos_rec.y + size_rec.y))
        return 1;
    return 0;
}

int run_is_inrect(sfVector2f pos, sfVector2f size_rec, sfVector2f pos_rec)
{
    if (pos.x > pos_rec.x && pos.y > pos_rec.y &&
        pos.x < (pos_rec.x + size_rec.x) &&
        pos.y < (pos_rec.y + size_rec.y)) {
        return 1;
    }
    if ((pos.x + 70) > pos_rec.x && (pos.y + 70) > pos_rec.y &&
        (pos.x + 70) < (pos_rec.x + size_rec.x) &&
        (pos.y + 70) < (pos_rec.y + size_rec.y))
        return 1;
    return 0;
}
