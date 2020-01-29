/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_lem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:09:54 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/29 18:27:08 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_free_char_arr(char **arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i += 1;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
	return (0);
}

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
	len = ft_room_array_len(room->links);
	while (i <= len)
	{
		ft_free_room(room->links[i]);
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
		ft_free_room(*list->room);
		list->room = NULL;
	}
	if (list)
	{
		free(list);
		list = NULL;
	}
	return ;
}

void	ft_free_rstr(t_rstr *list)
{
	t_rstr *temp;
	if (!list)
		return ;
	while (list->next != NULL)
	{
		temp = list->next;
		if (list->str)
		{
			free(list->str);
			list->str = NULL;
		}
		if (list->next)
		{
			free(list->next);
			list->next = NULL;
		}
		if (list)
		{
			free(list);
			list = NULL;
		}
	}
}