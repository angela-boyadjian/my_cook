/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** free functions
*/
#include "cook.h"

void	free_tab(struct game *cook)
{
	struct sprite	*img;

	for (int i = 0; i < MAX_ING; ++i) {
		if (cook->ingredients[i] == NULL)
			break;
		img = (struct sprite *)cook->ingredients[i]->obj;
		free(img);
		free(cook->ingredients[i]);
		cook->ingredients[i] = NULL;
	}
	for (int i = 0; i < MAX_ING; ++i) {
		if (cook->order[i] == NULL)
			break;
		img = (struct sprite *)cook->order[i]->obj;
		free(img);
		free(cook->order[i]);
		cook->order[i] = NULL;
	}
}

void	free_ing(struct game *cook)
{
	struct sprite	*img;

	for (int i = 0; i < MAX_ING; ++i) {
		if (cook->ingredients[i] == NULL)
			break;
		img = (struct sprite *)cook->ingredients[i]->obj;
		free(img);
		free(cook->ingredients[i]);
		cook->ingredients[i] = NULL;
	}
}