/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:25:41 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/03/05 14:34:07 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "../ft_lem_in.h"

int	ft_error(int i)
{
	if (i == ERR_PARAMS)
		ft_dprintf(STDERR_FILENO, "Too many arguments given!\n");
	else if (i == ERR_ROOM_NAME)
		ft_dprintf(STDERR_FILENO, "Invalid roomname! Can't start with 'L'\n");
	else if (i == ERR_MEM)
		ft_dprintf(STDERR_FILENO, "Trouble allocating memory\n");
	else if (i == ERR_DOUBLE_COMMANDS)
		ft_dprintf(STDERR_FILENO, "Detected double commands, either \
##start or ##end is double.\n");
	else if (i == ERR_NO_PATHS)
		ft_dprintf(STDERR_FILENO, "No paths available!\n");
	else
		ft_dprintf(STDERR_FILENO, "Error number: %d\n", i);
	return (-1);
}
