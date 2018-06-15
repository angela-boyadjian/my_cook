/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** end game functions
*/
#include "cook.h"

static bool	check_victory(struct game *cook, struct game_object *obj)
{
	struct music		*sound = NULL;
	struct text		*score = (struct text *)(obj->obj);

	if (cook->current_screen == GAME) {
		if (score->points == 20) {
			sound = get_obj(cook, MUSIC, cook->current_screen);
			sfMusic_stop(sound->music);
			cook->current_screen = VICTORY;
			return (true);
		}
	}
	return (false);
}

static bool	check_defeat(struct game *cook, struct game_object *obj)
{
	struct music	*sound = NULL;
	struct text	*counter = (struct text *)(obj->obj);

	if (obj->type == COUNTER && cook->current_screen == GAME
	&& counter->counter == 0) {
		sound = get_obj(cook, MUSIC, cook->current_screen);
		sfMusic_stop(sound->music);
		cook->current_screen = DEFEAT;
		return (true);
	}
	return (false);
}

bool	end_game(struct game *cook, struct game_object *obj)
{
	if (check_victory(cook, obj) == true)
		return (true);
	else if (check_defeat(cook, obj) == true)
		return (true);
	return (false);
}