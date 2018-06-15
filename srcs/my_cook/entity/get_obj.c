/*
** EPITECH PROJECT, 2017
** get_obj.c
** File description:
** get obj function
*/
#include "cook.h"

void	*get_obj(struct game *cook, enum obj_type type, enum screen_type screen)
{
	struct node *head = cook->screens[screen];
	struct node *tmp = head;
	struct game_object	*obj;

	do {
		obj = (struct game_object *)tmp->data;
		if (obj->type == type)
			return (obj->obj);
		tmp = tmp->next;
	} while (tmp != head);
	return (NULL);
}