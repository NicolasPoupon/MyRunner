##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile project with libmy
##

SRC	=	sources/main_runner.c	\
		sources/runner.c	\
		sources/create_parallax.c	\
		sources/create_text_rect_vect.c	\
		sources/create_runner.c	\
		sources/startgame.c	\
		sources/create_music_score.c	\
		sources/destroy_obj.c	\
		sources/check_colli.c	\
		sources/create_menu.c	\
		sources/floor.c	\
		sources/draw_game.c	\
		sources/anim_sprite.c	\
		sources/endgame.c	\
		sources/obstacle.c	\
		sources/create_enemy.c	\
		sources/startlvl.c	\
		sources/draw_game_lvl.c	\
		sources/endlvl.c	\
		sources/event_game.c	\

SRC_TESTS	=	sources/project.c   \
			sources/create_parallax.c	\
			sources/create_text_rect_vect.c	\
			sources/startgame.c	\
			sources/create_runner.c	\
			sources/create_music_score.c	\
			sources/destroy_obj.c	\
			sources/anim_sprite.c	\
			sources/check_colli.c	\
			sources/create_menu.c	\
			sources/floor.c	\
			sources/draw_game.c	\
			sources/endgame.c	\
			sources/obstacle.c	\
			sources/sources/create_enemy.c	\
			sources/startlvl.c	\
			sources/draw_game_lvl.c	\
			sources/endlvl.c	\
			sources/event_game.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

LDFLAGS	=	-l csfml-graphics -l csfml-system -l csfml-window

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C libmy
	gcc $(OBJ) -L libmy/ -o $(NAME) -lmy $(LDFLAGS) -l csfml-audio

clean:
	rm -f sources/*.o
	rm -f sources/*~
	rm -f sources/*.gcda
	rm -f sources/*.gcno
	make clean -C libmy
	rm -f ./a.out

fclean:	clean
	rm -f $(NAME)
	make fclean -C libmy

re:	fclean all

tests_run:
	make -C libmy
	gcc $(SRC_TESTS) -L libmy -lmy ./tests/test.c --coverage -lcriterion
	./a.out

.PHONY : all clean fclean re tests_run
