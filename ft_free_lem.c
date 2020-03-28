/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_lem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:09:54 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/28 20:06:51 by Lotte         ########   odam.nl         */
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

void		ft_free_edges(t_room *room)
{
	int i;

	i = 0;
	if (room->edges != NULL)
	{
		while (room->edges[i] != NULL)
		{
			free(room->edges[i]);
			room->edges[i] = NULL;
			i += 1;
		}
		free(room->edges);
		room->edges = NULL;
	}
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
		ft_free_edges(room);
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
		free(list->start);
	if (list->end != NULL)
		free(list->end);
	while (i < MAX_HASHTABLE)
	{
		if (list->room[i] != NULL)
			ft_free_room(list->room[i]);
		i++;
	}
	if (list->paths)
		ft_free_paths(list);
	if (list->iter)
		free(list->iter);
	free(list);
}

void		ft_free_rstr(t_rstr *list)
{
	t_rstr *temp;

	if (!list)
		return ;
	while (list->next != NULL)
	{
		temp = list->next;
		if (list && list->str)
		{
			free(list->str);
			list->str = NULL;
		}
		free(list);
		list = temp;
	}
	if (list && list->str)
	{
		free(list->str);
		list->str = NULL;
	}
	free(list);
	list = NULL;
}
