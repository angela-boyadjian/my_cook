/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** envent related functions
*/
#include "cook.h"

static int	manage_over(struct game *cook)
{
	struct node		*head = cook->screens[cook->current_screen];
	struct node		*tmp = head;
	struct game_object	*obj;

	do {
		obj = (struct game_object *)tmp->data;
		if (obj->type == PLAY || obj->type == EXIT || obj->type == SKIP
			|| obj->type == HELP_BUTTON
			|| obj->type == MENU_BUTTON || obj->type == BACK) {
			if (get_over(obj,
				sfMouse_getPositionRenderWindow(cook->window))
				== true)
				obj->button_type = OVER;
			else
				obj->button_type = NORMAL;
		}
		tmp = tmp->next;
	} while (tmp != head);
	return (0);
}

static int	manage_mouse(sfMouseButtonEvent event, struct game *cook)
{
	struct node		*head = cook->screens[cook->current_screen];
	struct node		*tmp = head;
	struct game_object	*obj;

	do {
		obj = (struct game_object *)tmp->data;
		if (event.button == sfMouseLeft) {
			if (check_play(cook, obj, event) == 1
			|| check_menu(cook, obj, event) == 1
			|| check_help(cook, obj, event) == 1
			|| check_back(cook, obj, event) == 1
			|| check_skip(cook, obj, event) == 1)
				return (0);
			if (check_exit(cook, obj, event) == -1)
				return (-1);
		}
		tmp = tmp->next;
	} while (tmp != head);
	return (0);
}

static void	add_ingredients(struct game *cook, sfEvent event)
{
	if (cook->count > 1 && cook->check == false) {
		check_event(cook, event, sfKeyH, &key_h);
		check_event(cook, event, sfKeyT, &key_tt);
	}
	if (cook->check == false) {
		check_event(cook, event, sfKeyS, &key_s);
		check_event(cook, event, sfKeyC, &key_c);
		check_event(cook, event, sfKeyV, &key_v);
		check_event(cook, event, sfKeyP, &key_p);
	}
}

int	analyse_event(struct game *cook, sfEvent event)
{
	if (event.type == sfEvtClosed) {
		sfRenderWindow_close(cook->window);
		return (1);
	}
	if (cook->count < MAX_ING) {
		if (cook->count > 0)
			add_ingredients(cook, event);
		if (cook->count == 0)
			check_event(cook, event, sfKeyO, &key_o);
	}
	check_event(cook, event, sfKeyReturn, &key_return);
	check_event(cook, event, sfKeySpace, &key_space);
	check_event(cook, event, sfKeyEscape, &key_escape);
	manage_over(cook);
	if (event.type == sfEvtMouseButtonPressed &&
	manage_mouse(event.mouseButton, cook) == -1)
		return (1);
	return (0);
}

int	handle_event(struct game *cook)
{
	sfEvent 	event;
	int		value;

	if (sfRenderWindow_pollEvent(cook->window, &event))
		value = analyse_event(cook, event);
	return (value);
}