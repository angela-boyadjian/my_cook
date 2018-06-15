/*
** EPITECH PROJECT, 2017
** move.c
** File description:
** move functions
*/
#include "cook.h"

void	move_client(struct game_object *obj, struct game *cook)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfVector2f	pos = sfSprite_getPosition(img->sprite);

	(void)cook;
	if (pos.x < 450 - cook->nb_client - 20) {
		if (img->nb_anim > 1) {
			sfSprite_setTextureRect(img->sprite,
				img->rect[img->current_anim]);
			if (++(img->current_anim) == img->nb_anim)
				img->current_anim = 0;
		}
		sfSprite_move(img->sprite, img->speed);
	}
}

void	exit_client(struct game_object *obj, struct game *cook)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfVector2f	pos = sfSprite_getPosition(img->sprite);

	(void)cook;
	if (pos.x < 1100) {
		if (img->nb_anim > 1) {
			sfSprite_setTextureRect(img->sprite,
				img->rect[img->current_anim]);
			if (++(img->current_anim) == img->nb_anim)
				img->current_anim = 0;
		}
		sfSprite_move(img->sprite, img->speed);
	} else {
		init_player(cook);
		cook->nb_client--;
	}
}

void	move_anim(struct game_object *obj, struct game *cook)
{
	struct sprite	*img = (struct sprite *)obj->obj;

	(void)cook;
	if (img->nb_anim > 1) {
		sfSprite_setTextureRect(img->sprite,
			img->rect[img->current_anim]);
		if (++(img->current_anim) == img->nb_anim)
			img->current_anim = 0;
	}
}

void	move_background(struct game_object *obj, struct game *cook)
{
	struct sprite	*img = (struct sprite *)obj->obj;

	(void)cook;
	sfSprite_move(img->sprite, img->speed);
}

void	move_null(struct game_object *obj, struct game *cook)
{
	(void)obj;
	(void)cook;
}