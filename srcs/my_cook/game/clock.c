/*
** EPITECH PROJECT, 2018
** clock.c
** File description:
** clock functions
*/
#include "cook.h"

void	decrement_counter(struct game_object *obj, struct game *cook)
{
	struct text	*score = (struct text *)(obj->obj);
	static int		loop = 0;

	if (loop >= 20 && cook->current_screen == GAME) {
		score->counter -= 1;
		loop = 0;
	}
	++loop;
	sfText_setString(score->text, my_itoa(score->counter));
}

void	init_clock(struct node **head)
{
	struct game_object	*obj;
	struct text		*score;

	obj = create_text("res/Font/font.ttf", ret_vec(10, 200), 35, 2);
	score = (struct text *)obj->obj;
	score->counter = 60;
	sfText_setString(score->text, my_itoa(score->counter));
	obj->type = COUNTER;
	obj->ptr_move = &decrement_counter;
	obj->ptr_display = &display_text;
	insert_end(head, obj);
}