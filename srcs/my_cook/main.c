/*
** EPITECH PROJECT, 2017
** src/main.c
** File description:
** src/main.c
*/
#include "cook.h"

int	main(int ac, char **av, char **envp)
{
	struct game	cook;

	(void)ac;
	(void)av;
	if (errors(envp) == FAILURE)
		return (FAILURE);
	init_game(&cook);
	while (sfRenderWindow_isOpen(cook.window))
		my_cook(&cook);
	clean_up(&cook);
	return (SUCCESS);
}