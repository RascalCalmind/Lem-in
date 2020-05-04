/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_lem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:09:54 by lhageman      #+#    #+#                 */
/*   Updated: 2020/05/04 16:03:44 by wmisiedjan    ########   odam.nl         */
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

void		ft_free_lemin(t_lemin *lemin)
{
	unsigned int i;

	i = 0;
	if (lemin == NULL)
		return ;
	if (lemin->start != NULL)
		free(lemin->start);
	if (lemin->end != NULL)
		free(lemin->end);
	while (i < MAX_HASHTABLE)
	{
		if (lemin->room[i] != NULL)
			ft_free_room(lemin->room[i]);
		i++;
	}
	if (lemin->paths)
		ft_free_paths(lemin);
	if (lemin->iter)
		free(lemin->iter);
	free(lemin);
}

void		ft_free_rstr(t_rstr *lemin)
{
	t_rstr *temp;

	if (!lemin)
		return ;
	while (lemin->next != NULL)
	{
		temp = lemin->next;
		if (lemin && lemin->str)
		{
			free(lemin->str);
			lemin->str = NULL;
		}
		free(lemin);
		lemin = temp;
	}
	if (lemin && lemin->str)
	{
		free(lemin->str);
		lemin->str = NULL;
	}
	free(lemin);
	lemin = NULL;
}
