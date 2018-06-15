/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error handling
*/
#include "cook.h"

int	errors(char **envp)
{
	if (envp[0] == NULL) {
		my_print_err(ERR_MSG_ENV);
		return (FAILURE);
	}
	return (SUCCESS);
}