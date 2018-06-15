/*
** EPITECH PROJECT, 2018
** display_valid.c
** File description:
** display valid function
*/
#include "cook.h"

bool	get_timer(float *time_elapsed, float timer_duration, struct game *cook)
{
	if (*time_elapsed < timer_duration)
		*time_elapsed += (sfClock_getElapsedTime(cook->clock))
		.microseconds;
	if (*time_elapsed >= timer_duration) {
		*time_elapsed = 0;
		return (true);
	}
	return (false);
}

static void	success_display(struct game *cook, float *time_elapsed)
{
	struct sprite	*img;

	if (*time_elapsed == 0.0f)
		sfSound_play(cook->sound_effect[0]->sound);
	if (get_timer(time_elapsed, 1000000.0f, cook)
	== true) {
		cook->score = false;
	}
	img = (struct sprite *)cook->valid[0]->obj;
	sfRenderWindow_drawSprite(cook->window, img->sprite,
	NULL);
}

static void	failure_display(struct game *cook, float *time_elapsed)
{
	struct sprite	*img;

	if (*time_elapsed == 0.0f)
		sfSound_play(cook->sound_effect[1]->sound);
	if (get_timer(time_elapsed, 1000000.0f, cook) == true)
		cook->send_order = false;
	img = (struct sprite *)cook->valid[1]->obj;
	sfRenderWindow_drawSprite(cook->window, img->sprite,
	NULL);
}

void	display_valid(struct game *cook)
{
	static float time_elapsed = 0.0f;

	if (cook->current_screen == GAME) {
		if (cook->score == true) {
			success_display(cook, &time_elapsed);
		}
		else if (cook->score == false && cook->send_order == true) {
			failure_display(cook, &time_elapsed);
		} else {
			return;
		}
	}
}