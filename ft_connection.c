/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_connection.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:00:40 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/11 17:38:31 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_in_lemin(char *str, t_lemin *list)
{
	int		index;
	t_room	*temp;

	index = 0;
	if (!str || !list)
		return (-1);
	index = ft_hash_sdbm(str, MAX_HASHTABLE);
	temp = list->room[index];
	while (list->room[index])
	{
		if (ft_strcmp(list->room[index]->name, str) == 0)
		{
			list->room[index] = temp;
			return (0);
		}
		list->room[index] = list->room[index]->next;
	}
	list->room[index] = temp;
	return (-1);
}

t_room	*ft_pointer_room(char *str, int index, t_lemin *list)
{
	t_room *temp;
	t_room *pointer;

	temp = list->room[index];
	while (list->room[index])
	{
		if (ft_strcmp(list->room[index]->name, str) == 0)
		{
			pointer = list->room[index];
			list->room[index] = temp;
			return (pointer);
		}
		list->room[index] = list->room[index]->next;
	}
	list->room[index] = temp;
	return (NULL);
}

t_edge	*create_edge(t_room *to, int available)
{
	t_edge *edge;
	edge = (t_edge *)ft_memalloc(sizeof(t_edge));
	edge->to = to;
	edge->available = available;
	return (edge);
}

/**
 * returns index of edge added in room
 */

int	add_edge(t_room *room, t_room *to, t_lemin *lemin)
{
	int i;

	i = 0;
	if (room->edges == NULL)
	{
		room->edges = (t_edge **)\
		ft_memalloc(sizeof(t_edge *) * (lemin->rooms + 1));
	}

	while (room->edges[i] != NULL)
		i++;
	room->edges[i] = create_edge(to, 1);
	room->link_count++;
	return (i);
}

int		ft_assign_connection(char **arr, t_lemin *list)
{
	t_room	*from;
	t_room	*to;
	int		from_index;
	int		to_index;

	from_index = ft_hash_sdbm(arr[0], MAX_HASHTABLE);
	to_index = ft_hash_sdbm(arr[1], MAX_HASHTABLE);
	from = ft_pointer_room(arr[0], from_index, list);
	to = ft_pointer_room(arr[1], to_index, list);

	// TODO: Double check if this makes sense
	from_index = add_edge(from, to, list);
	to_index = add_edge(to, from, list);
	from->edges[from_index]->rev = to->link_count;
	to->edges[to_index]->rev = from->link_count - 1;
	return (0);
}

int		ft_connection(char *str, t_lemin *list)
{
	char	**arr;

	if (!str)
		return (-1);
	if (ft_contains(str, '-') != 1)
		return (-1);
	arr = ft_strsplit(str, '-');
	if (!arr)
		return (-1);
	if (ft_in_lemin(arr[0], list) < 0 || ft_in_lemin(arr[1], list) < 0)
	{
		ft_free_char_arr(arr, 2);
		return (-1);
	}
	else if (ft_assign_connection(arr, list) == 0)
	{
		ft_free_char_arr(arr, 2);
		return (0);
	}
	else
	{
		ft_free_char_arr(arr, 2);
		return (-1);
	}
}
