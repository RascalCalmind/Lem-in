/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:55:12 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/20 14:20:08 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_room_array_len(t_room **room)
{
	int i;

	i = 0;
	if (!room)
		return (0);
	while (room[i])
	{
		i += 1;
	}
	return (i);
}

void		ft_free_room(t_room *room)
{
	int i;
	int len;

	i = 0;
	if (!room)
		return ;
	if (room->name)
	{
		free(room->name);
		room->name = NULL;
	}
	len = ft_room_array_len(room->conn);
	while (i <= len)
	{
		ft_free_room(room->conn[i]);
		i += 1;
	}
	if (room)
	{
		free(room);
		room = NULL;
	}
}

void		ft_free_lemin(t_lemin *list)
{
	if (!list)
		return ;
	if (list->start)
	{
		free(list->start);
		list->start = NULL;
	}
	if (list->end)
	{
		free(list->end);
		list->end = NULL;
	}
	if (list->room != NULL)
	{
		ft_free_room(list->room);
		list->room = NULL;
	}
	if (list)
	{
		free(list);
		list = NULL;
	}
	return ;
}

int			ft_create_room(t_room *room)
{
	room = malloc(sizeof(t_room));
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	room->h = 0;
	room->conn = NULL;
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
