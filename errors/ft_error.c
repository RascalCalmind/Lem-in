/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:25:41 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/03/11 17:22:38 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "../ft_lem_in.h"

int		ft_free_error_lem_rstr(t_lemin *list, t_rstr *file, int i)
{
	if (i == 1)
		ft_dprintf(STDERR_FILENO, "No ants :(\n");
	if (i == 2)
		ft_dprintf(STDERR_FILENO, "No ants or connections are invalid!\n");
	if (i == 3)
		ft_dprintf(STDERR_FILENO, "Error in coordinates of room\n");
	if (i == 4)
		ft_dprintf(STDERR_FILENO, "Error in saving start or end room\n");
	ft_free_rstr(file);
	ft_free_lemin(list);
	return (-1);
}

int	ft_error(int i)
{
	if (i == ERR_PARAMS)
		ft_dprintf(STDERR_FILENO, "Too many arguments given!\n");
	else if (i == ERR_FILE)
		ft_dprintf(STDERR_FILENO, "Error reading file, might be empty.\n");
	else if (i == ERR_INVALID_ROOM_COUNT)
		ft_dprintf(STDERR_FILENO, "Not enough rooms\n");
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
