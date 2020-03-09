/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_lem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:09:54 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/09 15:57:45 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_free_char_arr(char **arr, int len)
{
	int i;

	i = 0;
	while (i < len && arr[i])
	{
		if (arr[i] != NULL)
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
		i += 1;
	return (i);
}

void		ft_free_room(t_room *room)
{
	unsigned int	i;

	i = 0;
	if (room == NULL)
		return ;
	if (room->name != NULL)
	{
		free(room->name);
		room->name = NULL;
	}
	if (room->edges != NULL)
	{
		free(room->edges);
		room->edges = NULL;
	}
	if (room->next != NULL)
		ft_free_room(room->next);
	free(room);
	room = NULL;
}

void		ft_free_lemin(t_lemin *list)
{
	unsigned int i;

	i = 0;
	if (list == NULL)
		return ;
	if (list->start != NULL)
	{
		free(list->start);
		list->start = NULL;
	}
	if (list->end != NULL)
	{
		free(list->end);
		list->end = NULL;
	}
	while (i < MAX_HASHTABLE)
	{
		if (list->room[i] != NULL)
		{
			ft_free_room(list->room[i]);
			list->room[i] = NULL;
		}
		i++;
	}
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}

void		ft_free_rstr(t_rstr *list)
{
	t_rstr *temp;

	if (!list)
		return ;
	while (list->next != NULL)
	{
		temp = list->next;
		if (list)
		{
			if (list->str)
			{
				free(list->str);
				list->str = NULL;
			}
			free(list);
			list = NULL;
		}
		list = temp;
	}
	if (list)
	{
		if (list->str)
		{
			free(list->str);
			list->str = NULL;
		}
		free(list);
		list = NULL;
	}
}
