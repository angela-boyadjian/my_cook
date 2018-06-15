/*
** EPITECH PROJECT, 2018
** display_ingredient.c
** File description:
** display functions
*/
#include "cook.h"

void	change_scale(struct sprite *img, int count)
{
	sfVector2f pos = sfSprite_getPosition(img->sprite);
	if (count > 1)
		pos.y -= count * 20;
	sfSprite_setPosition(img->sprite, pos);
}

void	display_ingredient(struct game *cook)
{
	struct sprite	*img;

	if (cook->current_screen == GAME) {
		for (int i = 0; i < cook->count
		&& cook->ingredients[i] != NULL; ++i) {
			img = (struct sprite *)cook->ingredients[i]->obj;
			sfRenderWindow_drawSprite(cook->window,
			img->sprite, NULL);
		}
	}
}

void	display_order(struct game *cook)
{
	struct sprite	*img;

	if (cook->current_screen == GAME
	&& check_client_stop(cook->player, cook->nb_client) == true) {
		for (int i = 0; i != cook->nb_of_scoop + 1; ++i) {
			img = (struct sprite *)cook->order[i]->obj;
			sfRenderWindow_drawSprite(cook->window,
			img->sprite, NULL);
		}
	}
}