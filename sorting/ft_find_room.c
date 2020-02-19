/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_room.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:19:42 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/19 14:35:42 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

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
