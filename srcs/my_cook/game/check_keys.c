/*
** EPITECH PROJECT, 2018
** check_keys.c
** File description:
** functions to check keys pressed
*/
#include "cook.h"

int	key_o(struct game *cook)
{
	if (cook->current_screen == GAME) {
		cook->ingredients[cook->count] =
		init_ingredient("res/Ingredients/cone.png",
		ret_vec(650.0f, 500.0f), KEY_O, ret_vec(0.3f, 0.3f));
		cook->count += 1;
	}
	return (0);
}

int	key_s(struct game *cook)
{
	if (cook->current_screen == GAME) {
		cook->ingredients[cook->count] =
		init_ingredient("res/Ingredients/Strawberry.png",
		ret_vec(630.0f - (cook->count - 1) * 20.0f, 515.0f),
		S, ret_vec(0.25f, 0.25f));
		cook->count += 1;
	}
	return (0);
}

int	key_c(struct game *cook)
{
	if (cook->current_screen == GAME) {
		cook->ingredients[cook->count] =
		init_ingredient("res/Ingredients/Chocolate.png",
		ret_vec(630.0f - (cook->count - 1) * 20.0f, 515.0f),
		C, ret_vec(0.25f, 0.25f));
		cook->count += 1;
	}
	return (0);
}

int	key_v(struct game *cook)
{
	if (cook->current_screen == GAME) {
		cook->ingredients[cook->count] =
		init_ingredient("res/Ingredients/Vanilla.png",
		ret_vec(630.0f - (cook->count - 1) * 20.0f, 515.0f),
		V, ret_vec(0.25f, 0.25f));
		cook->count += 1;
	}
	return (0);
}

int	key_p(struct game *cook)
{
	if (cook->current_screen == GAME) {
		cook->ingredients[cook->count] =
		init_ingredient("res/Ingredients/Pistachio.png",
		ret_vec(630.0f - (cook->count - 1) * 20.0f, 515.0f),
		P, ret_vec(0.25f, 0.25f));
		cook->count += 1;
	}
	return (0);
}