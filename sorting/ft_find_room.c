/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_room.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:19:42 by lhageman      #+#    #+#                 */
/*   Updated: 2020/04/20 17:23:13 by wmisiedjan    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

void		ft_room_map_v(t_lemin *lemin, void (*func)\
			(t_room *, t_path **paths, int cpath))
{
	int		i;
	int		j;
	t_room	*temp;

	i = 0;
	j = 0;
	temp = NULL;
	while (i < MAX_HASHTABLE)
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

void		ft_room_map(t_lemin *lemin, void (*func)(t_room *))
{
	int		i;
	int		j;
	t_room	*temp;

	i = 0;
	j = 0;
	temp = NULL;
	while (i < MAX_HASHTABLE)
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

t_room		*ft_find_room(t_lemin *lemin, char *name)
{
	t_room	*p;
	t_room	*temp;
	int		index;

	index = ft_hash_sdbm(name, MAX_HASHTABLE);
	if (lemin->room[index] != NULL)
	{
		temp = lemin->room[index];
		while (lemin->room[index] != NULL &&
				ft_strcmp(lemin->room[index]->name, name) != 0 &&
				lemin->room[index]->next)
			lemin->room[index] = lemin->room[index]->next;
		if (lemin->room[index] && ft_strcmp(lemin->room[index]->name, name) == 0)
		{
			p = lemin->room[index];
			lemin->room[index] = temp;
			return (p);
		}
		else
			lemin->room[index] = temp;
	}
	return (NULL);
}
