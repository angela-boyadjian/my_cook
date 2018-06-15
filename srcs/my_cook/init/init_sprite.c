/*
** EPITECH PROJECT, 2017
** init_sprite.c
** File description:
** functions to init sprites
*/
#include "cook.h"

struct game_object *init_background(sfVector2f pos, char *path,
	enum obj_type type)
{
	struct game_object *obj;
	struct sprite	*img;

	obj = create_sprite(path, type, 0, ret_int_rect(0, 0, 0, 0));
	img = (struct sprite *)obj->obj;
	sfSprite_setPosition(img->sprite, pos);
	obj->ptr_move = &move_null;
	obj->ptr_display = &display_sprite;
	return (obj);
}