/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:55:12 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/29 15:55:01 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_create_room(t_room *room)
{
	room = malloc(sizeof(t_room));
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	room->h = 0;
	room->links = NULL;
	room->next = NULL;
}

int			ft_create_lemin(t_lemin *list)
{
	char	*str;
	char	*end;
	t_room	*room;

	str = ft_strnew(0);
	if (str == NULL)
		return (-1);
	end = ft_strnew(0);
	if (end == NULL)
	{
		free(str);
		return (-1);
	}
	room = ft_create_room(room);
	if (!room)
	{
		free(str);
		free(end);
		return (-1);
	}
	list->start = str;
	list->end = end;
	list->room = room;
	list->ants = 0;
	return (0);
}
