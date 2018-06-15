/*
** EPITECH PROJECT, 2018
** check_keys_extra.c
** File description:
** functions for extras
*/
#include "cook.h"

int	key_h(struct game *cook)
{
	struct sprite	*img;
	sfVector2f pos;

	img = (struct sprite *)cook->ingredients[cook->count - 1]->obj;
	pos = sfSprite_getPosition(img->sprite);
	pos.x += 25;
	if (cook->current_screen == GAME) {
		cook->ingredients[cook->count] =
		init_ingredient("res/Ingredients/cherry.png",
		pos, H, ret_vec(0.1f, 0.1f));
		cook->count += 1;
		cook->check = true;
	}
	return (0);
}

int	key_tt(struct game *cook)
{
	struct sprite	*img;
	sfVector2f pos;

	img = (struct sprite *)cook->ingredients[cook->count - 1]->obj;
	pos = sfSprite_getPosition(img->sprite);
	pos.x += 10;
	if (cook->current_screen == GAME) {
		cook->ingredients[cook->count] =
		init_ingredient("res/Ingredients/sticks.png",
		pos, T, ret_vec(0.1f, 0.1f));
		cook->count += 1;
		cook->check = true;
	}
	return (0);
}