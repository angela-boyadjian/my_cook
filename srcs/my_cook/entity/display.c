/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** display.c
*/
#include "cook.h"

void	display_button(struct game_object *obj, struct game *cook)
{
	struct sprite	*img = (struct sprite *)obj->obj;

	if (obj->button_type == OVER) {
		sfSprite_setTextureRect(img->sprite,
		img->rect[1]);
		sfRenderWindow_drawSprite(cook->window, img->sprite, NULL);
	} else if (obj->button_type == CLICK) {
		sfSprite_setTextureRect(img->sprite,
		img->rect[2]);
		sfRenderWindow_drawSprite(cook->window, img->sprite, NULL);
	} else {
		sfSprite_setTextureRect(img->sprite,
		img->rect[0]);
		sfRenderWindow_drawSprite(cook->window, img->sprite, NULL);
	}
}

void	display_sprite(struct game_object *obj, struct game *cook)
{
	struct sprite	*img = (struct sprite *)obj->obj;

	sfRenderWindow_drawSprite(cook->window, img->sprite, NULL);
}

void	display_text(struct game_object *obj, struct game *cook)
{
	struct text	*score = (struct text *)obj->obj;

	sfRenderWindow_drawText(cook->window, score->text, NULL);
}

void	display_intro(struct game_object *obj, struct game *cook)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfVector2f	pos = sfSprite_getPosition(img->sprite);
	struct music	*sound;

	if (pos.y < -950.0f) {
		sound = get_obj(cook, MUSIC, cook->current_screen);
		sfMusic_stop(sound->music);
		cook->current_screen = MENU;
	}
	sfRenderWindow_drawSprite(cook->window, img->sprite, NULL);
}