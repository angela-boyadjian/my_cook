/*
** EPITECH PROJECT, 2018
** init_victory.c
** File description:
** init victory screen
*/
#include "cook.h"

void	init_victory_screen(struct game *cook)
{
	screen	**head = &((cook->screens)[VICTORY]);

	*head = NULL;
	insert_end(head, init_background(ret_vec(0, 0),
	"res/Game_scene/victory.png", BACKGROUND));
	insert_end(head, init_button("res/Button/quit_game_button.png",
		ret_vec(500.0f, 600.0f), EXIT, ret_vec(1.0f, 1.0f)));
	insert_end(head, init_button("res/Button/menu_button.png",
		ret_vec(500.0f, 200.0f), MENU_BUTTON, ret_vec(1.0f, 1.0f)));
}