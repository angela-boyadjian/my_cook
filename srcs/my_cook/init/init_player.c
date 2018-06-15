/*
** EPITECH PROJECT, 2018
** init_player.c
** File description:
** init player functions
*/
#include "cook.h"

void	init_player(struct game *cook)
{
	struct game_object	*obj;
	struct sprite		*img;

	obj = create_sprite("res/Player/player_2.png", CLIENT, 6,
	ret_int_rect(0, 110, 110, 160));
	img = (struct sprite *)obj->obj;
	sfSprite_setScale(img->sprite, ret_vec(2.5f, 2.5f));
	sfSprite_setPosition(img->sprite, ret_vec(250.0f, 100.0f));
	sfSprite_setTextureRect(img->sprite, img->rect[0]);
	img->speed = ret_vec(0.0f, 3.5f);
	obj->ptr_move = &move_client;
	obj->ptr_display = &display_sprite;
	cook->player = obj;
	cook->nb_client++;
	cook->client_num++;
}