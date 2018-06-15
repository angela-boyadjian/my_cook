/*
** EPITECH PROJECT, 2018
** init_help_screen
** File description:
** init help screen
*/
#include "cook.h"

void	init_help_screen(struct game *cook)
{
	screen	**head = &((cook->screens)[HELP]);

	*head = NULL;
	insert_end(head, init_background(ret_vec(0, 0),
		"res/Game_scene/how_to_play.png", BACKGROUND));
	insert_end(head, init_button("res/Button/back_button.png",
	ret_vec(10.0f, 30.0f), BACK, ret_vec(0.8f, 0.8f)));
}