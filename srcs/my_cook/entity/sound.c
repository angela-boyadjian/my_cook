/*
** EPITECH PROJECT, 2018
** sound.c
** File description:
** sound functions
*/
#include "cook.h"

void	play_music(struct game_object *obj, struct game *cook)
{
	struct music	*sound = (struct music *)obj->obj;

	(void)cook;
	if (sfMusic_getStatus(sound->music) == sfStopped)
		sfMusic_play(sound->music);
}

void	play_sound(struct game_object *obj, struct game *cook)
{
	struct sound	*sound = (struct sound *)obj->obj;

	(void)cook;
	sfSound_play(sound->sound);
}