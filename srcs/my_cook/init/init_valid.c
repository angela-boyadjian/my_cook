/*
** EPITECH PROJECT, 2018
** init_valid.c
** File description:
** init valid functions
*/
#include "cook.h"

static struct game_object *create_valid(char *path, enum obj_type type)
{
	struct game_object	*obj = malloc(sizeof(*obj));
	struct sprite		*img = malloc(sizeof(*img));

	img->sprite = sfSprite_create();
	img->texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(img->sprite, img->texture, sfTrue);
	sfSprite_setScale(img->sprite, ret_vec(1.0f, 1.0f));
	sfSprite_setPosition(img->sprite, ret_vec(150.0f, 250.0f));
	obj->type = type;
	obj->obj = img;
	return (obj);
}

void	init_valid(struct game *cook)
{
	cook->valid[0] = create_valid("res/Player/ok.png", OK);
	cook->valid[1] = create_valid("res/Player/wrong.png", WRONG);
}