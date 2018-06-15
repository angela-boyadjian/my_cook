/*
** EPITECH PROJECT, 2018
** display_player.c
** File description:
** display the client
*/
#include "cook.h"

void	display_player(struct game *cook)
{
	struct game_object	*obj;

	if (cook->current_screen == GAME) {
			obj = (struct game_object *)cook->player;
			obj->ptr_display(obj, cook);
			obj->ptr_move(obj, cook);
		}
}