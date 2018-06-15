/*
** EPITECH PROJECT, 2018
** client.c
** File description:
** client functions
*/
#include "cook.h"

bool	check_client_stop(struct game_object *obj, int nb_client)
{
	struct sprite	*img = (struct sprite *)obj->obj;
	sfVector2f	pos = sfSprite_getPosition(img->sprite);

	if (obj->type == CLIENT && pos.x == 450 - nb_client - 20)
		return (true);
	return (false);
}

bool	compare_order(struct game *cook)
{
	for (int i = 0; i <= cook->nb_of_scoop; ++i) {
		if (i == 0 && cook->ingredients[i] == NULL
		&& cook->order[i] == NULL)
			return (false);
		if (cook->ingredients[i] == NULL || cook->order[i] == NULL)
			return (false);
		if (cook->order[i]->letter != cook->ingredients[i]->letter)
			return (false);
	}
	return (true);
}

int	generate_scoop(struct game *cook, int min, int max, int dont_take[5])
{
	int nb = generate_nbr(cook, min, max);
	int i = 0;

	while (i != 5) {
		if (nb == dont_take[i]) {
			nb = generate_nbr(cook, min, max);
			i = 0;
		} else
			i++;
	}
	return (nb);
}

void	generate_glace(struct game *cook, int nb_of_scoop, int nb_of_extra)
{
	int scoop;
	int ex_scoop[5] = { 0, 0, 0, 0, 0 };
	struct sprite *sprite;
	int i;

	for (i = 1; i != nb_of_scoop + 1; ++i) {
		scoop = generate_scoop(cook, 1, 4, ex_scoop);
		cook->order[i] = cook->all_ing[scoop];
		ex_scoop[i - 1] = scoop;
		sprite = (struct sprite *)cook->order[i]->obj;
		sfSprite_setPosition(sprite->sprite,
		ret_vec(300.0f - (i - 1) * 20.0f, 665));
	}
	if (nb_of_extra == 1) {
		cook->order[i] = cook->all_ing[generate_nbr(cook, 5, 6)];
		sprite = (struct sprite *)cook->order[i]->obj;
		sfSprite_setPosition(sprite->sprite,
		ret_vec(300.0f - (i - 1) * 20.0f, 665));
	}
}

void	generate_order(struct game *cook)
{
	int nb_of_scoop = generate_nbr(cook, 1, 3);
	int nb_of_extra = generate_nbr(cook, 0, 1);
	static int nb_client = 0;

	if (check_client_stop(cook->player, cook->nb_client) == true
	&& nb_client < cook->client_num) {
		cook->order[0] = cook->all_ing[0];
		cook->nb_of_scoop = nb_of_scoop + nb_of_extra;
		generate_glace(cook, nb_of_scoop, nb_of_extra);
		nb_client = cook->client_num;
	}
}