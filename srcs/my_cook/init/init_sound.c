/*
** EPITECH PROJECT, 2018
** init_sound.c
** File description:
** init sound and music functions
*/
#include "cook.h"

void	init_sound(struct game *cook, int i, char *path)
{

	cook->sound_effect[i] = malloc(sizeof(*(cook->sound_effect[i])));
	cook->sound_effect[i]->buffer =
	sfSoundBuffer_createFromFile(path);
	cook->sound_effect[i]->sound = sfSound_create();
	sfSound_setBuffer(cook->sound_effect[i]->sound,
	cook->sound_effect[i]->buffer);
}

void	init_music(struct node **head, char *path)
{
	struct game_object	*obj;

	obj = create_music(path);
	obj->ptr_move =	&move_null;
	obj->ptr_display = &play_music;
	insert_end(head, obj);
}