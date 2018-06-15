/*
** EPITECH PROJECT, 2018
** check_event.c
** File description:
** chechk events functions
*/
#include "cook.h"

int	check_event(struct game *cook, sfEvent event, sfKeyCode key,
	int (*ptr)(struct game *))
{
	if (event.type == sfEvtKeyPressed && event.key.code == key) {
		ptr(cook);
		return (1);
	}
	return (0);
}

int	key_escape(struct game *cook)
{
	if (cook->current_screen == GAME) {
		cook->previous_screen = GAME;
		cook->current_screen = PAUSE;
	} else if (cook->current_screen == PAUSE) {
		cook->previous_screen = PAUSE;
		cook->current_screen = GAME;
	}
	return (0);
}

int	key_return(struct game *cook)
{
	if (cook->current_screen == GAME) {
		if (compare_order(cook) == true) {
			cook->send_order = true;
			cook->score = true;
		} else {
			cook->send_order = true;
			cook->score = false;
		}
		cook->count = 0;
		cook->check = false;
	}
	return (0);
}

int	key_space(struct game *cook)
{
	if (cook->current_screen == GAME) {
		cook->count = 0;
		cook->check = false;
	}
	return (0);
}