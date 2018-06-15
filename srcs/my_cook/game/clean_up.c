/*
** EPITECH PROJECT, 2017
** clean_up.c
** File description:
** clean up
*/
#include "cook.h"

static void	clean_up_music(struct game *cook)
{
	struct music *sound;

	for (int i = 0; i < SCREEN_SIZE; ++i) {
		cook->current_screen = i;
		if ((sound = get_obj(cook, MUSIC, cook->current_screen))
		!= NULL)
			sfMusic_destroy(sound->music);
	}
	sfSound_destroy(cook->sound_effect[0]->sound);
	sfSoundBuffer_destroy(cook->sound_effect[0]->buffer);
	sfSound_destroy(cook->sound_effect[1]->sound);
	sfSoundBuffer_destroy(cook->sound_effect[1]->buffer);
}

void	clean_up(struct game *cook)
{
	clean_up_music(cook);
}