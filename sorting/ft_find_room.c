/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_room.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:19:42 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/27 18:49:41 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

void	*ft_room_map_v(t_lemin *lemin, void (*func)(t_room *, t_path **paths, int cpath))
{
	int		i;
	int 	j;
	t_room 	*temp;

	i = 0;
	j = 0;
	temp = NULL;
	while (lemin->room && i < MAX_HASHTABLE)
	{
		if (lemin->room[i] != NULL)
		{
			temp = lemin->room[i];
			while (lemin->room[i] != NULL)
			{
				func(lemin->room[i], lemin->paths, lemin->path_count);
				lemin->room[i] = lemin->room[i]->next;
			}
			lemin->room[i] = temp;
		}
		i += 1;
	}
}

void	*ft_room_map(t_lemin *lemin, void (*func)(t_room *))
{
	int		i;
	int 	j;
	t_room 	*temp;

	i = 0;
	j = 0;
	temp = NULL;
	while (lemin->room && i < MAX_HASHTABLE)
	{
		if (lemin->room[i] != NULL)
		{
			temp = lemin->room[i];
			while (lemin->room[i] != NULL)
			{
				func(lemin->room[i]);
				lemin->room[i] = lemin->room[i]->next;
			}
			lemin->room[i] = temp;
		}
		i += 1;
	}
}

t_room		*ft_find_room(t_lemin *list, char *name)
{
	t_room	*p;
	t_room	*temp;
	int		index;

	index = ft_hash_sdbm(name, MAX_HASHTABLE);
	if (list->room[index] != NULL)
	{
		temp = list->room[index];
		while (list->room[index] != NULL &&
				ft_strcmp(list->room[index]->name, name) != 0 &&
				list->room[index]->next)
			list->room[index] = list->room[index]->next;
		if (list->room[index] && ft_strcmp(list->room[index]->name, name) == 0)
		{
			p = list->room[index];
			list->room[index] = temp;
			return (p);
		}
		else
			list->room[index] = temp;
	}
	return (NULL);
}
