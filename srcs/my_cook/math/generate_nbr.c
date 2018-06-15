/*
** EPITECH PROJECT, 2018
** generate_nbr.c
** File description:
** generate random nbr
*/
#include "cook.h"

int generate_nbr(struct game *cook, int min, int max)
{
	sfTime time = sfClock_getElapsedTime(cook->clock);

	srand(time.microseconds);
	return (rand() % (max + 1 - min) + min);
}