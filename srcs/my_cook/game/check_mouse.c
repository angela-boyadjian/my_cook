/*
** EPITECH PROJECT, 2018
** check_mouse.c
** File description:
** check mouse functions
*/
#include "cook.h"

int	check_play(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event)
{
	struct music	*sound = NULL;

	if (obj->type == PLAY && get_click(obj, event.x, event.y) == true) {
		sound = get_obj(cook, MUSIC, cook->current_screen);
		sfMusic_stop(sound->music);
		obj->button_type = CLICK;
		cook->previous_screen = cook->current_screen;
		cook->pause = true;
		cook->current_screen = GAME;
		return (1);
	}
	return (0);
}

int	check_menu(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event)
{
	struct music	*sound = NULL;

	if (obj->type == MENU_BUTTON && get_click(obj, event.x, event.y)
	== true) {
		sound = get_obj(cook, MUSIC, cook->previous_screen);
		sfMusic_stop(sound->music);
		cook->previous_screen = cook->current_screen;
		obj->button_type = CLICK;
		cook->current_screen = MENU;
		return (1);
	}
	return (0);
}

int	check_exit(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event)
{
	if (obj->type == EXIT && get_click(obj, event.x, event.y) == true) {
		obj->button_type = CLICK;
		cook->previous_screen = cook->current_screen;
		cook->pause = true;
		sfRenderWindow_close(cook->window);
		return (-1);
	}
	return (0);
}

int	check_help(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event)
{
	if (obj->type == HELP_BUTTON && get_click(obj, event.x, event.y)
		== true) {
		obj->button_type = CLICK;
		cook->previous_screen = cook->current_screen;
		cook->pause = true;
		cook->current_screen = HELP;
		return (1);
	}
	return (0);
}

int	check_skip(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event)
{
	struct music	*sound = NULL;

	if (obj->type == SKIP && get_click(obj, event.x, event.y) == true) {
		obj->button_type = CLICK;
		cook->previous_screen = cook->current_screen;
		cook->pause = true;
		sound = get_obj(cook, MUSIC, cook->current_screen);
		sfMusic_stop(sound->music);
		cook->current_screen = MENU;
		return (1);
	}
	return (0);
}

int	check_back(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event)
{
	if (obj->type == BACK && get_click(obj, event.x, event.y) == true) {
		obj->button_type = CLICK;
		cook->previous_screen = cook->current_screen;
		cook->pause = true;
		cook->previous_screen = cook->current_screen;
		cook->current_screen = MENU;
		return (1);
	}
	return (0);
}