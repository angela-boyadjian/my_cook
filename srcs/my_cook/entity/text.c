/*
** EPITECH PROJECT, 2017
** text.c
** File description:
** functions for text
*/
#include "cook.h"

char	*add_space(char *str)
{
	char	*save = malloc(sizeof(*save) * (my_strlen(str) * 3) - 1);
	int	i = 0;

	if (my_strcmp(str, "090") == 0)
		return ("9 0");
	my_strcpy(save, str);
	for (i = 0; str[i]; ++i) {
		if (i % 2 != 0) {
			save[i] = ' ';
			save[i + 1] = str[i + 1];
		}
	}
	if ((my_strlen(str) % 2 != 0 && my_strlen(str) != 1)
	|| my_strlen(str) == 2)
		save[i] = str[i - 1];
	save[i + 1] = 0;
	return (save);
}

void	set_color(struct text *score, int color)
{
	if (color == 1)
		sfText_setColor(score->text, sfWhite);
	else if (color == 2)
		sfText_setColor(score->text, sfBlue);
	else
		sfText_setColor(score->text, sfBlack);
}

struct	game_object *init_text(sfVector2f pos, int size, int color, char *text)
{
	struct game_object	*obj;
	struct text		*score;

	obj = create_text("res/Font/font.ttf", pos, size, color);
	score = (struct text *)obj->obj;
	sfText_setString(score->text, text);
	obj->type = TEXT;
	obj->ptr_move = &move_null;
	obj->ptr_display = &display_text;
	return (obj);
}

void	init_target(struct node **head, int target)
{
	struct game_object	*obj;
	struct text		*score;
	char			*str = my_itoa(target);

	obj = create_text("res/Font/font.ttf", ret_vec(530, 310), 45, 1);
	score = (struct text *)obj->obj;
	sfText_setString(score->text, add_space(str));
	obj->type = SCORE;
	obj->ptr_move = &move_null;
	obj->ptr_display = &display_text;
	insert_end(head, obj);
}

void	init_points(struct node **head)
{
	struct game_object	*obj;
	struct text		*score;
	char			*str;

	obj = create_text("res/Font/font.ttf", ret_vec(540, 500), 45, 1);
	score = (struct text *)obj->obj;
	str = my_itoa(score->points);
	sfText_setOrigin(score->text, ret_vec(10, -10));
	sfText_setString(score->text, add_space(str));
	obj->type = SCORE;
	obj->ptr_move = &increment_score;
	obj->ptr_display = &display_text;
	insert_end(head, obj);
}