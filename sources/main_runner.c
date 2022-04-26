/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"
#include "../include/p.h"

static void print_usage_h(void)
{
    my_putstr("USAGE\n    ./my_runner framerate\n\nDESCRIPTION\n");
    my_putstr("Jump with space to dodge the obstacles");
    my_putstr("and to win the maximum of point\n");
    my_putstr("Choose the framerate when you start the game (60 advised)\n");
    my_putstr("Press the key escape of your keyboard to leave the game.\n");
    my_putstr("The game end when you hit 3 ghosts or one obstacle\n");
    my_putstr("In the menu you can click on start to launch the game ");
    my_putstr("in infinite mode or choose a level");
    my_putstr("Good luck :)\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage_h();
        return (0);
    }
    if (ac == 2) {
        runner(my_getnbr(av[1]));
        return (0);
    }
    my_putstr("Wrong number of arguments, try './my_runner' ");
    my_putstr("to start the game or './my_runner -h' to see the rules.\n");
    return (0);
}
