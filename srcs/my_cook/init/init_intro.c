/*
** EPITECH PROJECT, 2018
** init_intro.c
** File description:
** init intro functions
*/
#include "cook.h"

static void	init_background_intro(struct node **head)
{
	struct game_object	*obj;
	struct sprite		*img;

	obj = create_sprite("res/Game_scene/intro_background.png",
	BACKGROUND, 0, ret_int_rect(0, 0, 0, 0));
	img = (struct sprite *)obj->obj;
	img->speed.x = 0.0f;
	img->speed.y = -2.0f;
	obj->ptr_move = &move_background;
	obj->ptr_display = &display_intro;
	insert_end(head, obj);
	insert_end(head, init_button("res/Button/skip_button.png",
	ret_vec(0.5f, 0.5f), SKIP, ret_vec(0.6f, 0.6f)));
}

void	init_intro_screen(struct game *cook)
{
	screen	**head = &((cook->screens)[INTRO]);

	*head = NULL;

	init_music(head, "res/Music/intro.ogg");
	init_background_intro(head);
}