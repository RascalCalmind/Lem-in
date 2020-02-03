/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:55:12 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/03 13:38:03 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_create_room(t_room *room)
{
	if (!room)
		return (-1);
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	room->h = 0;
	room->links = NULL;
	room->next = NULL;
	return (0);
}

int			ft_create_lemin(t_lemin *list, int rooms)
{
	char	*str;
	char	*end;
	// int		ret;
	t_room	**room;
	int i;

	i = 0;
	str = ft_strnew(0);
	if (str == NULL)
		return (-1);
	end = ft_strnew(0);
	if (end == NULL)
	{
		free(str);
		return (-1);
	}
	room = malloc(sizeof(t_room **) * rooms);
	if (!room)
		return (-1);
	while (i < rooms)
	{
		room[i] = NULL;
		i += 1;
	}
	//room = malloc(sizeof(t_room));
	// if (!room)
	// 	return (-1);
	//ret = ft_create_room(room);
	// if (!room || ret == -1)
	// {
	// 	free(str);
	// 	free(end);
	// 	return (-1);
	// }
	list->start = str;
	list->end = end;
	list->room = room;
	list->ants = 0;
	list->rooms = rooms;
	ft_printf("end:[%s]\tstart:[%s]\n---\n", list->end, list->start);
	return (0);
}
