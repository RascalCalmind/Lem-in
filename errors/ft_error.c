/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:25:41 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/04/20 16:47:15 by wmisiedjan    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "../ft_lem_in.h"

int		ft_free_error(t_lemin *lemin, t_rstr *file, int i)
{
	if (i == ERR_NO_ANTS)
		ft_dprintf(STDERR_FILENO, "No ants :(\n");
	else if (i == ERR_NO_START_END)
		ft_dprintf(STDERR_FILENO, "No start or endroom found\n");
	else if (i == ERR_CONN_INVALID)
		ft_dprintf(STDERR_FILENO, "Connections are invalid!\n");
	else if (i == ERR_ROOM_CORDS)
		ft_dprintf(STDERR_FILENO, "Error in coordinates of room\n");
	else if (i == ERR_START_END)
		ft_dprintf(STDERR_FILENO, "Error in format / saving start or end room\n");
	else if (i == ERR_PARSE_ROOM)
		ft_dprintf(STDERR_FILENO, "Error in parsing a room\n");
	else if (i == ERR_FILE)
		ft_dprintf(STDERR_FILENO, "Something wrong in file format\n");
	else if (i == ERR_NO_PATHS)
		ft_dprintf(STDERR_FILENO, "No paths available!\n");
	else
		ft_dprintf(STDERR_FILENO, "Whoops something went wrong, error: %d\n", i);
	ft_free_rstr(file);
	ft_free_lemin(lemin);
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
	else
		ft_dprintf(STDERR_FILENO, "Error number: %d\n", i);
	return (-1);
}
