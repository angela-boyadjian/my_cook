/*
** EPITECH PROJECT, 2018
** score.c
** File description:
** score functions
*/
#include "cook.h"

static void	handle_change(struct text *score, sfVector2f pos)
{
	static int	count = 0;

	if (score->points == 10 && count == 0) {
		if (count == 0)
			++count;
		pos.x -= 40;
		sfText_setPosition(score->text, pos);
	}
	if (score->points == 100 && count == 1) {
		if (count == 1)
			++count;
		pos.x -= 25;
		sfText_setPosition(score->text, pos);
	}
}

void	increment_score(struct game_object *obj, struct game *cook)
{
	struct text	*score = (struct text *)(obj->obj);
	char		*str = my_itoa(score->points);
	sfVector2f	pos = sfText_getPosition(score->text);

	if (cook->send_order == true
	&& check_client_stop(cook->player, cook->nb_client) == true) {
		if (cook->score == true)
			score->points += 10;
		else
			score->points -= 10;
		if (score->points < 0)
			score->points = 0;
		cook->send_order = false;
		cook->player->ptr_move = &exit_client;
	}
	handle_change(score, pos);
	sfText_setString(score->text, add_space(str));
}