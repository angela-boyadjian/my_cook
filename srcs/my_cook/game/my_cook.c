/*
** EPITECH PROJECT, 2017
** my_cook.c
** File description:
** my cook game loop
*/
#include "cook.h"

static float	handle_time(sfClock *clock, float framerate)
{
	sfTime	time = sfClock_getElapsedTime(clock);
	return (time.microseconds / framerate);
}

void	handle_display(struct game *cook)
{

	display_order(cook);
	display_ingredient(cook);
	display_valid(cook);
	sfRenderWindow_display(cook->window);
	sfClock_restart(cook->clock);
}

void	display_head(struct node *head, struct game *cook)
{
	struct node		*tmp;
	struct game_object	*obj;
	int			i = 0;

	tmp = head;
	do {
		if (i == 1)
			display_player(cook);
		obj = (struct game_object *)tmp->data;
		obj->ptr_display(obj, cook);
		obj->ptr_move(obj, cook);
		generate_order(cook);
		if (end_game(cook, obj) == true)
			break;
		tmp = tmp->next;
		++i;
	} while (tmp != head);
}

int	my_cook(struct game *cook)
{
	struct node		*head;

	if (handle_event(cook) == 1)
		return (1);
	if (handle_time(cook->clock, 1000000.0f) > 0.05f) {
		head = (cook->screens)[cook->current_screen];
		display_head(head, cook);
		handle_display(cook);
	}
	return (0);
}