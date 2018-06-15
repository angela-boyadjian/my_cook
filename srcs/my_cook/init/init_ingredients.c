/*
** EPITECH PROJECT, 2018
** init_ingredients.c
** File description:
** functions to init ingredients list
*/
#include "cook.h"

static struct game_object	*create_ingredients(char const *path,
	enum letter letter)
{
	struct sprite		*obj = malloc(sizeof(*obj));
	struct game_object	*ret = malloc(sizeof(*ret));

	obj->sprite = sfSprite_create();
	ret->letter = letter;
	obj->texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
	ret->obj = obj;
	return (ret);
}

struct game_object	*init_ingredient(char *path, sfVector2f pos,
	enum letter letter, sfVector2f scale)
{
	struct game_object	*obj;
	struct sprite		*img;

	obj = create_ingredients(path, letter);
	img = (struct sprite *)obj->obj;
	sfSprite_setScale(img->sprite, scale);
	sfSprite_setPosition(img->sprite, pos);
	return (obj);
}

void	init_all_ing(struct game *cook)
{
		cook->all_ing[0] = init_ingredient("res/Ingredients/cone.png",
		ret_vec(300.0f, 650.0f), KEY_O, ret_vec(0.2f, 0.2f));
		cook->all_ing[1] = init_ingredient(
		"res/Ingredients/Chocolate.png",
		ret_vec(300.0f, 665.0f), C, ret_vec(0.15f, 0.15f));
		cook->all_ing[2] = init_ingredient(
		"res/Ingredients/Vanilla.png",
		ret_vec(300.0f, 665.0f), V, ret_vec(0.15f, 0.15f));
		cook->all_ing[3] = init_ingredient(
		"res/Ingredients/Strawberry.png",
		ret_vec(300.0f , 665.0f), S, ret_vec(0.15f, 0.15f));
		cook->all_ing[4] = init_ingredient(
		"res/Ingredients/Pistachio.png",
		ret_vec(300.0f, 665.0f), P, ret_vec(0.15f, 0.15f));
		cook->all_ing[5] = init_ingredient(
		"res/Ingredients/sticks.png",
		ret_vec(300.0f, 665.0f), T, ret_vec(0.1f, 0.1f));
		cook->all_ing[6] = init_ingredient(
		"res/Ingredients/cherry.png",
		ret_vec(300.0f, 665.0f), H, ret_vec(0.1f, 0.1f));
}