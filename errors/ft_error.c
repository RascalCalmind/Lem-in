/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:25:41 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/01/29 18:56:45 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "../ft_lem_in.h"

int	ft_error(int i)
{
	if (i == ERR_PARAMS)
		ft_dprintf(STDERR_FILENO, "Too many arguments given!\n");
	if (i == ERR_ROOM_NAME)
		ft_dprintf(STDERR_FILENO, "Invalid roomname! Can't start with 'L'\n");
	if (i == ERR_MEM)
		ft_dprintf(STDERR_FILENO, "Trouble allocating memory\n");
	ft_dprintf(STDERR_FILENO, "Error\n");
	return (-1);
}
