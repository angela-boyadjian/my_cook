/*
** EPITECH PROJECT, 2017
** init_menu.c
** File description:
** init menu fuctions
*/
#include "cook.h"

struct game_object	*init_button(char *path, sfVector2f pos,
	enum obj_type type, sfVector2f scale)
{
	struct game_object	*obj;
	struct sprite		*img;

	obj = create_sprite(path, type, 3, ret_int_rect(0, 330, 330, 100));
	obj->button_type = NORMAL;
	img = (struct sprite *)obj->obj;
	sfSprite_setScale(img->sprite, scale);
	sfSprite_setPosition(img->sprite, pos);
	obj->ptr_move = &move_null;
	obj->ptr_display = &display_button;
	return (obj);
}

static struct game_object	*init_help_button(char *path, sfVector2f pos,
	enum obj_type type, sfVector2f scale)
{
	struct game_object	*obj;
	struct sprite		*img;

	obj = create_sprite(path, type, 3, ret_int_rect(0, 175, 175, 80));
	img = (struct sprite *)obj->obj;
	sfSprite_setScale(img->sprite, scale);
	sfSprite_setPosition(img->sprite, pos);
	obj->ptr_move = &move_null;
	obj->ptr_display = &display_button;
	return (obj);
}

void	init_menu_screen(struct game *cook)
{
	screen	**head = &((cook->screens)[MENU]);

	*head = NULL;
	init_music(head, "res/Music/menu.ogg");
	insert_end(head, init_background(ret_vec(0, 0),
	"res/Game_scene/menu.png", BACKGROUND));
	insert_end(head, init_button("res/Button/quit_game_button.png",
	ret_vec(610.0f, 137.0f), EXIT, ret_vec(1.0f, 1.0f)));
	insert_end(head, init_button("res/Button/play_game_button.png",
	ret_vec(510.0f, 137.0f), PLAY, ret_vec(1.0f, 1.0f)));
	insert_end(head, init_help_button("res/Button/htp_game_button.png",
	ret_vec(720.0f, 210.0f), HELP_BUTTON, ret_vec(1.0f, 1.0f)));
}